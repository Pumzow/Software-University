#ifndef CAPITALSFILTER_H
#define CAPITALSFILTER_H

#include <iostream>
#include <string>
#include <vector>

#include "Filter.h"

class CapitalsFilter  : public Filter{
private:
	std::ostringstream filtered;
protected:
	virtual bool shouldFilterOut(char symbol) const override
	{
		return isupper(symbol);
	}

	virtual ~CapitalsFilter() override {}
};

#endif // !CAPITALSFILTER_H