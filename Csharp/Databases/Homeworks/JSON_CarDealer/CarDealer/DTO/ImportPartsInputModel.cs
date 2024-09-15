using System;
using System.Collections.Generic;
using System.Text;

namespace CarDealer.DTO
{
    public  class ImportPartsInputModel
    {
        public string name { get; set; }
        public decimal price { get; set; }
        public int quantity { get; set; }
        public int supplierId { get; set; }
    }
}
