using SharedTrip.Models.Trips;
using SharedTrip.Models.Users;
using System.Linq;
using System.Collections.Generic;
using System.Text.RegularExpressions;

using static SharedTrip.Data.DataConstants;
using System.Globalization;
using System;

namespace SharedTrip.Services
{

    public class Validator : IValidator
    {
        public ICollection<string> ValidateUser(RegisterUserFormModel model)
        {
            var errors = new List<string>();

            if (model.Username.Length < UsernameMinLength || model.Username.Length > UsernameMaxLength) 
            {
                errors.Add($"Username '{model.Username}' is not valid. It must be between {UsernameMinLength} and {UsernameMaxLength} characters long.");
            }

            if (!Regex.IsMatch(model.Email, UserEmailRegularExpression))
            {
                errors.Add($"Email {model.Email} is not a valid e-mail address.");
            }

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

        public ICollection<string> ValidateTrip(AddTripFormModel model)
        {
            var errors = new List<string>();

            if (model.Seats < TripSeatsMinLength || model.Seats > TripSeatsMaxLength)
            {
                errors.Add($"Seats must be between {TripSeatsMinLength} and {TripSeatsMaxLength}.");
            }

            if (model.Description.Length > TripDescriptionMaxLength)
            {
                errors.Add($"Description is too long. It must less or equal than {TripDescriptionMaxLength} characters long.");
            }

            bool isParsed = DateTime.TryParseExact(model.DepartureTime, "dd.MM.yyyy HH:mm", CultureInfo.InvariantCulture, DateTimeStyles.None, out _);
            if (!isParsed)
            {
                errors.Add("Invalid Departure time. Please use this format (dd.MM.yyyy HH: mm)");
            }

            return errors;
        }
    }
}
