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

std:: string longestCommonPrefix(std::vector<std::string>& strs)
{
	if (strs.empty())
		return "";

	std::sort(strs.begin(),strs.end());

	std::string first = strs[0], last = strs.back();

	int i = 0;

	for (; i < std::min(first.size(), last.size()); i++)
	{
		if (first[i] != last[i])
			break;
	}
	return first.substr(0,i);

}

std::string longestCommonPrefix2(std::vector<std::string>& strs)
{
	if (strs.empty())
		return "";

	int shortestStringIndex = 0;

	for (int i=1;i<strs.size();i++)
	{
		if (strs[i].size() < strs[shortestStringIndex].size())
			shortestStringIndex = i;
	}
	std::string shortestString = strs[shortestStringIndex];
	for (std::string str : strs)
	{
		while (str.find(shortestString,0) != 0)
			shortestString = shortestString.substr(0,shortestString.size()-1);
	}
	return shortestString;
}

int main()
{
	std::vector<std::string> strings;
	strings.push_back("flower");
	strings.push_back("flow");
	strings.push_back("florist");

	//std::cout << longestCommonPrefix(strings) << std::endl;
	std::cout << longestCommonPrefix2(strings)<<std::endl;
	return 0;
}