#include <iostream>
#include <string>

using namespace std;

int main()
{
	int _cakeLength, _cakeWidth;
	cin >> _cakeLength >> _cakeWidth;

	int _cakePieces = _cakeLength * _cakeWidth;

	while (true)
	{
		string _input;
		cin >> _input;

		if (_input == "STOP")
		{
			if (_cakePieces > 0)
			{
				cout << _cakePieces << " pieces are left." << endl;
				break;
			}
		}
		else
		{
			_cakePieces -= stoi(_input);

			if (_cakePieces <= 0)
			{
				cout << "No more cake left! You need " << abs(_cakePieces) << " pieces more." << endl;
				break;
			}
		}

	}
}
