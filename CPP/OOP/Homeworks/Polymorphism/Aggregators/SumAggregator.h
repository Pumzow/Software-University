#pragma once

#include "Aggregator.h"

class SumAggregator : public StreamAggregator {
public:
	SumAggregator(std::istream& stream) : StreamAggregator(stream)
	{
		aggregationResult = 0;
	}

	void aggregate(int next) override
	{
		aggregationResult += next;
	}
};