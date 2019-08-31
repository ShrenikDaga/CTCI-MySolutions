///////////////////////////////////////////////////
//Source:	Shrenik Daga, Syracuse University   //
//			shdaga@syr.edu						//
/////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string>

void reverseString(std::vector<char>& stringInput)
{
	int i = 0, j = stringInput.size() - 1;

	while (i != j && j>i)
	{
		char temp = stringInput[i];
		stringInput[i] = stringInput[j];
		stringInput[j] = temp;
		i++; j--;
	}
}

int main()
{
	std::vector<char> input{ 's','h','r','e','n','i','k' };

	reverseString(input);

	return 0;
}