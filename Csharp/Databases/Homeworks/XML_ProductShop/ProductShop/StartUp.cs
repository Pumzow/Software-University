using Microsoft.EntityFrameworkCore;
using ProductShop.Data;
using ProductShop.Dtos.Export;
using ProductShop.Dtos.Import;
using ProductShop.Models;
using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Xml.Serialization;

namespace ProductShop
{
    public class StartUp
    {
        public static void Main(string[] args)
        {
            var context = new ProductShopContext();
            context.Database.EnsureDeleted();
            context.Database.EnsureCreated();


            var usersXml = File.ReadAllText("../../../Datasets/users.xml");
            ImportUsers(context, usersXml);

            var productsXml = File.ReadAllText("../../../Datasets/products.xml");
            ImportProducts(context, productsXml);

            var categoriesXml = File.ReadAllText("../../../Datasets/categories.xml");
            ImportCategories(context, categoriesXml);

            var categoryProductsXml = File.ReadAllText("../../../Datasets/categories-products.xml");
            ImportCategoryProducts(context, categoryProductsXml);

            //var result = GetProductsInRange(context);
            //var result = GetSoldProducts(context);
            //var result = GetCategoriesByProductsCount(context);
            var result = GetUsersWithProducts(context);
            Console.WriteLine(result);
        }

        public static string ImportUsers(ProductShopContext context, string inputXml)
        {
            XmlSerializer xmlSerializer = new XmlSerializer(typeof(UserImportDto[]), new XmlRootAttribute("Users"));
            var textRead = new StringReader(inputXml);

            var suppliersDto = xmlSerializer.Deserialize(textRead) as UserImportDto[];

            var users = suppliersDto.Select(x => new User
            {
                FirstName = x.FirstName,
                LastName = x.LastName,
                Age = x.Age
            })
            .ToList();

            context.Users.AddRange(users);
            context.SaveChanges();

            var result = $"Successfully imported {users.Count}";
            return result;
        }

        public static string ImportProducts(ProductShopContext context, string inputXml)
        {
            XmlSerializer xmlSerializer = new XmlSerializer(typeof(ProductImportDto[]), new XmlRootAttribute("Products"));
            var textRead = new StringReader(inputXml);

            var suppliersDto = xmlSerializer.Deserialize(textRead) as ProductImportDto[];

            var users = context.Users
                .Select(x => x.Id)
                .ToList();

            var products = suppliersDto
                .Select(x => new Product
            {
                Name = x.Name,
                Price = x.Price,
                SellerId = x.SellerId,
                BuyerId = x.BuyerId
            })
            .ToList();

            context.Products.AddRange(products);
            context.SaveChanges();

            var result = $"Successfully imported {products.Count}";
            return result;
        }

        public static string ImportCategories(ProductShopContext context, string inputXml)
        {


            XmlSerializer xmlSerializer = new XmlSerializer(typeof(CategoryImportDto[]), new XmlRootAttribute("Categories"));
            var textRead = new StringReader(inputXml);

            var suppliersDto = xmlSerializer.Deserialize(textRead) as CategoryImportDto[];

            var users = context.Users
                .Select(x => x.Id)
                .ToList();

            var categories = suppliersDto
                .Where(x => x.Name != null)
                .Select(x => new Category
                {
                    Name = x.Name
                })
            .ToList();

            context.Categories.AddRange(categories);
            context.SaveChanges();

            var result = $"Successfully imported {categories.Count}";
            return result;
        }

        public static string ImportCategoryProducts(ProductShopContext context, string inputXml)
        {


            XmlSerializer xmlSerializer = new XmlSerializer(typeof(CategoryProductsImportDto[]), new XmlRootAttribute("CategoryProducts"));
            var textRead = new StringReader(inputXml);

            var suppliersDto = xmlSerializer.Deserialize(textRead) as CategoryProductsImportDto[];

            var categories = context.Categories
                .Select(x => x.Id)
                .ToList();
            var products = context.Products
                .Select(x => x.Id)
                .ToList();

            var categoriesProducts = suppliersDto
                .Where(x => x.CategoryId != null && x.ProductId != null)
                .Select(x => new CategoryProduct
                {
                    CategoryId = x.CategoryId,
                    ProductId = x.ProductId
                })
            .ToList();

            context.CategoryProducts.AddRange(categoriesProducts);
            context.SaveChanges();

            var result = $"Successfully imported {categoriesProducts.Count}";
            return result;
        }

        public static string GetProductsInRange(ProductShopContext context)
        {
            var products = context.Products
                .Where(c => c.Price >= 500 && c.Price <= 1000)
                .Include(p => p.Buyer)
                .Select(x => new ProductExportDto
                {
                    Name = x.Name,
                    Price = x.Price,
                    Buyer = $"{x.Buyer.FirstName} {x.Buyer.LastName}"
                })
                .OrderBy(c => c.Price)
                .Take(10)
                .ToArray();

            XmlSerializer xmlSerializer = new XmlSerializer(typeof(ProductExportDto[]), new XmlRootAttribute("Products"));
            var textWriter = new StringWriter();

            var namespaceSettings = new XmlSerializerNamespaces();
            namespaceSettings.Add("", "");

            xmlSerializer.Serialize(textWriter, products, namespaceSettings);

            var result = textWriter.ToString();

            return result;
        }
        public static string GetSoldProducts(ProductShopContext context)
        {
            var soldProducts = context.Users
                .Where(c => c.ProductsSold.Count > 0)
                .Select(x => new UserSoldsExportDto
                {
                    FirstName = x.FirstName,
                    LastName = x.LastName,
                    SoldProducts = x.ProductsSold.Select(p => new SoldProductsExportDto
                    { 
                        Name = p.Name,
                        Price = p.Price
                    })
                    .ToArray()
                })
                .OrderBy(c => c.LastName)
                .ThenBy(c => c.FirstName)
                .Take(5)
                .ToArray();

            XmlSerializer xmlSerializer = new XmlSerializer(typeof(UserSoldsExportDto[]), new XmlRootAttribute("Users"));
            var textWriter = new StringWriter();

            var namespaceSettings = new XmlSerializerNamespaces();
            namespaceSettings.Add("", "");

            xmlSerializer.Serialize(textWriter, soldProducts, namespaceSettings);

            var result = textWriter.ToString();

            return result;
        }
        public static string GetCategoriesByProductsCount(ProductShopContext context)
        {
            var categories = context
                  .Categories
                  .Select(x => new CategoryByCountExportDto
                  {
                      Name = x.Name,
                      Count = x.CategoryProducts.Count,
                      AveragePrice = x.CategoryProducts.Select(a => a.Product.Price).Average(),
                      TotalRevenue = x.CategoryProducts.Select(а => а.Product.Price).Sum()
                  })
                  .OrderByDescending(x => x.Count)
                  .ThenBy(x => x.TotalRevenue)
                  .ToArray();

            XmlSerializer xmlSerializer = new XmlSerializer(typeof(CategoryByCountExportDto[]), new XmlRootAttribute("Categories"));
            var textWriter = new StringWriter();

            var namespaceSettings = new XmlSerializerNamespaces();
            namespaceSettings.Add("", "");

            xmlSerializer.Serialize(textWriter, categories, namespaceSettings);

            var result = textWriter.ToString();

            return result;
        }

        public static string GetUsersWithProducts(ProductShopContext context)
        {

            var users = new ExportUsersWithCountAndProductsDto
            {
                Count = context.Users.Count(x => x.ProductsSold.Any()),
                Users = context.Users.Where(x => x.ProductsSold.Count() > 0)
                               .Select(u => new ExportUserWithProductsDto
                               {
                                   Firstname = u.FirstName,
                                   Lastname = u.LastName,
                                   Age = u.Age,
                                   SoldProducts = new ExportSoldProductDto
                                   {
                                       Count = u.ProductsSold.Count,
                                       SoldProducts = u.ProductsSold.Select(s =>
                                       new ExportProductMiniDto
                                       {
                                           Name = s.Name,
                                           Price = s.Price
                                       })
                                       .OrderByDescending(y => y.Price)
                                       .ToArray()
                                   }
                               })
                               .OrderByDescending(v => v.SoldProducts.Count)
                               .ToArray()
            };

            XmlSerializer xmlSerializer = new XmlSerializer(typeof(ExportUsersWithCountAndProductsDto), new XmlRootAttribute("Users"));
            var textWriter = new StringWriter();

            var namespaceSettings = new XmlSerializerNamespaces();
            namespaceSettings.Add("", "");

            xmlSerializer.Serialize(textWriter, users, namespaceSettings);

            var result = textWriter.ToString();

            return result;
        }

    }
}