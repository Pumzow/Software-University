namespace VaporStore.DataProcessor
{
	using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.Globalization;
    using System.IO;
    using System.Linq;
    using System.Text;
    using System.Xml.Serialization;
    using Data;
    using Newtonsoft.Json;
    using VaporStore.Data.Models;
    using VaporStore.Data.Models.Enums;
    using VaporStore.DataProcessor.Dto.Import;

    public static class Deserializer
	{
		public static string ImportGames(VaporStoreDbContext context, string jsonString)
		{
			var gamesDtos = JsonConvert.DeserializeObject<ICollection<GamesInputModel>>(jsonString);

			StringBuilder sb = new StringBuilder();
			List<Game> games = new List<Game>();

			var genres = new List<Genre>();
			var developers = new List<Developer>();
			var tags = new List<Tag>();

			foreach (var currGame in gamesDtos)
            {
				if (!IsValid(currGame) || !currGame.Tags.Any() || currGame.Price < 0)
				{
					sb.AppendLine("Invalid Data");
					continue;
				}

				

				var genre = genres.FirstOrDefault(x => x.Name == currGame.Genre)
					?? new Genre { Name = currGame.Genre };
				genres.Add(genre);
				var developer = developers.FirstOrDefault(x => x.Name == currGame.Developer)
					?? new Developer { Name = currGame.Developer };
				developers.Add(developer);

				var game = new Game
				{
					Name = currGame.Name,
					Price = currGame.Price,
					Genre = genre,
					Developer = developer,
					ReleaseDate = currGame.ReleaseDate.Value,
				};


                foreach (var currTag in currGame.Tags)
                {
					var tag = tags.FirstOrDefault(x => x.Name == currTag)
						?? new Tag { Name = currTag };
					tags.Add(tag);

					game.GameTags.Add(new GameTag { Tag = tag });
				}
				games.Add(game);
				sb.AppendLine($"Added {currGame.Name} ({currGame.Genre}) with {currGame.Tags.Count()} tags");
			}

			context.Games.AddRange(games);
			context.SaveChanges();

			return sb.ToString().TrimEnd();
		}

		public static string ImportUsers(VaporStoreDbContext context, string jsonString)
		{
			var usersDtos = JsonConvert.DeserializeObject<ICollection<UsersInputModel>>(jsonString);

			StringBuilder sb = new StringBuilder();
			List<User> users = new List<User>();

			foreach (var currUser in usersDtos)
			{
				if (!IsValid(currUser) || !currUser.Cards.Any())
				{
					sb.AppendLine("Invalid Data");
					continue;
				}

                foreach (var currCards in currUser.Cards)
                {

                }

				var user = new User
				{
					FullName = currUser.FullName,
					Username = currUser.Username,
					Email = currUser.Email,
					Age = currUser.Age,
					Cards = currUser.Cards.Select(x => new Card
					{
						Number = x.Number,
						Cvc = x.CVC,
						Type = x.Type.Value
					}).ToList()
				};

				users.Add(user);
				sb.AppendLine($"Imported {currUser.Username} with {currUser.Cards.Count} cards");
			}

			context.Users.AddRange(users);
			context.SaveChanges();

			return sb.ToString().TrimEnd();
		}

		public static string ImportPurchases(VaporStoreDbContext context, string xmlString)
		{
			XmlSerializer serializer = new XmlSerializer(typeof(PurchasesInputModel[]), new XmlRootAttribute("Purchases"));
			TextReader reader = new StringReader(xmlString);
			var purchasesDtos = (IEnumerable<PurchasesInputModel>)serializer.Deserialize(reader);

			StringBuilder sb = new StringBuilder();
			List<Purchase> purchases = new List<Purchase>();

			foreach (var currPurchase in purchasesDtos)
			{
				if (!IsValid(currPurchase))
				{
					sb.AppendLine("Invalid Data");
					continue;
				}

				var parsedDate = DateTime.TryParseExact(currPurchase.Date, "dd/MM/yyyy HH:mm", CultureInfo.InvariantCulture, DateTimeStyles.None, out var date);

				if (!parsedDate)
				{
					sb.AppendLine("Invalid Data");
					continue;
				}

				var purchase = new Purchase
				{
					Type = currPurchase.Type.Value,
					ProductKey = currPurchase.Key,
					Date = date
				};

				purchase.Card = context.Cards.FirstOrDefault(x => x.Number == currPurchase.Card);
				purchase.Game = context.Games.FirstOrDefault(x => x.Name == currPurchase.Title); // title Attribute
				var username = context.Users.Where(x => x.Id == purchase.Card.UserId).Select(x => x.Username).FirstOrDefault(); // get the username for the output
				purchases.Add(purchase);
				sb.AppendLine($"Imported {currPurchase.Title} for {username}");
            }

			context.Purchases.AddRange(purchases);
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