using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using AutoMapper;
using CarDealer.Data;
using CarDealer.DTO;
using CarDealer.Models;
using Newtonsoft.Json;
using Newtonsoft.Json.Serialization;

namespace CarDealer
{
    public class StartUp
    {
        public static void Main(string[] args)
        {
            var context = new CarDealerContext();
            context.Database.EnsureDeleted();
            context.Database.EnsureCreated();

            var jsonSupplies = File.ReadAllText("../../../Datasets/suppliers.json");
            ImportSuppliers(context, jsonSupplies);
            var jsonParts = File.ReadAllText("../../../Datasets/parts.json");
            ImportParts(context, jsonParts);
            var jsonCars = File.ReadAllText("../../../Datasets/cars.json");
            ImportCars(context, jsonCars);
            var jsonCustomers = File.ReadAllText("../../../Datasets/customers.json");
            ImportCustomers(context, jsonCustomers);
            var jsonSales = File.ReadAllText("../../../Datasets/sales.json");
            ImportSales(context, jsonSales);

            var result = GetSalesWithAppliedDiscount(context);
            Console.WriteLine(result);
        }

        public static string ImportSuppliers(CarDealerContext context, string inputJson)
        {
            var supplierDtos = JsonConvert.DeserializeObject<IEnumerable<ImportSupplierInputModel>>(inputJson);

            var suppliers = supplierDtos.Select(x => new Supplier 
            {
                Name = x.Name,
                IsImporter = x.IsImporter
            })
            .ToList();

            context.Suppliers.AddRange(suppliers);
            context.SaveChanges();

            var result = $"Successfully imported { suppliers.Count}.";
            return result;
        }

        public static string ImportParts(CarDealerContext context, string inputJson)
        {

            var supplieIds = context.Suppliers
                .Select(x => x.Id)
                .ToArray();

            var parts = JsonConvert
                .DeserializeObject<IEnumerable<Part>>(inputJson)
                .Where(s => supplieIds.Contains(s.SupplierId))
                .ToList();

            context.Parts.AddRange(parts);
            context.SaveChanges();

            var result = $"Successfully imported { parts.Count}.";
            return result;
        }
        public static string ImportCars(CarDealerContext context, string inputJson)
        {
            var carDtos = JsonConvert.DeserializeObject<IEnumerable<ImportCarsInputModel>>(inputJson);

            var cars = new List<Car>();

            foreach (var car in carDtos)
            {
                var currentCar = new Car {
                    Make = car.make,
                    Model = car.Model,
                    TravelledDistance = car.travelledDistance
                };

                foreach (var partId in car?.partsId.Distinct())
                {
                    currentCar.PartCars.Add(new PartCar
                    {
                        PartId = partId
                    });
                }

                cars.Add(currentCar);
            }

            context.Cars.AddRange(cars);
            context.SaveChanges();

            var result = $"Successfully imported { cars.Count()}.";
            return result;
        }

        public static string ImportCustomers(CarDealerContext context, string inputJson)
        {
            var customerDtos = JsonConvert.DeserializeObject<IEnumerable<ImportCustomersInputModel>>(inputJson);

            var customers = customerDtos.Select(x => new Customer
            {
                Name = x.name,
                BirthDate = x.birthDate,
                IsYoungDriver = x.isYoungDriver
            })
            .ToList();

            context.Customers.AddRange(customers);
            context.SaveChanges();

            var result = $"Successfully imported { customers.Count}.";
            return result;
        }

        public static string ImportSales(CarDealerContext context, string inputJson)
        {
            var saleDtos = JsonConvert.DeserializeObject<IEnumerable<ImportSalesInputModel>>(inputJson);

            var sales = saleDtos.Select(x => new Sale
            {
                CarId = x.carId,
                CustomerId = x.customerId,
                Discount = x.discount
            })
            .ToList();

            context.Sales.AddRange(sales);
            context.SaveChanges();

            var result = $"Successfully imported { sales.Count}.";
            return result;
        }

        public static string GetOrderedCustomers(CarDealerContext context)
        {

            var customers = context.Customers
                .OrderBy(x => x.BirthDate)
                .ThenBy(c => c.IsYoungDriver)
                .Select(s => new
                {
                    Name = s.Name,
                    BirthDate = s.BirthDate.ToString("dd/MM/yyyy"),
                    IsYoungDriver = s.IsYoungDriver
                })
                .ToList();

            var result = JsonConvert.SerializeObject(customers);
            return result;
        }

        public static string GetCarsFromMakeToyota(CarDealerContext context)
        {
            var cars = context.Cars
                .Where(c => c.Make == "Toyota")
                .Select(c => new
                {
                    Id = c.Id,
                    Make = c.Make,
                    Model = c.Model,
                    TravelledDistance = c.TravelledDistance
                })
                .OrderBy(c => c.Model)
                .ThenByDescending(c => c.TravelledDistance)
                .ToList();

            var result = JsonConvert.SerializeObject(cars);
            return result;
        }

        public static string GetLocalSuppliers(CarDealerContext context)
        {
            var suppliers = context.Suppliers
                    .Where(s => s.IsImporter == false)
                    .Select(s => new { Id = s.Id, Name = s.Name, PartsCount = s.Parts.Count })
                    .ToList();

            var settings = new JsonSerializerSettings
            {
                Formatting = Formatting.Indented
            };

            var result = JsonConvert.SerializeObject(suppliers, settings);
            return result;
        }

        public static string GetCarsWithTheirListOfParts(CarDealerContext context)
        {
            var cars = context.Cars
                    .Select(c => new { 
                        car = new
                        {
                            Make = c.Make,
                            Model = c.Model,
                            TravelledDistance = c.TravelledDistance
                        },
                        parts = c.PartCars
                            .Select(p => new
                            { 
                                Name = p.Part.Name,
                                Price = p.Part.Price.ToString("F2")
                            })
                    })
                    .ToList();

            var settings = new JsonSerializerSettings
            {
                Formatting = Formatting.Indented
            };

            var result = JsonConvert.SerializeObject(cars, settings);
            return result;
        }

        public static string GetTotalSalesByCustomer(CarDealerContext context)
        {
            var customers = context.Customers
                    .Where(c => c.Sales.Count >= 1)
                    .Select(s => new
                    {
                        FullName = s.Name,
                        BoughtCars = s.Sales.Count,
                        SpentMoney = s.Sales.Sum(c => c.Car.PartCars.Sum(p => p.Part.Price))
                    })
                    .OrderByDescending(o => o.SpentMoney)
                    .ThenByDescending(o => o.BoughtCars)
                    .ToList();

            var settings = new JsonSerializerSettings
            {
                Formatting = Formatting.Indented,
                ContractResolver = new CamelCasePropertyNamesContractResolver()
            };

            var result = JsonConvert.SerializeObject(customers, settings);

            return result;
        }

        public static string GetSalesWithAppliedDiscount(CarDealerContext context)
        {
            var sales = context.Sales
                    .Take(10)
                    .Select(s => new
                    {
                        car = new { 
                            Make = s.Car.Make,
                            Model = s.Car.Model,
                            TravelledDistance = s.Car.TravelledDistance
                        },
                        customerName = s.Customer.Name,
                        Discount = s.Discount.ToString("F2"),
                        price = s.Car.PartCars.Sum(p => p.Part.Price).ToString("F2"),
                        priceWithDiscount = (s.Car.PartCars.Sum(p => p.Part.Price) - (s.Car.PartCars.Sum(p => p.Part.Price) * (s.Discount * 0.01M))).ToString("F2")
                    })
                    .ToList();

            var settings = new JsonSerializerSettings
            {
                Formatting = Formatting.Indented
            };

            var result = JsonConvert.SerializeObject(sales, settings);
            return result;
        }
    }
}