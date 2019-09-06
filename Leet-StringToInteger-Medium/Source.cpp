///////////////////////////////////////////////////
//Source:	Shrenik Daga, Syracuse University   //
//			shdaga@syr.edu						//
/////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string>

int myAtoi(std::string inputString)
{
	int index = inputString.find_first_not_of(' ' );
	int sign = 1,result=0;

	if (inputString[index] == '+' || inputString[index] == '-')
		sign = inputString[index++] == '+' ? 1 : -1;
	while (index < inputString.size() && isdigit(inputString[index]))
	{
		result = result * 10 + (inputString[index++] - '0');
		if (result*sign > INT_MAX) return INT_MAX;
		if (result*sign < INT_MIN)return INT_MIN;
	}
	return result * sign;
}

int main() 
{
	std::string input;
	std::getline(std::cin, input);

	auto number = myAtoi(input);

	return 0;
}