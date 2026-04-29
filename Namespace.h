#pragma once
#include <vector>
namespace test
{
	double inline Sum(double x, double y)
	{
		return x + y;
	}

	double inline Sum(std::vector<double> doubles)
	{
		double sum = 0;
		for (int i = 0; i < doubles.size(); i++)
			sum += doubles[i];

		return sum;
	}

}