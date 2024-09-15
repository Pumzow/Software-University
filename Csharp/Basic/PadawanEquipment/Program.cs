using System;

namespace PadawanEquipment
{
    class Program
    {
        static void Main(string[] args)
        {
            double Money = double.Parse(Console.ReadLine());
            int Students = int.Parse(Console.ReadLine());

            double SingleLightsaberPrice = double.Parse(Console.ReadLine());
            double SingleRobePrice = double.Parse(Console.ReadLine());
            double SingleBeltPrice = double.Parse(Console.ReadLine());

            double AdditinalLightsabers = Math.Ceiling(Students * 0.10);

            double MoneyNeededForLightsabers = (Students+ AdditinalLightsabers) * SingleLightsaberPrice;

            double MoneyNeededForRobes = Students * SingleRobePrice;

            double freeBelts = Math.Floor(Students / 6.00);
            double MoneyNeededForBelts = SingleBeltPrice * (Students-freeBelts);

            double TotalMoneyNeeded = MoneyNeededForLightsabers + MoneyNeededForRobes + MoneyNeededForBelts;

            if (Money >= TotalMoneyNeeded)
            {
                Console.WriteLine($"The money is enough - it would cost {TotalMoneyNeeded:f2}lv.");
            }
            else
            {
                double moneyDiff = TotalMoneyNeeded - Money;
                Console.WriteLine($"Ivan Cho will need {moneyDiff:f2}lv more.");
            }
        }
    }
}
