namespace Cinema.DataProcessor
{
    using System;
    using System.Collections.Generic;
    using System.Globalization;
    using System.IO;
    using System.Linq;
    using System.Text;
    using System.Xml.Serialization;
    using Cinema.Data.Models;
    using Cinema.Data.Models.Enums;
    using Cinema.DataProcessor.ImportDto;
    using Data;
    using Newtonsoft.Json;

    public class Deserializer
    {
        private const string ErrorMessage = "Invalid data!";

        private const string SuccessfulImportMovie 
            = "Successfully imported {0} with genre {1} and rating {2}!";

        private const string SuccessfulImportProjection 
            = "Successfully imported projection {0} on {1}!";

        private const string SuccessfulImportCustomerTicket 
            = "Successfully imported customer {0} {1} with bought tickets: {2}!";

        public static string ImportMovies(CinemaContext context, string jsonString)
        {
            var moviesDtos = JsonConvert.DeserializeObject<ICollection<MoviesInputModel>>(jsonString);

            StringBuilder sb = new StringBuilder();
            List<Movie> movies = new List<Movie>();

            foreach (var currMovie in moviesDtos)
            {
                if (currMovie.Title == null || currMovie.Genre == null || currMovie.Duration == null || currMovie.Rating == null || currMovie.Director == null)
                {
                    sb.AppendLine("Invalid data!");
                    continue;
                }
                if(currMovie.Rating < 1 || currMovie.Rating > 10)
                {
                    sb.AppendLine("Invalid data!");
                    continue;
                }
                if(currMovie.Title.Length < 3 || currMovie.Title.Length > 20)
                {
                    sb.AppendLine("Invalid data!");
                    continue;
                }
                if (currMovie.Director.Length < 3 || currMovie.Director.Length > 20)
                {
                    sb.AppendLine("Invalid data!");
                    continue;
                }

                var title = movies.FirstOrDefault(m => m.Title == currMovie.Title);

                if (title != null)
                {
                    sb.AppendLine("Invalid data!");
                    continue;
                }

                var rating = $"{currMovie.Rating:f2}";



                var movie = new Movie
                {
                    Title = currMovie.Title,
                    Genre = (Genre)currMovie.Genre,
                    Duration = currMovie.Duration,
                    Rating = currMovie.Rating,
                    Director = currMovie.Director
                };

                movies.Add(movie);
                sb.AppendLine($"Successfully imported {currMovie.Title} with genre {currMovie.Genre} and rating {currMovie.Rating:f2}!");
            }

            context.Movies.AddRange(movies);
            context.SaveChanges();

            return sb.ToString().TrimEnd();
        }

        public static string ImportProjections(CinemaContext context, string xmlString)
        {
            XmlSerializer serializer = new XmlSerializer(typeof(ProjectionsInputModel[]), new XmlRootAttribute("Projections"));
            TextReader reader = new StringReader(xmlString);
            var projectionsDtos = (IEnumerable<ProjectionsInputModel>)serializer.Deserialize(reader);

            StringBuilder sb = new StringBuilder();
            List<Projection> projections = new List<Projection>();


            foreach (var currProjection in projectionsDtos)
            {
                var movie = context.Movies.FirstOrDefault(m => m.Id == currProjection.MovieId);

                if (movie == null)
                {
                    sb.AppendLine(ErrorMessage);
                    continue;
                }

                if (movie.Title == null || movie.Genre == null || movie.Duration == null || movie.Rating == null || movie.Director == null)
                {
                    sb.AppendLine("Invalid data!");
                    continue;
                }
                if (movie.Rating < 1 || movie.Rating > 10)
                {
                    sb.AppendLine("Invalid data!");
                    continue;
                }
                if (movie.Title.Length < 3 || movie.Title.Length > 20)
                {
                    sb.AppendLine("Invalid data!");
                    continue;
                }
                if (movie.Director.Length < 3 || movie.Director.Length > 20)
                {
                    sb.AppendLine("Invalid data!");
                    continue;
                }



                DateTime dateTime;
                bool isDateValid = DateTime.TryParseExact(currProjection.DateTime, "yyyy-MM-dd HH:mm:ss", CultureInfo.InvariantCulture, DateTimeStyles.None, out dateTime);
                if (!isDateValid)
                {
                    sb.AppendLine(ErrorMessage);
                    continue;
                }

                var projection = new Projection
                {
                    MovieId = currProjection.MovieId,
                    DateTime = dateTime
                };

                string dt = dateTime.ToString("MM/dd/yyyy");


                projections.Add(projection);
                sb.AppendLine($"Successfully imported projection {movie.Title} on {dt}!");
            }

            context.Projections.AddRange(projections);
            context.SaveChanges();
            return sb.ToString().TrimEnd();
        }

        public static string ImportCustomerTickets(CinemaContext context, string xmlString)
        {
            XmlSerializer serializer = new XmlSerializer(typeof(CustomersInputModel[]), new XmlRootAttribute("Customers"));
            TextReader reader = new StringReader(xmlString);
            var customersDtos = (IEnumerable<CustomersInputModel>)serializer.Deserialize(reader);

            StringBuilder sb = new StringBuilder();
            List<Customer> customers = new List<Customer>();

            foreach (var currCustomer in customersDtos)
            {
                if (currCustomer.FirstName.Length < 3 || currCustomer.FirstName.Length > 20 || currCustomer.LastName.Length < 3 || currCustomer.LastName.Length > 20 || currCustomer.Age < 12 || currCustomer.Age > 110 || currCustomer.Balance < 0.01m)
                {
                    sb.AppendLine(ErrorMessage);
                    continue;
                }

                var customer = new Customer
                {
                    FirstName = currCustomer.FirstName,
                    LastName = currCustomer.LastName,
                    Age = currCustomer.Age,
                    Balance = currCustomer.Balance
                };

                foreach (var currTicket in currCustomer.Tickets)
                {
                    if (currTicket.Price < 0.01m)
                    {
                        sb.AppendLine(ErrorMessage);
                        continue;
                    }

                    customer.Tickets.Add(new Ticket { ProjectionId = currTicket.ProjectionId, Price = currTicket.Price });
                }

                customers.Add(customer);
                sb.AppendLine($"Successfully imported customer {customer.FirstName} {customer.LastName} with bought tickets: {customer.Tickets.Count}!");
            }

            context.Customers.AddRange(customers);
            context.SaveChanges();
            return sb.ToString().TrimEnd();
        }
    }
}