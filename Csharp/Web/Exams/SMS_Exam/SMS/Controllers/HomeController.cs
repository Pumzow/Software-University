namespace SMS.Controllers
{
    using MyWebServer.Controllers;
    using MyWebServer.Http;
    using SMS.Data;
    using SMS.Models.Products;
    using System.Linq;

    public class HomeController : Controller
    {
        private readonly SMSDbContext data;
        public HomeController(SMSDbContext data) => this.data = data;
        public HttpResponse Index()
        {
            if (User.IsAuthenticated)
            {
                return Redirect("/Home/IndexLoggedIn");
            }

            return this.View();
        }
        [Authorize]
        public HttpResponse IndexLoggedIn()
        {
            var user = data.Users.FirstOrDefault(u => u.Id == User.Id);

            var products = data.Products
                .Select(p => new ListingProductsViewModel
                {
                    Username = user.Username,
                    Id = p.Id,
                    Name = p.Name,
                    Price = p.Price
                })
                .ToList();

            return View(products);
        }
    }
}