#ifndef NONCAPITALSFILTER_H
#define NONCAPITALSFILTER_H

#include <iostream>
#include <string>
#include <vector>

#include "Filter.h"

class NonCapitalsFilter : public Filter {
private:
	std::ostringstream filtered;
protected:
	virtual bool shouldFilterOut(char symbol) const override
	{
		return islower(symbol);
	}

	virtual ~NonCapitalsFilter() override {}
};

#endif // !NONCAPITALSFILTER_H