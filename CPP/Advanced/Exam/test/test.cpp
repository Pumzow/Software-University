#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main() {
	map<int, int> counter;
	for (size_t i = 0; i < 6; ++i)
	{
		counter[i % 2]++;
	}
	cout << counter.size();
}
