﻿using System;
using System.Collections.Generic;
using System.Text;
using System.Xml.Serialization;

namespace TeisterMask.DataProcessor.ExportDto
{
    [XmlType("Project")]
    public class ProjectExportModel
    {
        [XmlAttribute("TasksCount")]
        public int TasksCount { get; set; }
        [XmlElement("ProjectName")]
        public string ProjectName { get; set; }
        [XmlElement("HasEndDate")]
        public string HasEndDate { get; set; }
        [XmlArray]
        public TaskExportModel[] Tasks { get; set; }
    }

    [XmlType("Task")]
    public class TaskExportModel
    {
        [XmlElement("Name")]
        public string Name { get; set; }
        [XmlElement("Label")]
        public string Label { get; set; }
    }
}
