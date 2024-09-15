using BusStation.Models.Users;
using System.Linq;
using System.Collections.Generic;
using System.Text.RegularExpressions;

using static BusStation.Data.DataConstants;

namespace BusStation.Services
{

    public class Validator : IValidator
    {
        public ICollection<string> ValidateUser(RegisterUserFormModel model)
        {
            var errors = new List<string>();

            //Username
            if (model.Username.Length < UsernameMinLength || model.Username.Length > UsernameMaxLength) 
            {
                errors.Add($"Username '{model.Username}' is not valid. It must be between {UsernameMinLength} and {UsernameMaxLength} characters long.");
            }
            //Email
            if (model.Email.Length < UserEmailMinLength || model.Email.Length > UserEmailMaxLength) 
            {
                errors.Add($"Email '{model.Email}' is not valid. It must be between {UserEmailMinLength} and {UserEmailMaxLength} characters long.");
            }
            //Password
            if (model.Password.Length < PasswordMinLength || model.Password.Length > PasswordMaxLength)
            {
                errors.Add($"The provided password is not valid. It must be between {PasswordMinLength} and {PasswordMaxLength} characters long.");
            }

            if (model.Password.Any(x => x == ' '))
            {
                errors.Add($"The provided password cannot contain whitespaces.");
            }

            if (model.Password != model.ConfirmPassword)
            {
                errors.Add($"Password and its confirmation are different.");
            }

            return errors;
        }
    }
}
