///////////////////////////////////////////////////
//Source:	Shrenik Daga, Syracuse University   //
//			shdaga@syr.edu						//
/////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <map>


std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) 
{
	std::map<std::string, int> map;
	std::vector<std::string> strs2 = strs;

	std::vector<std::vector<std::string>> result;

	for (int i=0;i<strs.size();i++)
	{
		std::sort(strs[i].begin(),strs[i].end());
		map[strs[i]]++;
	}

	std::map < std::string, std::vector<std::string>> miniResult;

	for (int i = 0; i < strs2.size(); i++)
	{
		auto word = strs2[i];
		
		std::sort(word.begin(),word.end());

		
		if (map[word] > 0) 
		{
			map[word]--;
			miniResult[word].push_back(strs2[i]);
		}
		if(map[word] == 0)
		{
			result.push_back(miniResult[word]);
		}
		
	}

	return result;

}

int main()
{
	std::vector<std::string> input{"eat","tea","tan","ate","nat","bat"};
	groupAnagrams(input);
	return 0;
}