namespace SMS.Data
{
    public class DataConstants
    {
        public const int UsernameMaxLength = 20;
        public const int UsernameMinLength = 5; 
        public const string UserEmailRegularExpression = @"^([\w-\.]+)@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.)|(([\w-]+\.)+))([a-zA-Z]{2,4}|[0-9]{1,3})(\]?)$";
        public const int PasswordMaxLength = 20;
        public const int PasswordMinLength = 6;
        

        public const int ProductNameMaxLength = 20;
        public const int ProductNameMinLength = 4;
        public const decimal PriceMax = 1000M;
        public const decimal PriceMin = 0.05M;
    }
}
