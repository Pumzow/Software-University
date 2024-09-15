#pragma once
#include "Aggregator.h"

class AverageAggregator : public StreamAggregator {
private:
	int sum;
	int count;
public:
	AverageAggregator(std::istream& stream) : StreamAggregator(stream)
	{
		sum = 0;
		count = 0;
	}

	void aggregate(int next) override
	{
		count++;
		sum += next;
		aggregationResult = sum/count;
	}
};