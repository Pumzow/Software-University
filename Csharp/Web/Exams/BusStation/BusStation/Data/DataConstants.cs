namespace BusStation.Data
{
    public class DataConstants
    {
        public const int UsernameMaxLength = 20;
        public const int UsernameMinLength = 5;
        public const int UserEmailMaxLength = 60;
        public const int UserEmailMinLength = 10;
        public const int PasswordMaxLength = 20;
        public const int PasswordMinLength = 5;

        public const int DestinationNameMaxLength = 50;
        public const int DestinationNameMinLength = 2;

        public const int DestinationOriginMaxLength = 50;
        public const int DestinationOriginMinLength = 2;

        public const int DestinationDateMaxLength = 30;
        public const int DestinationTimeMaxLength = 30;

        public const decimal TicketMaxPrice = 90M;
        public const decimal TicketMinPrice = 10M;
    }
}
