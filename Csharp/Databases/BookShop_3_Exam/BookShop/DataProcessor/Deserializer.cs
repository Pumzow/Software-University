namespace BookShop.DataProcessor
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.Globalization;
    using System.IO;
    using System.Linq;
    using System.Text;
    using System.Xml.Serialization;
    using BookShop.Data.Models;
    using BookShop.Data.Models.Enums;
    using BookShop.DataProcessor.ImportDto;
    using Data;
    using Newtonsoft.Json;
    using ValidationContext = System.ComponentModel.DataAnnotations.ValidationContext;

    public class Deserializer
    {
        private const string ErrorMessage = "Invalid data!";

        private const string SuccessfullyImportedBook
            = "Successfully imported book {0} for {1:F2}.";

        private const string SuccessfullyImportedAuthor
            = "Successfully imported author - {0} with {1} books.";

        public static string ImportBooks(BookShopContext context, string xmlString)
        {
            XmlSerializer serializer = new XmlSerializer(typeof(BooksInputModel[]), new XmlRootAttribute("Books"));
            TextReader reader = new StringReader(xmlString);
            var booksDtos = (IEnumerable<BooksInputModel>)serializer.Deserialize(reader);

            StringBuilder sb = new StringBuilder();
            List<Book> books = new List<Book>();

            foreach (var currBook in booksDtos)
            {
                if(!IsValid(currBook))
                {
                    sb.AppendLine(ErrorMessage);
                    continue;
                }

                var publishedDate = DateTime.ParseExact(currBook.PublishedOn, "MM/dd/yyyy", CultureInfo.InvariantCulture);

                var book = new Book()
                {
                    Name = currBook.Name,
                    Genre = Enum.Parse<Genre>(currBook.Genre),
                    Price = currBook.Price,
                    Pages = currBook.Pages,
                    PublishedOn = publishedDate
                };

                books.Add(book);
                sb.AppendLine(string.Format(SuccessfullyImportedBook, book.Name, book.Price));
            }

            context.Books.AddRange(books);
            context.SaveChanges();
            return sb.ToString().TrimEnd();
        }

        public static string ImportAuthors(BookShopContext context, string jsonString)
        {
            var authorsDtos = JsonConvert.DeserializeObject<ICollection<AuthorInputModel>>(jsonString);

            StringBuilder sb = new StringBuilder();
            List<Author> authors = new List<Author>();

            foreach (var currAuthor in authorsDtos)
            {
                if (!IsValid(currAuthor))
                {
                    sb.AppendLine(ErrorMessage);
                    continue;
                }

                var email = authors.FirstOrDefault(a => a.Email == currAuthor.Email);

                if (email != null)
                {
                    sb.AppendLine(ErrorMessage);
                    continue;
                }


                var author = new Author()
                {
                    FirstName = currAuthor.FirstName,
                    LastName = currAuthor.LastName,
                    Phone = currAuthor.Phone,
                    Email = currAuthor.Email
                };

                foreach (var currBook in currAuthor.Books)
                {
                    var book = context.Books.Find(currBook.Id);

                    if (book == null)
                    {
                        continue;
                    }

                    author.AuthorsBooks.Add(new AuthorBook
                    {
                        Author = author,
                        Book = book
                    });
                }

                if (!author.AuthorsBooks.Any())
                {
                    sb.AppendLine(ErrorMessage);
                    continue;
                }

                authors.Add(author);
                sb.AppendLine(string.Format(SuccessfullyImportedAuthor, $"{author.FirstName} {author.LastName}", author.AuthorsBooks.Count));
            }

            context.Authors.AddRange(authors);
            context.SaveChanges();

            return sb.ToString().TrimEnd();
        }

        private static bool IsValid(object dto)
        {
            var validationContext = new ValidationContext(dto);
            var validationResult = new List<ValidationResult>();

            return Validator.TryValidateObject(dto, validationContext, validationResult, true);
        }
    }
}