///////////////////////////////////////////////////
//Source:	Shrenik Daga, Syracuse University   //
//			shdaga@syr.edu						//
/////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string>

bool isPlaindrome(std::string input)
{
	int left = 0, right = input.size() - 1;

	while (left < right)
	{
		while (left < right && !isalnum(input[left]))
			left++;

		while (left < right && !isalnum(input[right]))
			right--;

		if (tolower(input[left]) != tolower(input[right]))
			return false;

		left++;
		right--;
	
	}
	return true;

}

int main() 
{
	bool x = isPlaindrome("A man, a plan, a canal: Panama");
	std::cout << "value " << x;
	return 0;
}