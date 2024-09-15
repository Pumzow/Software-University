using System;
using System.Collections.Generic;
using System.Text;
using System.Xml.Serialization;

namespace CarDealer.DataTransferObjects.Output
{
    [XmlType("sale")]
    public class SalesOutputModel
    {
        [XmlElement("car")]
        public CarSalesDiscountDTO Car { get; set; }
        [XmlElement("customer-name")]
        public string CustomerName { get; set; }
        [XmlElement("discount")]
        public decimal Discount { get; set; }
        [XmlElement("price")]
        public string Price { get; set; }
        [XmlElement("price-with-discount")]
        public string DescountedPrice { get; set; }
    }
}
