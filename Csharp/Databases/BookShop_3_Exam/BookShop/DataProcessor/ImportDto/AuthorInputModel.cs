using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Text;

namespace BookShop.DataProcessor.ImportDto
{
    public class AuthorInputModel
    {

        [Required]
        [StringLength(30, MinimumLength = 3)]
        public string FirstName { get; set; }


        [Required]
        [StringLength(30, MinimumLength = 3)]
        public string  LastName { get; set; }


        [Required]
        [RegularExpression("[0-9]{3}-[0-9]{3}-[0-9]{4}")]
        public string Phone { get; set; }


        [Required]
        [DataType(DataType.EmailAddress)]
        [EmailAddress]
        public string Email { get; set; }
        public List<AuthorBookInput> Books { get; set; }
    }

    public class AuthorBookInput
    {
        public int? Id { get; set; }
    }
}
