using MyWebServer.Controllers;
using MyWebServer.Http;
using SMS.Data;
using SMS.Data.Models;
using SMS.Models.Products;
using SMS.Services;

namespace SMS.Controllers
{
    public class ProductsController : Controller
    {
        private readonly SMSDbContext data;
        private readonly IValidator validator;
        public ProductsController(SMSDbContext data, IValidator validator)
        {
            this.data = data;
            this.validator = validator;
        }
        [Authorize]
        public HttpResponse Create() => this.View();

        [Authorize]
        [HttpPost]
        public HttpResponse Create(CreateProductFormModel model)
        {
            var product = new Product
            {
                Name = model.Name,
                Price = decimal.Parse(model.Price)
            };

            data.Products.Add(product);
            data.SaveChanges();

            return Redirect("/");
        }

        public HttpResponse Add() => View();
    }
}
