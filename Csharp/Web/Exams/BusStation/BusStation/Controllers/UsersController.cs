namespace BusStation.Controllers
{
    using MyWebServer.Http;
    using MyWebServer.Controllers;
    using BusStation.Data;
    using BusStation.Models.Users;
    using BusStation.Services;
    using System.Linq;
    using BusStation.Data.Models;

    public class UsersController : Controller
    {
        private readonly BusStationDbContext data;
        private readonly Validator validator;
        private readonly PasswordHasher passwordHasher;
        public UsersController(BusStationDbContext data, Validator validator, PasswordHasher passwordHasher)
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
                return View();
            }

            var user = new User
            {
                Username = model.Username,
                Password = this.passwordHasher.HashPassword(model.Password),
                Email = model.Email
            };

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
                return View();
            }

            this.SignIn(userId);

            return Redirect("/Destinations/All");
        }

        [Authorize]
        public HttpResponse Logout()
        {
            SignOut();

            return Redirect("/");
        }

    }
}
