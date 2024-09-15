using BookShop.Data.Models.Enums;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Runtime.Serialization;
using System.Text;
using System.Xml.Serialization;

namespace BookShop.DataProcessor.ImportDto
{
    [XmlType("Book")]
    public class BooksInputModel
    {
        [StringLength(30, MinimumLength = 3)]
        [Required]
        [XmlElement("Name")]
        public string Name { get; set; }

        [EnumDataType(typeof(Genre))]
        [Required]
        [XmlElement("Genre")]
        public string Genre { get; set; }

        [Range(typeof(decimal), "0.01", "79228162514264337593543950335")]
        [XmlElement("Price")]
        public decimal Price { get; set; }

        [Range(50, 5000)]
        [XmlElement("Pages")]
        public int Pages { get; set; }


        [Required]
        [XmlElement("PublishedOn")]
        public string PublishedOn { get; set; }
    }
}
