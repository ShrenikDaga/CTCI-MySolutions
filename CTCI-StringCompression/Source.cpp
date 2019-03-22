#include <iostream>
#include <string>

int main()
{
	std::cout << "Enter string\n";

	std::string inputString,outputString;

	std::cin >> inputString;
	int counter = 1;
	
	outputString += inputString.at(0);
	for (int i=1;i<inputString.length();i++)
	{
		if (inputString.at(i) == inputString.at(i - 1))
		{
			counter++;
		}
		else
		{
			outputString += std::to_string(counter);
			counter = 1;
			outputString += inputString.at(i);
		}

	}
	outputString += std::to_string(counter);
	std::cout << outputString;
	return 0;
}