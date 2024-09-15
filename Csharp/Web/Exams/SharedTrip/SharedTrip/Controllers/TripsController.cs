using MyWebServer.Controllers;
using MyWebServer.Http;
using SharedTrip.Data;
using SharedTrip.Data.Models;
using SharedTrip.Models.Trips;
using SharedTrip.Services;
using System;
using System.ComponentModel.DataAnnotations;
using System.Globalization;
using System.Linq;

namespace SharedTrip.Controllers
{
    public class TripsController : Controller
    {
        private readonly ApplicationDbContext data;
        private readonly IValidator validator;
        public TripsController(ApplicationDbContext data, IValidator validator)
        {
            this.data = data;
            this.validator = validator;
        }

        [Authorize]
        public HttpResponse All()
        {
            var trips = data.Trips
                .Select(t => new ListingTripsViewModel
                { 
                    Id = t.Id,
                    StartPoint = t.StartPoint,
                    EndPoint = t.EndPoint,
                    DepartureTime = t.DepartureTime.ToLocalTime().ToString("dd.MM.yyyy HH:mm", CultureInfo.InvariantCulture),
                    Seats = t.Seats
                })
                .ToList();

            return View(trips);
        }
        [Authorize]
        public HttpResponse Add() => View();
        [Authorize]
        [HttpPost]
        public HttpResponse Add(AddTripFormModel model)
        {
            var modelErrors = this.validator.ValidateTrip(model);
            if (modelErrors.Any())
            {
                return Error(modelErrors);
            }

            bool isParsed = DateTime.TryParseExact(model.DepartureTime, "dd.MM.yyyy HH:mm", CultureInfo.InvariantCulture, DateTimeStyles.None, out _);
            if (!isParsed)
            {
                //return Redirect("/Trips/Add");
                return Error("Invalid Departure time. Please use this format (dd.MM.yyyy HH: mm)");
            }

            var trip = new Trip
            {
                StartPoint = model.StartPoint,
                EndPoint = model.EndPoint,
                DepartureTime = DateTime.ParseExact(model.DepartureTime, "dd.MM.yyyy HH:mm", CultureInfo.InvariantCulture),
                ImagePath = model.ImagePath,
                Seats = model.Seats,
                Description = model.Description
            };

            data.Trips.Add(trip);
            data.SaveChanges();

            return Redirect("/Trips/All");
        }
        [Authorize]
        public HttpResponse Details(string tripId)
        {
            var trip = data.Trips
                .Where(t => t.Id == tripId)
                .Select(t => new DetailsTripViewModel
                {
                    Id = t.Id,
                    StartPoint = t.StartPoint,
                    EndPoint = t.EndPoint,
                    DepartureTime = t.DepartureTime.ToLocalTime().ToString("dd.MM.yyyy HH:mm", CultureInfo.InvariantCulture),
                    AvailableSeats = t.Seats - t.UserTrips.Count,
                    Description = t.Description,
                    ImagePath = t.ImagePath
                })
                .FirstOrDefault();

            return View(trip);
        }
        [Authorize]
        public HttpResponse AddUserToTrip(string tripId)
        {

            data.Add(new UserTrip
            {
                UserId = User.Id,
                TripId = tripId
            });
            data.SaveChanges();
            return Redirect("/Trips/All");
        }
    }
}
