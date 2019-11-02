///////////////////////////////////////////////////
//Source:	Shrenik Daga, Syracuse University   //
//			shdaga@syr.edu						//
/////////////////////////////////////////////////

#include <iostream>
#include <string>
#include<unordered_map>
#include <map>
#include <vector>

/*
Initially result is empty, then we subtract the nums[i] from target and find it in our result. 
If it doesnt exists then we store the current index i in result at index nums[i]
If it does, that means we have a matcha and we can return
*/
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
	digits.push_back(2);
	digits.push_back(7);
	digits.push_back(11);
	digits.push_back(15);

	std::vector<int> result;

	result = twoSum(digits,9);

	return 0;
}