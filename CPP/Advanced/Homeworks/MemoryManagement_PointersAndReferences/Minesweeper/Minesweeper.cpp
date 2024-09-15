#include <iostream>

using namespace std;

int main()
{
	int h, w;
	cin >> h >> w;

	// index with map[x + w * y] - map in single contogous block
	unsigned char* sums = new unsigned char[w * h] {0};

	// Load map from input & process increments for '!' to the sums
	for (int y = 0; y < h; y++)
	{
		string s; cin >> s;
		for (int x = 0; x < w; x++)
		{
			if (s[x] == '!')
			{
				for (int xx = x - 1; xx <= x + 1; xx++)
				{
					for (int yy = y - 1; yy <= y + 1; yy++)
					{
						if (xx >= 0 && xx < w && yy >= 0 && yy < h)
						{
							sums[xx + w * yy]++;
						}
					}
				}
			}
		}
	}

	// print the data
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			cout << (int)sums[x + w * y];
		}
		cout << endl;
	}
	delete[] sums;
}