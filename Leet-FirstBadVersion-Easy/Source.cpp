#include <iostream>
#include <vector>


bool isBadVersion(int n)
{
	return n >= 4 ? true : false;
}

int helper(int start, int end)
{
	if (start == end)
		return start;

	int mid = (start + end) / 2;
	int returnValue;

	bool check = isBadVersion(mid);
	if (!check)
	{
		returnValue = helper(mid+1,end);
	}
	else
	{
		returnValue = helper(start,mid);
	}
	
	return returnValue;
}

int firstBadVersion(int n)
{
	return helper(1,n);
}

int main()
{
	firstBadVersion(10);
	return 0;
}