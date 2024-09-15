#include <iostream>
#include <string>

using namespace std;

int main()
{
	string _book;
	getline(cin, _book);

	int _tries = 0;
	while (true)
	{
		string _currentSearch;
		getline(cin, _currentSearch);

		if (_currentSearch == _book)
		{
			cout << "You checked " << _tries << " books and found it." << endl;
			break;
		}
		else if (_currentSearch == "No More Books")
		{
			cout << "The book you search is not here!" << endl;
			cout << "You checked " << _tries << " books." << endl;
			break;
		}
		_tries++;
	}
}
