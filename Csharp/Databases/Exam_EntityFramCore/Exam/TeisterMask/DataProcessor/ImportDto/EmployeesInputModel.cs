using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Text;

namespace TeisterMask.DataProcessor.ImportDto
{
    public class EmployeesInputModel
    {
        [Required]
        [StringLength(40, MinimumLength = 3)]
        [RegularExpression("[a-z]+[0-9]*|[A-Z]+[0-9]*")]
        public string Username { get; set; }
        [Required]
        public string Email { get; set; }
        [Required]
        [RegularExpression("[0-9]{3}-[0-9]{3}-[0-9]{4}")]
        public string Phone { get; set; }
        public List<int> Tasks { get; set; }
    }
}
