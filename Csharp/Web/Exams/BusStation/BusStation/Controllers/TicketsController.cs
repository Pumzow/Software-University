namespace BusStation.Controllers
{
    using MyWebServer.Http;
    using MyWebServer.Controllers;
    using BusStation.Data;
    using System.Linq;
    using BusStation.Data.Models;
    using BusStation.Models.Tickets;
    using System.Collections.Generic;

    public class TicketsController : Controller
    {
        private readonly BusStationDbContext data;
        public TicketsController(BusStationDbContext data) => this.data = data;


        [Authorize]
        public HttpResponse Create() => this.View();

        [Authorize]
        [HttpPost]
        public HttpResponse Create(AddTicketFormModel model, string DestinationId)
        {
            var destination = data.Destinations.FirstOrDefault(d => d.Id == DestinationId);
            var user = data.Users.FirstOrDefault(u => u.Id == User.Id);

            if (decimal.Parse(model.Price) < 10 || decimal.Parse(model.Price) > 90)
            {
                return View();
            }

            if (model.TicketsCount > 10)
            {
                return View();
            }

            for (int i = 0; i < model.TicketsCount; i++)
            {
                var ticket = new Ticket
                {
                    Price = decimal.Parse(model.Price),
                    UserId = User.Id,
                    DestinationId = DestinationId,
                };

                data.Tickets.Add(ticket);
            }
            ;
            data.SaveChanges();
            return Redirect("/Destinations/All");
        }

        [Authorize]
        public HttpResponse MyTickets()
        {
            var tickets = data.Tickets
                .Where(t => t.UserId == User.Id)
                .Select(d => new ListingMyTicketsViewModel
                {
                    DestinationName = d.Destination.DestinationName,
                    Origin = d.Destination.Origin,
                    Date = d.Destination.Date,
                    ImageUrl = d.Destination.ImageUrl,
                    Price = d.Price.ToString(),
                })
                .ToList();


            return View(tickets);
        }
        [Authorize]
        public HttpResponse Reserve(string destinationId)
        {
            var ticket = data.Tickets.FirstOrDefault(t => t.DestinationId == destinationId);
            var user = data.Users.FirstOrDefault(u => u.Id == User.Id);
            var destination = data.Destinations.FirstOrDefault(d => d.Id == destinationId);

            user.Tickets.Add(ticket);
            destination.Tickets.Remove(ticket);
            ;
            data.SaveChanges();
            return Redirect("/Destinations/All");
        }
    }
}
