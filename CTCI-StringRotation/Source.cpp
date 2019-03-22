#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string>

int main()
{
	std::string input1, input2;

	std::cout << "Enter the two string\n";
	std::cin >> input1 >> input2;
	std::vector<int> indexes;

	for (int i=0;i<input1.length();i++)
	{
		if (input2.at(i) == input1.at(0))
			indexes.push_back(i);
	}

	for (int i : indexes)
	{
		std::cout << i << ",";
	}
	int length = input2.length();
	bool flag = true;
	for (int i : indexes)
	{
		for (int x = 0; x < input1.length(); x++)
		{
			if (input1[x] != input2[(i + x) % length])
			{
				flag = false;
			}
		}
	}
	std::cout << "Verdict: "<<flag;
	return 0;
}