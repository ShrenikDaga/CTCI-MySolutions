#include <vector>
#include <iostream>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
{
	for (int i = 0; i < n; i++)
		nums1.pop_back();

	auto it = nums1.begin();

	for (int num : nums2)
	{
		it = nums1.begin();
		bool done = false;
		while (it != nums1.end())
		{
			if (*it < num)
				it++;
			else
			{
				nums1.emplace(it, num);
				done = true;
				break;
			}
		}
		if (!done)
		{
			nums1.push_back(num);
		}
	}
}

int main()
{
	std::vector<int> nums1{ -1,0,0,3,3,3,0,0,0 };
	std::vector<int> nums2{ 1,2,2 };
	merge(nums1, nums1.size(),nums2,nums2.size());

	for (int n : nums1)
	{
		std::cout << n << " ";
	}


	return 0;
}