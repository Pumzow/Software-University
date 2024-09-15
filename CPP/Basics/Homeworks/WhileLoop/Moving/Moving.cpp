#include <iostream>
#include <string>
using namespace std;

int main()
{
	int width, length, height;
	cin >> width >> length >> height;
	int totalSpace = width * length * height;

	int totalBoxes = 0;
	int box;
	string input;

	cin >> input;

	while (input != "Done") {

		box = stoi(input);
		totalBoxes += box;

		if (totalSpace < totalBoxes) { break; }
		cin >> input;

	}

	if (totalSpace < totalBoxes) {
		int res = totalBoxes - totalSpace;
		cout << "No more free space! You need " << res << " Cubic meters more." << endl;
	}
	else {
		int res = totalSpace - totalBoxes;
		cout << res << " Cubic meters left." << endl;
	}

	return 0;
}
