#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> split(string s, string sep)
{
	vector<string> results;
	auto pos = s.find(sep);
	while (pos != -1)
	{
		string token = s.substr(0, pos);
		results.push_back(token);
		s = s.substr(pos + sep.size());
		pos = s.find(sep);
	}
	results.push_back(s);
	return results;
}

class Sale
{
	double sale = 0;
public:
	string town, product;
	double price, quantity;
	Sale(string t, string p, double pr,double q)
	{
		town = t;
		product = p;
		price = pr;
		quantity = q;
		sale = price * quantity;
	}

	void addProduct(double price, double quantity)
	{
		sale += price * quantity;
	}

	void print()
	{
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << town << " -> " << sale << endl;
	}
};

int main()
{
	int n;
	cin >> n;

	vector<Sale> sales;

	for (size_t i = 0; i < n; i++)
	{
		string input;
		getline(cin >> ws, input);
		vector<string> info = split(input, " ");

		string town = info.at(0);
		string product = info.at(1);
		double price = stod(info.at(2));
		double quantity = stod(info.at(3));
		bool has = false;
		for (size_t j = 0; j < sales.size(); j++)
		{
			if (sales.at(j).town == town)
			{
				sales.at(j).addProduct(price, quantity);
				has = true;
				break;
			}
		}
		if (!has)
		{
			Sale sale(town, product, price, quantity);
			sales.push_back(sale);
		}
	}

	sort(sales.begin(), sales.end(), [](const Sale& a, const Sale& b) { return (a.town < b.town); });

	for (size_t i = 0; i < sales.size(); i++)
	{
		sales.at(i).print();
	}
}
