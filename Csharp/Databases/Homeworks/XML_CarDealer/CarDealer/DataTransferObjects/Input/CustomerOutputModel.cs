using System;
using System.Collections.Generic;
using System.Text;
using System.Xml.Serialization;

namespace CarDealer.DataTransferObjects.Input
{
    [XmlType("customer")]
    class CustomerOutputModel
    {
        [XmlAttribute("full-name")]
        public string Name { get; set; }
        [XmlAttribute("bought-cars")]
        public int CarsOwned { get; set; }
        [XmlAttribute("spent-money")]
        public decimal MoneySpent { get; set; }
    }
}
