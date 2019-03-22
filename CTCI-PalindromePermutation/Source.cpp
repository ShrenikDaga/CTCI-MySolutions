#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <cctype>


int main()
{
	std::cout << "Hello World";
	std::string input1;
	std::cout << "Enter string";
	std::getline(std::cin,input1);
	std::vector<char> input2;
	int input2Size = input1.size();
	for (int i = 0; i < input1.length(); i++)
	{
		input2.push_back(std::tolower(input1.at(i)));
	}
	
	int letters[128] = { 0 };
	for (char c:input2)
	{
		if (letters[c] == 0)
			letters[c] = 1;
		else
			letters[c] = 0;
	}
	letters[32] = 0;
	int sum = (std::accumulate(&letters[0], &letters[128], 0));

	if ( sum + input2Size == input2Size || sum + input2Size == input2Size+1)
		std::cout << "True";
	else
		std::cout << "False";

	//std::cout << input1;
	return 0;
}