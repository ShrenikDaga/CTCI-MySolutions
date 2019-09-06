///////////////////////////////////////////////////
//Source:	Shrenik Daga, Syracuse University   //
//			shdaga@syr.edu						//
/////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <unordered_map>
#include <algorithm>

std::string countAndSay(int n)
{
	if (n == 1)
		return "1";

	std::string result, temp = countAndSay(--n);
	int count = 1;
	char x = temp[0];

	for (int i = 1; i < temp.size(); i++)
	{
		if (temp[i] == x)
		{
			count++;
		}
		else
		{
			result += std::to_string(count);
			result.push_back(x);
			x = temp[i];
			count = 1;
		}
	}

	result += std::to_string(count);
	result.push_back(x);
	return result;
}

int main()
{
	std::cout << countAndSay(6) << std::endl;
	return 0;
}