using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Text;
using System.Xml.Serialization;
using TeisterMask.Data.Models.Enums;

namespace TeisterMask.DataProcessor.ImportDto
{
    [XmlType("Project")]
    public class ProjectsInputModel
    {
        [Required]
        [StringLength(40, MinimumLength = 2)]
        [XmlElement("Name")]
        public string Name { get; set; }
        [Required]
        [XmlElement("OpenDate")]
        public string OpenDate { get; set; }



        [XmlElement("DueDate")]
        public string DueDate { get; set; }



        [XmlArray("Tasks")]
        public TasksInputModel[] Tasks { get; set; }
    }
    [XmlType("Task")]
    public class TasksInputModel
    {
        [Required]
        [StringLength(40, MinimumLength = 2)]
        [XmlElement("Name")]
        public string Name { get; set; }
        [Required]
        [XmlElement("OpenDate")]
        public string OpenDate { get; set; }
        [Required]
        [XmlElement("DueDate")]
        public string DueDate { get; set; }
        [Required]
        [XmlElement("ExecutionType")]
        [EnumDataType(typeof(ExecutionType))]
        public string ExecutionType { get; set; }
        [Required]
        [XmlElement("LabelType")]
        [EnumDataType(typeof(LabelType))]
        public string LabelType { get; set; }
    }
}
