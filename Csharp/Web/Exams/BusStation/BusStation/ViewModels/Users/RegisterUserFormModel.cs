using BusStation.Data.Models;
using System.Collections.Generic;

namespace BusStation.Models.Users
{
    public class RegisterUserFormModel
    {
        public string Username { get; set; }
        public string Email { get; set; }
        public string Password { get; set; }
        public string ConfirmPassword { get; set; }
    }
}
