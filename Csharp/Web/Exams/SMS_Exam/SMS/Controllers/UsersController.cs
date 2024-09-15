using MyWebServer.Controllers;
using MyWebServer.Http;
using SMS.Services;
using SMS.Data;
using SMS.Models.Users;
using System.Linq;
using SMS.Data.Models;

namespace SMS.Controllers
{
    public class UsersController : Controller
    {
        private readonly SMSDbContext data;
        private readonly Validator validator;
        private readonly PasswordHasher passwordHasher;

        public UsersController(SMSDbContext data, PasswordHasher passwordHasher, Validator validator)
        {
            this.data = data;
            this.passwordHasher = passwordHasher;
            this.validator = validator;
        }

        public HttpResponse Register() => View();

        [HttpPost]
        public HttpResponse Register(RegisterUserFormModel model)
        {
            var modelErrors = this.validator.ValidateUser(model);
            if (this.data.Users.Any(u => u.Username == model.Username))
            {
                modelErrors.Add($"User with '{model.Username}' username already exists.");
            }

            if (this.data.Users.Any(u => u.Email == model.Email))
            {
                modelErrors.Add($"User with '{model.Email}' e-mail already exists.");
            }
            if (modelErrors.Any())
            {
                return Error(modelErrors);
            }

            var user = new User
            {
                Username = model.Username,
                Password = this.passwordHasher.HashPassword(model.Password),
                Email = model.Email
            };

            var cart = new Cart
            {
                User = user,
            };
            user.Cart = cart;
            user.CartId = cart.Id;

            data.Carts.Add(cart);
            data.Users.Add(user);

            data.SaveChanges();

            return Redirect("/Users/Login");
        }
        public HttpResponse Login() => View();
        [HttpPost]
        public HttpResponse Login(LoginUserFormModel model)
        {

            var hashedPassword = this.passwordHasher.HashPassword(model.Password);

            var userId = this.data
                .Users
                .Where(u => u.Username == model.Username && u.Password == hashedPassword)
                .Select(u => u.Id)
                .FirstOrDefault();

            if (userId == null)
            {
                return Error("Username and password combination is not valid.");
            }

            this.SignIn(userId);

            return Redirect("/");
        }

        [Authorize]
        public HttpResponse Logout()
        {
            SignOut();

            return Redirect("/");
        }
    }
}
