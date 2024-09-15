using System;

namespace Vacation
{
    class Program
    {
        static void Main(string[] args)
        {

            double n = int.Parse(Console.ReadLine());
            string GroupType = Console.ReadLine();
            string Day = Console.ReadLine();

            double TotalSum = 0;

            if (GroupType == "Students")
            {
                if (Day == "Friday")
                {
                    TotalSum = n * 8.45;
                }
                else if (Day == "Saturday")
                {
                    TotalSum = n * 9.80;
                }
                else if (Day == "Sunday")
                {
                    TotalSum = n * 10.46;
                }

                if (n >= 30)
                {
                    TotalSum = TotalSum - (TotalSum * 0.15);
                }
            }
            else if (GroupType == "Business")
            {
                if (n >= 100)
                {
                    n -= 10;
                }

                if (Day == "Friday")
                {
                    TotalSum = n * 10.90;
                }
                else if (Day == "Saturday")
                {
                    TotalSum = n * 15.60;
                }
                else if (Day == "Sunday")
                {
                    TotalSum = n * 16;
                }
            }
            else if (GroupType == "Regular")
            {
                if (Day == "Friday")
                {
                    TotalSum = n * 15;
                }
                else if (Day == "Saturday")
                {
                    TotalSum = n * 20;
                }
                else if (Day == "Sunday")
                {
                    TotalSum = n * 22.50;
                }

                if ((n >= 10) && (n <= 20))
                {
                    TotalSum = TotalSum - (TotalSum * 0.05);
                }
            }
            Console.WriteLine($"Total price: {TotalSum:f2}");
        }
    }
}
