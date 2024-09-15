#ifndef DIGITSFILTER_H
#define DIGITSFILTER_H

#include <iostream>
#include <string>
#include <vector>

#include "Filter.h"

class DigitsFilter : public Filter {
private:
	std::ostringstream filtered;
protected:
	virtual bool shouldFilterOut(char symbol) const override
	{
		return isdigit(symbol);
	}

	virtual ~DigitsFilter() override {}
};

#endif // !DIGITSFILTER_H