namespace BusStation.Controllers
{
    using MyWebServer.Http;
    using MyWebServer.Controllers;
    using BusStation.Data;
    using System.Linq;
    using BusStation.Models.Destinations;
    using BusStation.Data.Models;

    public class DestinationsController : Controller
    {
        private readonly BusStationDbContext data;
        public DestinationsController(BusStationDbContext data) => this.data = data;
        [Authorize]
        public HttpResponse All()
        {
            var destinations = data.Destinations
                .Select(d => new ListingDestinationsViewModel
                {
                    Id = d.Id,
                    DestinationName = d.DestinationName,
                    Origin = d.Origin,
                    Date = d.Date,
                    Time = d.Time,
                    Tickets = d.Tickets
                })
                .ToList();

            return View(destinations);
        }

        [Authorize]
        public HttpResponse Add() => this.View();

        [Authorize]
        [HttpPost]
        public HttpResponse Add(AddDestinationFormModel model)
        {
            var destination = new Destination
            {
                DestinationName = model.DestinationName,
                Origin = model.Origin,
                Date = model.Date,
                Time = model.Date,
                ImageUrl = model.ImageUrl,
            };
            ;
            data.Destinations.Add(destination);
            data.SaveChanges();

            return Redirect("/Destinations/All");
        }
    }
}
