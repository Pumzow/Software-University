﻿using BookShop.Data.Models.Enums;
using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Text;

namespace BookShop.Data.Models
{
    public class Book
    {
        public Book()
        {
            this.AuthorsBooks = new HashSet<AuthorBook>();
        }

        public int Id { get; set; }
        [Required]
        public string Name { get; set; }
        [Required]
        public Genre Genre { get; set; }
        public decimal Price { get; set; }
        public int Pages { get; set; }
        [Required]
        public DateTime PublishedOn { get; set; }
        public ICollection<AuthorBook> AuthorsBooks { get; set; }
    }
}
