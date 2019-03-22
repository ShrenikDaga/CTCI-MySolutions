#include <string>
#include <iostream>
#include <numeric>
#include <cctype>

int main()
{
	std::string string1, string2;
	std::cout << "Enter two stirngs\n";
	std::cin >> string1;
	std::cin >> string2;
	int charset[128] = { 0 };
	
	for (char c : string1)
	{
		charset[c] = 1;
	}
	for (char c : string2)
	{
		charset[c] = 0;
	}

	if (std::accumulate(&charset[0], &charset[128], 0) == 1)
		std::cout << "True";
	else
		std::cout << "False";

	return 0;
}