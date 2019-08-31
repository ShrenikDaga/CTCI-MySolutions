///////////////////////////////////////////////////
//Source:	Shrenik Daga, Syracuse University   //
//			shdaga@syr.edu						//
/////////////////////////////////////////////////

#include <iostream>
#include <string>
#include<unordered_map>
#include <map>
#include <vector>

std::vector<int> twoSum(std::vector<int>& nums, int target) 
{
	std::unordered_map<int, int> result;

	for (int i = 0; i < nums.size() - 1; i++)
	{
		if (result.find(target - nums[i]) != result.end())
		{
			return { result[target - nums[i]],i };
		}
		result[nums[i]] = i;
	}
}


int main()
{
	std::vector<int> digits;
	digits.push_back(1);
	digits.push_back(3);
	digits.push_back(4);
	digits.push_back(9);

	std::vector<int> result;

	result = twoSum(digits,7);

	return 0;
}