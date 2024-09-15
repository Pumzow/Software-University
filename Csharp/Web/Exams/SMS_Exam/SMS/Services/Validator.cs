using SMS.Models.Users;
using System.Linq;
using System.Collections.Generic;
using System.Text.RegularExpressions;

using static SMS.Data.DataConstants;
using SMS.Models.Products;

namespace SMS.Services
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

        public ICollection<string> ValidateTrip(CreateProductFormModel model)
        {
            var errors = new List<string>();

            if (model.Name.Length < ProductNameMinLength || model.Name.Length > ProductNameMinLength)
            {
                errors.Add($"Name must be between {ProductNameMinLength} and {ProductNameMinLength}.");
            }

            if (decimal.Parse(model.Price) < PriceMin || decimal.Parse(model.Price) > PriceMax)
            {
                errors.Add($"Price must be between {PriceMin} and {PriceMax}.");
            }

            return errors;
        }
    }
}
