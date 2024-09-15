using System;
using System.ComponentModel.DataAnnotations;

using static BusStation.Data.DataConstants;
namespace BusStation.Data.Models
{
    public class Ticket
    {
        [Key]
        [Required]
        public string Id { get; set; } = Guid.NewGuid().ToString();
        [Required]
        [Range((double)TicketMinPrice, (double)TicketMaxPrice)]
        public decimal Price { get; set; }
        [Required]
        public string UserId { get; set; }
        public User User { get; set; }
        [Required]
        public string DestinationId { get; set; }
        public Destination Destination { get; set; }
    }
}
