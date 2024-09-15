#ifndef FILTERFACTORY_H
#define FILTERFACTORY_H

#include "CapitalsFilter.h"
#include "NonCapital.h"
#include "DigitsFilter.h"
#include <string>
#include <sstream>
#include <string>

using namespace std;

class FilterFactory
{
public:
	Filter* buildFilter(string filter) const
	{
		if (filter == "A-Z")
		{
			Filter* filter = new CapitalsFilter();
			return filter;
		}
		else if (filter == "a-z")
		{
			Filter* filter = new NonCapitalsFilter();
			return filter;
		}
		else if (filter == "0-9")
		{
			Filter* filter = new DigitsFilter();
			return filter;
		}
		return nullptr;
	}
};

#endif // !FILTERFACTORY_H

