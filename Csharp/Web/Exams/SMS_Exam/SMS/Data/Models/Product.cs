using System;
using System.ComponentModel.DataAnnotations;

using static SMS.Data.DataConstants;

namespace SMS.Data.Models
{
    public class Product
    {
        public string Id { get; set; } = Guid.NewGuid().ToString();
        [Required]
        [MaxLength(ProductNameMaxLength)]
        public string Name { get; set; }
        [Required]
        [Range((double)PriceMin, (double)PriceMax)]
        public Decimal Price { get; set; }
        public string CartId { get; set; }
        public Cart Cart { get; set; }
    }
}
