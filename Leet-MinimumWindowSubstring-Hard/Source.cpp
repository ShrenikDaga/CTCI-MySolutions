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

struct character
{
	char value;
	int index;
};


template<class T>
bool operator==(T it1,T it2)
{
	return it1->first == it2->first && it1->second >= it2->second ? true : false;
}

bool matchKeys(std::map<char,int> A, std::map<char, int> B)
{
	if (A.empty() || B.empty())
		return false;

	auto itA = A.begin();
	auto itB = B.begin();

	while (itA != A.end())
	{
		if (itA == itB) //Directly check here itself instea dof template
		{
			++itA; ++itB;
			if (itB != B.end())
			{
			}
			else
			{
				break;
			}
		}
		else
		{
			++itA;
		}
	}
	
	return itB != B.end() ? false : true;
}

std::string minWindow(std::string s, std::string t)
{
	std::map<char, int> windowT; //What we need to acheive
	
	for (char c:t)
	{
		windowT[c]++;
	}

	std::map<char, int> minimumWindow; // What we have gotten so far

	int left=0, right = 0;

	int resultLeft=0, resultRight = s.size()+150;
	std::string result = "";

	while (right<=s.size() && left<s.size())
	{
		if (matchKeys(minimumWindow, windowT))
		{
			//record min
			if (resultRight - resultLeft > right - left)
			{
				resultLeft = left;
				resultRight = right;
				result = s.substr(left,right-left);
			}

			minimumWindow[s[left]]--;
			++left;
		}
		else
		{
			minimumWindow[s[right]]++;
			++right;
		}
	}

	return result;
}
int main()
{
	std::cout<<minWindow("ADOBECODEBANC","XYZ")<<std::endl;
	return 0;
}