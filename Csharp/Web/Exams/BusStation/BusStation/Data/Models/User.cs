using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;

using static BusStation.Data.DataConstants;
namespace BusStation.Data.Models
{
    public class User
    {
        [Key]
        [Required]
        public string Id { get; set; } = Guid.NewGuid().ToString();
        [Required]
        [MaxLength(UsernameMaxLength)]
        public string Username { get; set; }
        [Required]
        public string Email { get; set; }
        [Required]
        public string Password { get; set; }
        public ICollection<Ticket> Tickets { get; set; } = new List<Ticket>();
    }
}
