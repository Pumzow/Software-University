using System;

namespace Ages
{
    class Program
    {
        static void Main(string[] args)
        {
            int Ages = int.Parse(Console.ReadLine());

            if (Ages < 2)
            {

                Console.WriteLine("baby");

            }
            else if ((Ages > 2) && (Ages < 14))
            {

                Console.WriteLine("child");

            }
            else if ((Ages > 13) && (Ages < 20))
            {

                Console.WriteLine("teenager");

            }
            else if ((Ages > 19) && (Ages < 66))
            {

                Console.WriteLine("adult");

            }
            else if (Ages > 65)
            {

                Console.WriteLine("elder");

            }

        }
    }
}
