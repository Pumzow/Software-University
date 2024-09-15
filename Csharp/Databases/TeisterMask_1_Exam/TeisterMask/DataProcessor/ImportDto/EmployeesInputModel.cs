using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Text;

namespace TeisterMask.DataProcessor.ImportDto
{
    public class EmployeesInputModel
    {
        [Required]
        [StringLength(40, MinimumLength = 2)]
        [RegularExpression(@"^[A-Za-z0-9]{3,}$")]
        public string Username { get; set; }

        [Required]
        [DataType(DataType.EmailAddress)]
        [EmailAddress]
        public string Email { get; set; }

        [RegularExpression(@"^\d{3}\-\d{3}\-\d{4}$")]
        [Required]
        public string Phone { get; set; }

        public IEnumerable<int> Tasks { get; set; }
    }
}
