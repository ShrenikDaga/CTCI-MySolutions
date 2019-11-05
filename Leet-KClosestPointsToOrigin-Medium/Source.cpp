///////////////////////////////////////////////////
//Source:	Shrenik Daga, Syracuse University   //
//			shdaga@syr.edu						//
/////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <map>
#include <math.h>

double euclideanDistance(int x, int y)
{
	double xx = x * x + y * y;
	xx = sqrt(xx);
	return xx;
}

std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int K)
{
	std::stable_sort(points.begin(), points.end(), [&](const std::vector<int>& a, const std::vector<int>& b) {return euclideanDistance(a[0], a[1]) < euclideanDistance(b[0], b[1]); });
	
	std::vector<std::vector<int>> output;
	
	int a, b = 0;

	[&]()
	{
		auto runner = points.begin();
		while (K > 0 && runner != points.end())
		{
			output.push_back(*runner);
			++runner;
			--K;
		}
	}();

	return output;
}


int main()
{
	std::vector<std::vector<int>> input{ {3,3},{5,-1},{-2,4}};
	std::vector<std::vector<int>> input1{ {0,1},{1,0}};
	auto result = kClosest(input,2);
	auto result1 = kClosest(input1,2);
	return 0;
}