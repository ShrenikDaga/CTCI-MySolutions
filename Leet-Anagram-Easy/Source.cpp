///////////////////////////////////////////////////
//Source:	Shrenik Daga, Syracuse University   //
//			shdaga@syr.edu						//
/////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>

bool isAnagram(std::string string1, std::string string2)
{
	std::unordered_map<char, int> smap;
	if (string1.size() != string2.size())
		return false;

	for (int i = 0; i < string1.size(); i++)
	{
		smap[string1.at(i)] += 1;
		smap[string2.at(i)] -= 1;
	}
	for (auto it = smap.begin(); it != smap.end(); ++it)
	{
		if (it->second != 0)
			return false;
	}
	return true;
}

int main()
{
	std::string input1 = "anagrtam";
	std::string input2 = "nagkaram";

	isAnagram(input1,input2);
	return 0;
}