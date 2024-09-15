#include <iostream>
#include <istream>
#include <string>
#include <array>
#include <vector>

using namespace std;

int main()
{
	int n;
	string buf;
	getline(cin, buf, ',');
	n = stoi(buf);

	char alg;
	cin >> alg;

	vector<vector<int>> m(n, vector<int>(n));

	int r = 0, c = 0;
	int direction = 1;
	for (int cur = 1; cur <= n * n; cur++)
	{
		m[r][c] = cur;

		r += direction;

		if (alg == 'A')
		{
			if (r >= n)
			{
				c++;
				r = 0;
			}
		}
		else
		{
			if (r < 0 || r >= n)
			{
				c++;
				if (direction > 0)
				{
					r = n - 1;
				}
				else
				{
					r = 0;
				}
				direction = -direction;
			}
		}
	}

	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n; c++)
		{
			cout << m[r][c] << " ";
		}
		cout << endl;
	}
}
