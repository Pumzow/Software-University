using Cinema.Data.Models.Enums;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Text;

namespace Cinema.DataProcessor.ImportDto
{
    public class MoviesInputModel
    {
        [Required]
        [StringLength(20, MinimumLength = 3)]
        public string Title { get; set; }
        [Required]
        [EnumDataType(typeof(Genre))]
        public Genre Genre { get; set; }
        [Required]
        public TimeSpan Duration { get; set; }
        [Required]
        public double Rating { get; set; }
        [Required]
        [StringLength(20, MinimumLength = 3)]
        public string Director { get; set; }
    }
}
