using System;

namespace RageExpenses
{
    class Program
    {
        static void Main(string[] args)
        {
            int LostGamesCount = int.Parse(Console.ReadLine());

            double HeadsetPrice = double.Parse(Console.ReadLine());
            double MousePrice = double.Parse(Console.ReadLine());
            double KeyboardPrice = double.Parse(Console.ReadLine());
            double DisplayPrice = double.Parse(Console.ReadLine());

            double RageExpenses = 0;
            int KeyboardTrashed = 0;

            for (int i = 1; i <= LostGamesCount; i++)
            {
                if (i % 6 == 0)
                {
                    RageExpenses += HeadsetPrice + MousePrice + KeyboardPrice;
                    KeyboardTrashed++;
                }
                else if(i % 3 == 0)
                {
                    RageExpenses += MousePrice;
                }
                else if (i % 2 == 0)
                {
                    RageExpenses += HeadsetPrice;
                }

                if (KeyboardTrashed == 2)
                {
                    RageExpenses += DisplayPrice;
                    KeyboardTrashed = 0;
                }
            }

            Console.WriteLine($"Rage expenses: {RageExpenses:f2} lv.");
        }
    }
}
