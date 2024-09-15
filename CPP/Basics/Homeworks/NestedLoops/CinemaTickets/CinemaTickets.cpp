#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    double countTickets = 0;
    int allTickets = 0;
    double countStandartTicket = 0;
    double countStudentTicket = 0;
    double countKidTicket = 0;
    int freeOnesPlaces = 0;
    string movieName;

    while (true)
    {
        string input; 
        std::cin >> std::ws;
        getline(cin, input);
        if (input == "Finish")
        {
            break;
        }
        else
        {
            movieName = input;
            cin >> freeOnesPlaces;

            for (int i = 1; i <= freeOnesPlaces; i++)
            {
                string ticketType;
                std::cin >> std::ws;
                getline(cin, ticketType);

                if (ticketType == "End")
                {
                    cout << fixed << setprecision(2) << movieName << " - " << countTickets / freeOnesPlaces * 100 << "% full." << endl;
                    countTickets = 0;
                    break;
                }
                else
                {
                    countTickets++;
                    allTickets++;
                    if (ticketType == "student")
                    {
                        countStudentTicket++;
                    }
                    else if (ticketType == "standard")
                    {
                        countStandartTicket++;
                    }
                    else if (ticketType == "kid")
                    {
                        countKidTicket++;
                    }
                }
                if (i == freeOnesPlaces)
                {
                    cout << fixed << setprecision(2) << movieName << " - " << countTickets / freeOnesPlaces * 100 << "% full." << endl;
                    countTickets = 0;
                }
            }
        }
    }
	cout << "Total tickets: " << allTickets << endl;
	cout << fixed << setprecision(2) << countStudentTicket / allTickets * 100 << "% student tickets." << endl;
	cout << fixed << setprecision(2) << countStandartTicket / allTickets * 100 << "% standard tickets." << endl;
	cout << fixed << setprecision(2) << countKidTicket / allTickets * 100 << "% kids tickets." << endl;
}
