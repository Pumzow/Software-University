using BusStation.Data.Models;
using System.Collections.Generic;

namespace BusStation.Models.Destinations
{
    public class AddDestinationFormModel
    {
        public string DestinationName { get; set; }
        public string Origin { get; set; }
        public string Date { get; set; }
        public string ImageUrl { get; set; }

    }
}
