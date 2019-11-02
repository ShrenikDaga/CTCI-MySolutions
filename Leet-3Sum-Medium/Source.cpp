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
#include <algorithm>


std::vector<std::vector<int>> threeSum(std::vector<int>& nums) 
{
	std::vector<std::vector<int>> result;

	std::sort(nums.begin(),nums.end());

	for (int i = 0; i < nums.size();)
	{
		auto target = -nums[i];

		int left = i + 1, right = nums.size() - 1;

		while (left < right)
		{
			auto sum = nums[left] + nums[right];
			
			if (sum < target)
				while (nums[++left] == nums[left - 1]);
			else if (sum > target)
				while (nums[--right] == nums[right + 1]);
			else
			{
				result.push_back(std::vector<int>{nums[i],nums[left],nums[right]});
				while (left <= nums.size()-1 && nums[++left] == nums[left - 1] && left < nums.size());
				while (right > 0 && nums[--right] == nums[right + 1] && right > 0);
			}

		}
		while (i < nums.size()-1 && nums[++i] == nums[i-1]);
		if (i == nums.size() - 1)
			break;
	}
	return result;
}

int main()
{
	std::vector<int> a{0,0,0};
	threeSum(a);
	return 0;
}