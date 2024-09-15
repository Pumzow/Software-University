using Microsoft.EntityFrameworkCore.Metadata.Internal;
using MyWebServer.Controllers;
using MyWebServer.Http;
using SMS.Data;
using SMS.Models.Cart;
using System.Linq;

namespace SMS.Controllers
{
    public class CartsController : Controller
    {
        private readonly SMSDbContext data;
        public CartsController(SMSDbContext data) => this.data = data;

        [Authorize]
        public HttpResponse Details()
        {
            var user = data.Users.FirstOrDefault(u => u.Id == User.Id);

            var cart = data.Carts.FirstOrDefault(u => u.Id == user.CartId);

            var products = data.Products
                .Where(p => p.CartId == cart.Id)
                .Select(p => new ListingCartViewModel
                {
                    Id = p.Id,
                    Name = p.Name,
                    Price = p.Price
                })
                .ToList();

            return View(products);
        }
        [Authorize]
        public HttpResponse AddProduct(string ProductId)
        {
            var user = data.Users.FirstOrDefault(u => u.Id == User.Id);

            var cart = data.Carts.FirstOrDefault(c => c.Id == user.CartId);

            var product = data.Products.FirstOrDefault(p => p.Id == ProductId);

            cart.Products.Add(product);
            if (product.CartId != null)
            {
                return Error("The product has been already taken.");
            }

            product.CartId = cart.Id;
            product.Cart = cart;

            data.SaveChanges();

            return Redirect("/Carts/Details");
        }
        [Authorize]
        public HttpResponse Buy()
        {
            var user = data.Users.FirstOrDefault(u => u.Id == User.Id);

            var cart = data.Carts.FirstOrDefault(c => c.Id == user.CartId);

            var products = data.Products
                .Where(p => p.CartId == cart.Id)
                .Select(p => p)
                .ToList();

            foreach (var product in products)
            {
                product.CartId = null;
                product.Cart = null;
            }

            cart.Products.Clear();

            data.SaveChanges();

            return Redirect("/");
        }
    }
}
