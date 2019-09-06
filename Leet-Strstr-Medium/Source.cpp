///////////////////////////////////////////////////
//Source:	Shrenik Daga, Syracuse University   //
//			shdaga@syr.edu						//
/////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

int strStr(std::string haystack, std::string needle) {

	if (needle.size() == 0)
		return 0;
	if (haystack.size() < needle.size())
		return -1;
	int returnIndex=0;
	int i, j;

	for (i = 0, j = 0; i < haystack.size() && j < needle.size();)
	{
		if (haystack[i] == needle[j])
		{
			i++; j++;
		}
		else
		{
			returnIndex++;
			i = returnIndex;
			j = 0;
		}
	}
	if (j == needle.size())
		return returnIndex;
	return - 1;
}

int main()
{
	strStr("mississippi","issipi");
	return 0;
}