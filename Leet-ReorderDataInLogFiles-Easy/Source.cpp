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


bool myComparator(std::string& left, std::string& right)
{
	int leftIndex = left.find_first_of(" ") + 1;
	int rightIndex = right.find_first_of(" ") + 1;
	if (isalpha(left[leftIndex]) && isalpha(right[rightIndex]) )
	{
		if (left.substr(leftIndex, left.size() - leftIndex) < right.substr(rightIndex, right.size() - rightIndex))
			return true;
		else if (left.substr(leftIndex, left.size() - leftIndex) == right.substr(rightIndex, right.size() - rightIndex))
		{
			if (left.substr(0, leftIndex-1) < right.substr(0, rightIndex-1))
				return true;
		}
		else
			return false;
	}
	return false;
}

std::vector<std::string> reorderLogFiles(std::vector<std::string>& logs) 
{
	int size = logs.size();
	auto itr = logs.begin();
	while(itr != logs.end() && size>0)
	{
		std::string temp = *itr;
		if (isdigit(temp[temp.find_first_of(" ") + 1]))
		{
			itr = logs.erase(itr);
			logs.push_back(temp);
		}
		else
			++itr;
		--size;
	}

	std::sort(logs.begin(),logs.end(),myComparator);
	return logs;
}



int main()
{
	//std::vector<std::string> logs{ "dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero" };

	
	std::vector<std::string> logs{ "l5sh 6 3869 08 1295", "16o 94884717383724 9", "43 490972281212 3 51", "9 ehyjki ngcoobi mi", "2epy 85881033085988", "7z fqkbxxqfks f y dg", "9h4p 5 791738 954209", "p i hz uubk id s m l", "wd lfqgmu pvklkdp u", "m4jl 225084707500464", "6np2 bqrrqt q vtap h", "e mpgfn bfkylg zewmg", "ttzoz 035658365825 9", "k5pkn 88312912782538", "ry9 8231674347096 00", "w 831 74626 07 353 9", "bxao armngjllmvqwn q", "0uoj 9 8896814034171", "0 81650258784962331", "t3df gjjn nxbrryos b" };
	std::vector<std::string> logs1 = reorderLogFiles(logs);

	for (std::string linf : logs)
	{
		std::cout << linf << std::endl;
	}

	/*
	["bxao armngjllmvqwn q","6np2 bqrrqt q vtap h","9 ehyjki ngcoobi mi","7z fqkbxxqfks f y dg",
	"t3df gjjn nxbrryos b","p i hz uubk id s m l","wd lfqgmu pvklkdp u","e mpgfn bfkylg zewmg",
	"l5sh 6 3869 08 1295","16o 94884717383724 9","43 490972281212 3 51","2epy 85881033085988",
	"9h4p 5 791738 954209","m4jl 225084707500464","ttzoz 035658365825 9","k5pkn 88312912782538",
	"ry9 8231674347096 00","w 831 74626 07 353 9","0uoj 9 8896814034171","0 81650258784962331"]
	*/
	
	return 0;
}