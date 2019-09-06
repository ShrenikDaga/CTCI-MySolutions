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

int firstUniqueChar(std::string inputString)
{
	std::unordered_map<char, int> umap;
	int size = inputString.size();


	for (int i=0;i<size;i++)
	{
		char c = inputString.at(i);
		umap[c]++;
	}
	
	for (int i = 0; i < size; i++)
	{
		char c = inputString.at(i);
		if (umap[c] == 1)
			return i;
	}
	return -1;
}

int main()
{
	int x = firstUniqueChar("loveleetcode");
	std::cout << "Index " << x;
	return 0;
}