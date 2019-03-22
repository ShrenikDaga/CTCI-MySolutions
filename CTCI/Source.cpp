#include <iostream>
#include <string>

using namespace std;

string URLify(string input1)
{

	string input2;
	for (int i = 0; i < input1.length(); i++)
	{
		if (input1.at(i) == ' ')
		{
			input2 += "%20";
		}
		else
		{
			//input2.append(input1.at(i));
			input2 += input1.at(i);
		}
	}
	return input2;
}

int main()
{
	cout << "Hello World";

	string string1;
	std::getline(std::cin,string1);
	
	cout<<string1;
	string1.append(" Hi");
	
	cout << "\n" << URLify(string1);

	return 0;
}