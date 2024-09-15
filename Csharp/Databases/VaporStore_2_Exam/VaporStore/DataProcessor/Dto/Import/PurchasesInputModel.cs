﻿using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Text;
using System.Xml.Serialization;
using VaporStore.Data.Models;
using VaporStore.Data.Models.Enums;

namespace VaporStore.DataProcessor.Dto.Import
{
    [XmlType("Purchase")]
    public class PurchasesInputModel
    {
        [Required]
        [XmlAttribute("title")]
        public string Title { get; set; }


        [Required]
        [XmlElement("Type")]
        [EnumDataType(typeof(PurchaseType))]
        public PurchaseType? Type { get; set; }


        [Required]
        [XmlElement("Key")]
        [RegularExpression("[A-Z0-9]{4}-[A-Z0-9]{4}-[A-Z0-9]{4}")]
        public string Key { get; set; }


        [Required]
        [XmlElement("Card")]
        public string Card { get; set; }


        [Required]
        [XmlElement("Date")]
        public string Date { get; set; }
    }
}
