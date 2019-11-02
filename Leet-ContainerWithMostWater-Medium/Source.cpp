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

/*
Start from the extreme ends and get start closing the gap in
Move the indexes in such a way that it only stops at a value higher than the previous height
*/
int maxArea(std::vector<int>& height) 
{
	if (height.size() == 0)
		return 0;
	if (height.size() == 1)
		return height[0];

	int maxArea = 0;
	int leftIndex = 0, rightIndex = height.size() - 1;

	while (leftIndex < rightIndex)
	{
		int nextHeight = std::min(height[leftIndex], height[rightIndex]);

		maxArea = std::max(maxArea, (rightIndex-leftIndex)*nextHeight);

		while (leftIndex < height.size() && height[leftIndex] <= nextHeight)
			leftIndex++;
		while (rightIndex > -1 && height[rightIndex] <= nextHeight)
			rightIndex--;
	}
	return maxArea;

}

int main()
{
	std::vector<int> input{1,8,6,2,5,4,8,3,7};
	std::cout<<maxArea(input);
	return 0;
}