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
#include <unordered_map>
#include <map>

struct roman
{
	char first;
	int second;
	roman(int f, char s) { f = first; s = second; };
};

int romanToInt(std::string s) 
{

	std::map<int,char> romans;

	romans[1] = 'I';
	romans[5] = 'V';
	romans[10] = 'X';
	romans[50] = 'L';
	romans[100] = 'C';
	romans[500] = 'D';
	romans[1000] = 'M';

	/*romans['M'] = 1000;
	romans['D'] = 500;
	romans['C'] = 100;
	romans['L'] = 50;
	romans['X'] = 10;
	romans['V'] = 5;
	romans['I'] = 1;*/

	int output = 0;
	auto it = --(romans.end());
	auto itGuard = --(--(--(romans.end())));

	while (s!="")
	{
		//output *= 10;
		if (s[0] == it->second)
		{
			if (it->second!='M' && it->second!='D')
			{
				if (s.size() > 1 && s[1] == next(it)->second)
				{
					output += (next(it)->first - it->first);
					s.erase(0,1);
				}
				else if(s.size() > 1 && s[1] == next(next(it))->second)
				{
					output += (next(next(it))->first - it->first);
					s.erase(0, 1);
				}
				else
				{
					output += it->first;
				}
				s.erase(0,1);
			}
			else
			{
				output += it->first;
				s.erase(0,1);
			}
		}
		else
		{
			--it;
		}
	}
	return output;
}

int main()
{
	std::cout<<romanToInt("III")<<std::endl;
	std::cout<<romanToInt("IV")<<std::endl;
	std::cout<<romanToInt("IX")<<std::endl;
	std::cout<<romanToInt("LVIII")<<std::endl;
	std::cout<<romanToInt("MCMXCIV")<<std::endl;
	std::cout<<romanToInt("MCD")<<std::endl;
	return 0;
}