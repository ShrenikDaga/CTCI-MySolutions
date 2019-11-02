///////////////////////////////////////////////////
//Source:	Shrenik Daga, Syracuse University   //
//			shdaga@syr.edu						//
/////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <unordered_map>
#include <map>

std::string intToRoman(int num)
{
	std::map<int, char> romans;

	romans[1000] = 'M';
	romans[500] = 'D';
	romans[100] = 'C';
	romans[50] = 'L';
	romans[10] = 'X';
	romans[5] = 'V';
	romans[1] = 'I';

	if (num > 3999 || num < 1)
		return "";
	std::string output = "";
	auto it = prev(romans.end());
	/*
	Try to divide by the largetest number and keep adding those romans
	Once the quotient is lest than 1, iterate to next roman
	But everytime it doesnt divide, check if it is one of the special cases
	*/
	while (num > 0)
	{
		if ((num / it->first) > 0)
		{
			int quotient = num / it->first;
			while (quotient > 0)
			{
				output += it->second;
				--quotient;
			}
			num = num % it->first;
		}
		else
		{
			/*
			Minus point is used for those 6 special cases like 4,9,40,90,400,900
			*/
			int minusPoint=0;
			if (it->first == 1000 || it->first == 500)
				minusPoint = 100;
			if (it->first == 100 || it->first == 50)
				minusPoint = 10;
			if (it->first == 10 || it->first == 5)
				minusPoint = 1;

			if (((num/minusPoint)*minusPoint) + minusPoint == it->first)
			{
				output += romans[minusPoint];
				output += romans[it->first];
				num = num - (it->first-minusPoint);
			}
			else
				it--;
		}

	}
	return output;
}

int main()
{
	std::cout << intToRoman(3)<<std::endl;
	std::cout << intToRoman(4) << std::endl;
	std::cout << intToRoman(9) << std::endl;
	std::cout << intToRoman(58) << std::endl;
	std::cout << intToRoman(1400) << std::endl;
	std::cout << intToRoman(1994) << std::endl;
	return 0;
}