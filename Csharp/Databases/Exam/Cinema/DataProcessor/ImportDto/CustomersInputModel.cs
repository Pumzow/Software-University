using System;
using System.Collections.Generic;
using System.Text;
using System.Xml.Serialization;

namespace Cinema.DataProcessor.ImportDto
{
    [XmlType("Customer")]
    public class CustomersInputModel
    {
        [XmlElement("FirstName")]
        public string FirstName { get; set; }
        [XmlElement("LastName")]
        public string LastName { get; set; }
        [XmlElement("Age")]
        public int Age { get; set; }
        [XmlElement("Balance")]
        public decimal Balance { get; set; }
        [XmlArray("Tickets")]
        public TicketsInputModel[] Tickets { get; set; }
    }
    [XmlType("Ticket")]
    public class TicketsInputModel
    {
        [XmlElement("ProjectionId")]
        public int ProjectionId { get; set; }
        [XmlElement("Price")]
        public decimal Price { get; set; }
    }
}
