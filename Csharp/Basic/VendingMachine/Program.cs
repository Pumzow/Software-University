using System;

namespace VendingMachine
{
    class Program
    {
        static void Main(string[] args)
        {
            double TotalInsertedSum = 0;

            while (true)
            {
                string Command = Console.ReadLine();

                if (Command != "Start")
                {
                    double InsertedSum = double.Parse(Command);

                    if ((InsertedSum == 0.1) || (InsertedSum == 0.2) || (InsertedSum == 0.5) || (InsertedSum == 1) || (InsertedSum == 2))
                    {
                        TotalInsertedSum += InsertedSum;
                    }
                    else
                    {
                        Console.WriteLine($"Cannot accept {InsertedSum}");
                    }
                }
                else
                {
                    break;
                }
            }

            while (true)
            {
                string Command = Console.ReadLine();

                if (Command != "End")
                {
                    if (Command == "Nuts")
                    {
                        if (TotalInsertedSum >= 2.00)
                        {
                            TotalInsertedSum -= 2.00;

                            Console.WriteLine($"Purchased nuts");
                        }
                        else
                        {
                            Console.WriteLine("Sorry, not enough money");
                        }
                    }
                    else if (Command == "Water")
                    {
                        if (TotalInsertedSum >= 0.70)
                        {
                            TotalInsertedSum -= 0.70;

                            Console.WriteLine($"Purchased water");
                        }
                        else
                        {
                            Console.WriteLine("Sorry, not enough money");
                        }
                    }
                    else if (Command == "Crisps")
                    {
                        if (TotalInsertedSum >= 1.50)
                        {
                            TotalInsertedSum -= 1.50;

                            Console.WriteLine($"Purchased crisps");
                        }
                        else
                        {
                            Console.WriteLine("Sorry, not enough money");
                        }
                    }
                    else if (Command == "Soda")
                    {
                        if (TotalInsertedSum >= 0.80)
                        {
                            TotalInsertedSum -= 0.80;

                            Console.WriteLine($"Purchased soda");
                        }
                        else
                        {
                            Console.WriteLine("Sorry, not enough money");
                        }
                    }
                    else if (Command == "Coke")
                    {
                        if (TotalInsertedSum >= 1.00)
                        {
                            TotalInsertedSum -= 1.00;

                            Console.WriteLine($"Purchased coke");
                        }
                        else
                        {
                            Console.WriteLine("Sorry, not enough money");
                        }
                    }
                    else
                    {
                        Console.WriteLine("Invalid product");
                    }
                }
                else
                {
                    break;
                }
            }
            Console.WriteLine($"Change: {TotalInsertedSum:f2}");
        }
    }
}
