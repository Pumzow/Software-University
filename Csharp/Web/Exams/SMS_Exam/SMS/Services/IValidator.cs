namespace SMS.Services
{
    using SMS.Models.Users;
    using System.Collections.Generic;

    public interface IValidator
    {
        ICollection<string> ValidateUser(RegisterUserFormModel model);
        //ICollection<string> ValidateTrip(AddTripFormModel model);
    }
}
