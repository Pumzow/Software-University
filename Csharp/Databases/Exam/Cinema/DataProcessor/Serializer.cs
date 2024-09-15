namespace Cinema.DataProcessor
{
    using System;
    using System.Globalization;
    using System.IO;
    using System.Linq;
    using System.Text;
    using System.Xml.Serialization;
    using Cinema.DataProcessor.ExportDto;
    using Data;
    using Microsoft.EntityFrameworkCore;
    using Newtonsoft.Json;

    public class Serializer
    {
        public static string ExportTopMovies(CinemaContext context, int rating)
        {
            return "To-Do";

            /*var movies = context.Movies
                .ToArray()
                .Where(m => m.Rating >= rating && m.Projections.Any(p => p.Tickets.Count > 0)) // If I need to compare something with input data (try addiding it again somewhere) { 1 }  
                .Select(m => new
                {
                    MovieName = m.Title,
                    Rating = m.Rating.ToString("f2"),
                    Customers = m.Projections.Select(p => p.Movie.)
                })
                .OrderByDescending(e => e.Tasks.Length)
                .ThenBy(e => e.Username)
                .Take(10)
                .ToArray();


            return JsonConvert.SerializeObject(movies, Formatting.Indented);*/
        }

        public static string ExportTopCustomers(CinemaContext context, int age)
        {
            StringBuilder sb = new StringBuilder();

            XmlSerializer xmlSerializer = new XmlSerializer(typeof(CustomersOutputModel[]), new XmlRootAttribute("Customers"));
            XmlSerializerNamespaces namespaces = new XmlSerializerNamespaces();
            namespaces.Add(string.Empty, string.Empty);

            using StringWriter stringWriter = new StringWriter(sb);


            var customers = context.Customers
                .Where(c => c.Age >= age)
                .ToArray()
                .Select(c => new CustomersOutputModel
                {
                    FirstName = c.FirstName,
                    LastName = c.LastName,
                    SpentMoney = c.Tickets.Sum(t => t.Price),
                    SpentTime = 
                })
                .OrderByDescending(c => c.SpentMoney)
                .Take(10)
                .ToArray();

            xmlSerializer.Serialize(stringWriter, customers, namespaces);

            return sb.ToString().TrimEnd();
        }
    }
}