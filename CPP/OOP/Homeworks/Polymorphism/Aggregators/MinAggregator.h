#pragma once
#include "Aggregator.h"


class MinAggregator : public StreamAggregator {
public:
	MinAggregator(std::istream& stream) : StreamAggregator(stream) 
	{
		aggregationResult = 1000;
	}

	void aggregate(int next) override
	{
		if(aggregationResult > next) aggregationResult = next;
	}
};