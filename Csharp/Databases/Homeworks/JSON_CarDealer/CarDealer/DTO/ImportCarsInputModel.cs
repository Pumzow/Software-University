using System;
using System.Collections.Generic;
using System.Text;

namespace CarDealer.DTO
{
    public class ImportCarsInputModel
    {
        public string make { get; set; }
        public string Model { get; set; }
        public int travelledDistance { get; set; }
        public IEnumerable<int> partsId { get; set; }
    }
}
