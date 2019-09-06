///////////////////////////////////////////////////
//Source:	Shrenik Daga, Syracuse University   //
//			shdaga@syr.edu						//
/////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string>

int reverse(int x)
{
	int result = 0;
	int prev_result = 0;

	while (x != 0)
	{
		result = result*10 + x % 10;
		if ((result - (x % 10))/10 != prev_result)
			return 0;
		prev_result = result;
		x /= 10;
	}
	return (result > INT_MAX || result < INT_MIN) ? 0 : result;
}

int main()
{
	int x = reverse(1534236469);
	std::cout << "Reverse " << x;
	return 0;
}