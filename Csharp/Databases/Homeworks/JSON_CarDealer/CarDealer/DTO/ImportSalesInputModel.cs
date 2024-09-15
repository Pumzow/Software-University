using System;
using System.Collections.Generic;
using System.Text;

namespace CarDealer.DTO
{
    public class ImportSalesInputModel
    {
        public int carId { get; set; }
        public int customerId { get; set; }
        public int discount { get; set; }
    }
}
