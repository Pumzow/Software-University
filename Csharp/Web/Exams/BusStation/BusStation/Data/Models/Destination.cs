using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;

using static BusStation.Data.DataConstants;
namespace BusStation.Data.Models
{
    public class Destination
    {
        [Key]
        [Required]
        public string Id { get; set; } = Guid.NewGuid().ToString();
        [Required]
        [MaxLength(DestinationNameMaxLength)]
        public string DestinationName { get; set; }
        [Required]
        [MaxLength(DestinationNameMaxLength)]
        public string Origin { get; set; }
        [Required]
        [MaxLength(DestinationDateMaxLength)]
        public string Date { get; set; }
        [Required]
        [MaxLength(DestinationTimeMaxLength)]
        public string Time { get; set; }
        [Required]
        public string ImageUrl { get; set; }
        public ICollection<Ticket> Tickets { get; set; } = new List<Ticket>();

    }
}
