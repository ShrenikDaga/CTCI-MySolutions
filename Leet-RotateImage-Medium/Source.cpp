///////////////////////////////////////////////////
//Source:	Shrenik Daga, Syracuse University   //
//			shdaga@syr.edu						//
/////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

void rotate(std::vector<std::vector<int>>& matrix) 
{
	int n = matrix.size();
	//Transpose
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			std::swap(matrix[i][j],matrix[j][i]);
		}
	}
	//Reverse
	for (int i = 0; i < n; i++)
	{
		std::reverse(matrix[i].begin(),matrix[i].end());
	}
}

int main()
{
	std::vector<std::vector<int>> input{ {1,2,3},{4,5,6},{7,8,9} };

	for (auto v : input)
	{
		for (int c : v)
		{
			std::cout << c << " ";
		}
		std::cout << std::endl;
	}
	rotate(input);

	for (auto v : input)
	{
		for (int c : v)
		{
			std::cout << c<<" ";
		}
		std::cout << std::endl;
	}
	return 0;
}