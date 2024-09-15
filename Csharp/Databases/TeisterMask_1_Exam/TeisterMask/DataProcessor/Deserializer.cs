namespace TeisterMask.DataProcessor
{
    using System;
    using System.Collections.Generic;

    using System.ComponentModel.DataAnnotations;
    using System.Globalization;
    using System.IO;
    using System.Linq;
    using System.Text;
    using System.Xml.Serialization;
    using Data;
    using Newtonsoft.Json;
    using TeisterMask.Data.Models;
    using TeisterMask.Data.Models.Enums;
    using TeisterMask.DataProcessor.ImportDto;
    using ValidationContext = System.ComponentModel.DataAnnotations.ValidationContext;

    public class Deserializer
    {
        private const string ErrorMessage = "Invalid data!";

        private const string SuccessfullyImportedProject
            = "Successfully imported project - {0} with {1} tasks.";

        private const string SuccessfullyImportedEmployee
            = "Successfully imported employee - {0} with {1} tasks.";

        public static string ImportProjects(TeisterMaskContext context, string xmlString)
		{
			XmlSerializer serializer = new XmlSerializer(typeof(ProjectsInputModel[]), new XmlRootAttribute("Projects"));
			TextReader reader = new StringReader(xmlString);
			var projectsDtos = (IEnumerable<ProjectsInputModel>)serializer.Deserialize(reader);

			StringBuilder sb = new StringBuilder();
			List<Project> projects = new List<Project>();

			foreach (var currProject in projectsDtos)
			{
                if (!IsValid(currProject))
                {
                    sb.AppendLine(ErrorMessage);
                    continue;
                }

                DateTime openDate;
                bool isOpenDateValid = DateTime.TryParseExact(currProject.OpenDate, "dd/MM/yyyy", CultureInfo.InvariantCulture, DateTimeStyles.None, out openDate);
                if (!isOpenDateValid)
                {
                    sb.AppendLine(ErrorMessage);
                    continue;
                }

                DateTime? dueDate = null;

                if (!String.IsNullOrWhiteSpace(currProject.DueDate))
                {
                    DateTime dueDateDT;
                    bool isDueDateValid = DateTime.TryParseExact(currProject.DueDate, "dd/MM/yyyy", CultureInfo.InvariantCulture, DateTimeStyles.None, out dueDateDT);
                    if (!isDueDateValid)
                    {
                        sb.AppendLine(ErrorMessage);
                        continue;
                    }
                    dueDate = dueDateDT;
                }

                Project project = new Project
                {
                    Name = currProject.Name,
                    OpenDate = openDate,
                    DueDate = dueDate,
                };

                foreach (var currTask in currProject.Tasks)
                {
                    if (!IsValid(currTask))
                    {
                        sb.AppendLine(ErrorMessage);
                        continue;
                    }

                    DateTime taskOpenDate;
                    bool isTaskOpenDateValid = DateTime.TryParseExact(currTask.OpenDate, "dd/MM/yyyy", CultureInfo.InvariantCulture, DateTimeStyles.None, out taskOpenDate);
                    if (!isTaskOpenDateValid)
                    {
                        sb.AppendLine(ErrorMessage);
                        continue;
                    }


                    DateTime taskDueDate;
                    bool isTaskDueDateValid = DateTime.TryParseExact(currTask.DueDate, "dd/MM/yyyy", CultureInfo.InvariantCulture, DateTimeStyles.None, out taskDueDate);
                    if (!isTaskDueDateValid)
                    {
                        sb.AppendLine(ErrorMessage);
                        continue;
                    }

                    if (taskOpenDate < openDate)
                    {
                        sb.AppendLine(ErrorMessage);
                        continue;
                    }

                    if (dueDate.HasValue && taskDueDate > dueDate.Value)
                    {
                        sb.AppendLine(ErrorMessage);
                        continue;
                    }

                    Task task = new Task
                    {
                        Name = currTask.Name,
                        OpenDate = taskOpenDate,
                        DueDate = taskDueDate,
                        ExecutionType = (ExecutionType)currTask.ExecutionType,
                        LabelType = (LabelType)currTask.LabelType
                    };

                    project.Tasks.Add(task);
                }

                projects.Add(project);
                sb.AppendLine($"Successfully imported project - {currProject.Name} with {project.Tasks.Count} tasks.");
            }

			context.Projects.AddRange(projects);
			context.SaveChanges();
			return sb.ToString().TrimEnd();
		}

        public static string ImportEmployees(TeisterMaskContext context, string jsonString)
        {
            var employeesDtos = JsonConvert.DeserializeObject<ICollection<EmployeesInputModel>>(jsonString);

            StringBuilder sb = new StringBuilder();
            List<Employee> employees = new List<Employee>();

            foreach (var currEmployee in employeesDtos)
            {
                if (!IsValid(currEmployee))
                {
                    sb.AppendLine(ErrorMessage);
                    continue;
                }

                Employee employee = new Employee
                {
                    Username = currEmployee.Username,
                    Email = currEmployee.Email,
                    Phone = currEmployee.Phone,
                };

                foreach (var currTask in currEmployee.Tasks.Distinct())
                {
                    Task task = context.Tasks.FirstOrDefault(t => t.Id == currTask);
                    if (task == null)
                    {
                        sb.AppendLine(ErrorMessage);
                        continue;
                    }

                    employee.EmployeesTasks.Add(new EmployeeTask { Task = task });
                }

                employees.Add(employee);
                sb.AppendLine($"Successfully imported employee - {employee.Username} with {employee.EmployeesTasks.Count} tasks.");
            }

            context.Employees.AddRange(employees);
            context.SaveChanges();

            return sb.ToString().TrimEnd();
        }

        private static bool IsValid(object dto)
        {
            var validationContext = new ValidationContext(dto);
            var validationResult = new List<ValidationResult>();

            return Validator.TryValidateObject(dto, validationContext, validationResult, true);
        }
    }
}