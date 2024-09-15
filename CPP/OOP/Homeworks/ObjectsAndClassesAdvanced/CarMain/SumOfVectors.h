#ifndef SUMOFVECTORS_H

#define SUMOFVECTORS_H

#include <string>

using namespace std;

class Car {
private:
	string brand;
	string model;
	int year;

public:

	Car(string& brand, string& model, int& year) : brand(brand), model(model), year(year)
	{}

	const string& GetBrand(void) const { return brand; }
	const string& GetModel(void) const { return model; }
	const int& GetYear(void) const { return year; }
};

#endif // !SUMOFVECTORS_H