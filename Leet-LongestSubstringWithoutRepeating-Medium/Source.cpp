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
Start with the first index of inpout s and find the contigous substring
If repeated, then switch to the next index in s
Store the max at each iteration
Be carfull of corner cases, like line 35
*/
int lengthOfLongestSubstring(std::string s) 
{
	if (s == "")
		return 0;
	if (s == " ")
		return 1;
	if (s.size() == 1)
		return 1;
	int max=0;
	std::string longest;
	for (int i=0;i<s.size()-1;i++)
	{
		int maxLength=1;
		std::string longestString = "";
		longestString += s.at(i);

		int index = i+1;
		while (index < s.size()&&longestString.find(s.at(index)) == std::string::npos)
		{
			longestString+=((s.at(index)));
			++index;
			maxLength = longestString.size();
		}
		if (max < maxLength)
		{
			longest = longestString;
			max = maxLength;
		}
	}
	return max;
}

int main()
{
	std::string input{"c"};
	std::cout<<lengthOfLongestSubstring(input);
	return 0;
}