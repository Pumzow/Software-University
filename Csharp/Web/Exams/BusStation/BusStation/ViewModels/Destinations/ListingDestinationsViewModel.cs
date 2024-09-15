using BusStation.Data.Models;
using System.Collections.Generic;

namespace BusStation.Models.Destinations
{
    public class ListingDestinationsViewModel
    {
        public string Id { get; set; }
        public string DestinationName { get; set; }
        public string Origin { get; set; }
        public string Date { get; set; }
        public string Time { get; set; }
        public string ImageUrl { get; set; }
        public ICollection<Ticket> Tickets { get; set; } = new List<Ticket>();

    }
}
