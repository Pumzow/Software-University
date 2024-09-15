using System;
using System.Collections.Generic;
using System.Text;
using System.Xml.Serialization;

namespace Cinema.DataProcessor.ImportDto
{
    [XmlType("Projection")]
    public class ProjectionsInputModel
    {
        [XmlElement("MovieId")]
        public int MovieId { get; set; }
        [XmlElement("DateTime")]
        public string DateTime { get; set; }
    }
}
