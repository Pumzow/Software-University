using CarDealer.Data;
using CarDealer.DataTransferObjects.Input;
using CarDealer.DataTransferObjects.Output;
using CarDealer.Models;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Xml.Serialization;

namespace CarDealer
{
    public class StartUp
    {
        public static void Main(string[] args)
        {
            var context = new CarDealerContext();
            context.Database.EnsureDeleted();
            context.Database.EnsureCreated();

            var supplierXml = File.ReadAllText("../../../Datasets/suppliers.xml");
            ImportSuppliers(context, supplierXml);

            var partsXml = File.ReadAllText("../../../Datasets/parts.xml");
            ImportParts(context, partsXml);

            var carsXml = File.ReadAllText("../../../Datasets/cars.xml");
            ImportCars(context, carsXml);

            var customersXml = File.ReadAllText("../../../Datasets/customers.xml");
            ImportCustomers(context, customersXml);

            var salesXml = File.ReadAllText("../../../Datasets/sales.xml");
            ImportSales(context, salesXml);

            //var result = GetCarsWithDistance(context);
            //var result = GetCarsFromMakeBmw(context);
            //var result = GetLocalSuppliers(context);
            //var result = GetCarsWithTheirListOfParts(context);
            //var result = GetTotalSalesByCustomer(context);
            var result = GetSalesWithAppliedDiscount(context);
            Console.WriteLine(result);
        }
        public static string ImportSuppliers(CarDealerContext context, string inputXml)
        {
            XmlSerializer xmlSerializer = new XmlSerializer(typeof(SupplierInputModel[]), new XmlRootAttribute("Suppliers"));
            var textRead = new StringReader(inputXml);

            var suppliersDto = xmlSerializer.Deserialize(textRead) as SupplierInputModel[];

            var suppliers = suppliersDto.Select(x => new Supplier
            {
                Name = x.Name,
                IsImporter = x.IsImporter
            })
            .ToList();

            context.Suppliers.AddRange(suppliers);
            context.SaveChanges();

            var result = $"Successfully imported {suppliers.Count}";
            return result;
        }
        public static string ImportParts(CarDealerContext context, string inputXml)
        {
            XmlSerializer xmlSerializer = new XmlSerializer(typeof(PartInputModel[]), new XmlRootAttribute("Parts"));
            var textRead = new StringReader(inputXml);

            var partsDto = xmlSerializer.Deserialize(textRead) as PartInputModel[];

            var supplierIds = context.Suppliers
                .Select(x => x.Id)
                .ToList();

            var parts = partsDto
                .Where(s => supplierIds.Contains(s.SupplierId))
            .Select(x => new Part
            {
                Name = x.Name,
                Price = x.Price,
                Quantity = x.Quantity,
                SupplierId = x.SupplierId
            })
            .ToList();

            context.Parts.AddRange(parts);
            context.SaveChanges();

            var result = $"Successfully imported {parts.Count}";
            return result;
        }
        public static string ImportCars(CarDealerContext context, string inputXml)
        {

            XmlSerializer xmlSerializer = new XmlSerializer(typeof(CarInputModel[]), new XmlRootAttribute("Cars"));
            var textRead = new StringReader(inputXml);

            var carsDto = xmlSerializer.Deserialize(textRead) as CarInputModel[];

            var allParts = context.Parts.Select(x => x.Id).ToList();

            var cars = carsDto
                .Select(x => new Car
                {
                    Make = x.Make,
                    Model = x.Model,
                    TravelledDistance = x.TraveledDistance,
                    PartCars = x.CarPartsInputModel.Select(x => x.Id)
                    .Distinct()
                    .Intersect(allParts)
                    .Select(pc => new PartCar
                    {
                        PartId = pc
                    })
                    .ToList()
                })
                .ToList();

            context.Cars.AddRange(cars);
            context.SaveChanges();

            var result = $"Successfully imported {cars.Count}";
            return result;

        }
        public static string ImportCustomers(CarDealerContext context, string inputXml)
        {
            XmlSerializer xmlSerializer = new XmlSerializer(typeof(CustomerInputModel[]), new XmlRootAttribute("Customers"));
            var textRead = new StringReader(inputXml);

            var customersDto = xmlSerializer.Deserialize(textRead) as CustomerInputModel[];

            var customers = customersDto.Select(x => new Customer
            {
                Name = x.Name,
                BirthDate = x.BirthDate,
                IsYoungDriver = x.IsYoungDriver
            })
            .ToList();

            context.Customers.AddRange(customers);
            context.SaveChanges();

            var result = $"Successfully imported {customers.Count}";
            return result;
        }
        public static string ImportSales(CarDealerContext context, string inputXml)
        {
            XmlSerializer xmlSerializer = new XmlSerializer(typeof(SaleInputModel[]), new XmlRootAttribute("Sales"));
            var textRead = new StringReader(inputXml);

            var salesDto = xmlSerializer.Deserialize(textRead) as SaleInputModel[];

            var carIds = context.Cars
                .Select(x => x.Id)
                .ToList();

            var sales = salesDto
                .Where(x => carIds.Contains(x.CarId))
                .Select(x => new Sale
                {
                    CarId = x.CarId,
                    CustomerId = x.CustomerId,
                    Discount = x.Discount
                })
            .ToList();

            context.Sales.AddRange(sales);
            context.SaveChanges();

            var result = $"Successfully imported {sales.Count}";
            return result;
        }

        public static string GetCarsWithDistance(CarDealerContext context)
        {
            var cars = context.Cars
                .Where(c => c.TravelledDistance > 2_000_000)
                .Select(c => new CarOutputModel
                {
                    Make = c.Make,
                    Model = c.Model,
                    TraveledDistance = c.TravelledDistance
                })
                .OrderBy(c => c.Make)
                .ThenBy(c => c.Model)
                .Take(10)
                .ToArray();

            XmlSerializer xmlSerializer = new XmlSerializer(typeof(CarOutputModel[]), new XmlRootAttribute("cars"));
            var textWriter = new StringWriter();

            var namespaceSettings = new XmlSerializerNamespaces();
            namespaceSettings.Add("", "");

            xmlSerializer.Serialize(textWriter, cars, namespaceSettings);

            var result = textWriter.ToString();

            return result;
        }

        public static string GetCarsFromMakeBmw(CarDealerContext context)
        {
            var cars = context.Cars
                .Where(c => c.Make == "BMW")
                .Select(c => new CarFromBMWOutputModel
                {
                    Id = c.Id,
                    Model = c.Model,
                    TravelledDistance = c.TravelledDistance
                })
                .OrderBy(c => c.Model)
                .ThenByDescending(c => c.TravelledDistance)
                .ToArray();

            XmlSerializer xmlSerializer = new XmlSerializer(typeof(CarFromBMWOutputModel[]), new XmlRootAttribute("cars"));
            var textWriter = new StringWriter();

            var namespaceSettings = new XmlSerializerNamespaces();
            namespaceSettings.Add("", "");

            xmlSerializer.Serialize(textWriter, cars, namespaceSettings);

            var result = textWriter.ToString();

            return result;
        }

        public static string GetLocalSuppliers(CarDealerContext context)
        {

            var suppliers = context.Suppliers
                .Where(x => x.IsImporter == false)
                .Select(c => new SupplierOutputModel
                {
                    Id = c.Id,
                    Name = c.Name,
                    Parts = c.Parts.Count
                })
                .ToArray();

            XmlSerializer xmlSerializer = new XmlSerializer(typeof(SupplierOutputModel[]), new XmlRootAttribute("suppliers"));
            var textWriter = new StringWriter();

            var namespaceSettings = new XmlSerializerNamespaces();
            namespaceSettings.Add("", "");

            xmlSerializer.Serialize(textWriter, suppliers, namespaceSettings);

            var result = textWriter.ToString();

            return result;
        }

        public static string GetCarsWithTheirListOfParts(CarDealerContext context)
        {

            var sb = new StringBuilder();

            var cars = context.Cars.OrderByDescending(c => c.TravelledDistance)
                              .ThenBy(c => c.Model)
                              .Take(5)
                              .Select(c => new CarsWithListOfPartsOutputModel
                              {
                                  Make = c.Make,
                                  Model = c.Model,
                                  TravelledDistance = c.TravelledDistance,
                                  Parts = c.PartCars.Select(pc => new PartsFromCarOutputModel
                                  {
                                      Name = pc.Part.Name,
                                      Price = pc.Part.Price
                                  })
                                  .OrderByDescending(x => x.Price)
                                  .ToArray()
                              })
                              .ToArray();

            //foreach (var car in cars)
            //{
            //    car.Parts = car.Parts.OrderByDescending(p => p.Price).ToArray();
            //}

            XmlSerializer xmlSerializer = new XmlSerializer(typeof(CarsWithListOfPartsOutputModel[]), new XmlRootAttribute("cars"));
            var textWriter = new StringWriter();

            var namespaceSettings = new XmlSerializerNamespaces();
            namespaceSettings.Add("", "");

            xmlSerializer.Serialize(textWriter, cars, namespaceSettings);

            var result = textWriter.ToString();

            return result;

        }

        public static string GetTotalSalesByCustomer(CarDealerContext context)
        {

            var customers = context.Customers
                .ToList()
                .Where(c => c.Sales.Count > 0)
                .Select(c => new ExportCustomerByTotalSalesDto
                {
                    FullName = c.Name,
                    BoughtCars = c.Sales.Count,
                    SpentMoney = c.Sales.Sum(ca => ca.Car.PartCars.Sum(p => p.Part.Price))
                })
                .OrderByDescending(x => x.SpentMoney)
                .ToArray();

            XmlSerializer xmlSerializer = new XmlSerializer(typeof(ExportCustomerByTotalSalesDto[]), new XmlRootAttribute("customers"));
            var textWriter = new StringWriter();

            var namespaceSettings = new XmlSerializerNamespaces();
            namespaceSettings.Add("", "");

            xmlSerializer.Serialize(textWriter, customers, namespaceSettings);

            var result = textWriter.ToString();

            return result;
        }

        public static string GetSalesWithAppliedDiscount(CarDealerContext context)
        {
            var sales = context.Sales
                .Select(c => new SalesOutputModel
                {
                    Car = new CarSalesDiscountDTO
                    {
                        Make = c.Car.Make,
                        Model = c.Car.Model,
                        TravelledDistance = c.Car.TravelledDistance
                    },
                    CustomerName = c.Customer.Name,
                    Discount = c.Discount,
                    Price = c.Car.PartCars.Sum(p => p.Part.Price).ToString("f2"),
                    DescountedPrice = (c.Car.PartCars.Sum(p => p.Part.Price) -
                        c.Car.PartCars.Sum(p => p.Part.Price) * c.Discount / 100).ToString("f2")
                })
                .ToList();

            XmlSerializer xmlSerializer = new XmlSerializer(typeof(SalesOutputModel[]), new XmlRootAttribute("customers"));
            var textWriter = new StringWriter();

            var namespaceSettings = new XmlSerializerNamespaces();
            namespaceSettings.Add("", "");

            xmlSerializer.Serialize(textWriter, sales, namespaceSettings);

            var result = textWriter.ToString().Trim();

            return result;
        }
    }
}