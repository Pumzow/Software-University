using System;
using System.ComponentModel.DataAnnotations;

using static SMS.Data.DataConstants;
namespace SMS.Data.Models
{
    public class User
    {
        public string Id { get; set; } = Guid.NewGuid().ToString();
        [Required]
        [MaxLength(UsernameMaxLength)]
        public string Username { get; set; }
        [Required]
        public string Email { get; set; }
        [Required]
        [MaxLength(PasswordMaxLength)]
        public string Password { get; set; }
        public string CartId { get; set; }
        [Required]
        public Cart Cart { get; set; }
    }
}
