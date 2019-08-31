///////////////////////////////////////////////////
//Source:	Shrenik Daga, Syracuse University   //
//			shdaga@syr.edu						//
/////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>

std::vector<int> plusOne(std::vector<int> digitVector)
{
	if (digitVector.empty())
	{
		digitVector.push_back(1);
	}

	else if (digitVector.back() == 9)
	{
		digitVector.pop_back();
		digitVector = plusOne(digitVector);
		digitVector.push_back(0);
	}

	else
	{
		digitVector.back()++;
	}
	return digitVector;
}

int main()
{
	std::vector<int> digits;
	/*digits.push_back(1);
	digits.push_back(3);
	digits.push_back(4);*/
	digits.push_back(9);

	std::vector<int> result;

	result = plusOne(digits);

	return 0;
}