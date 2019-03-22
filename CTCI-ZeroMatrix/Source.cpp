#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main()
{
	std::cout << "Enter size";
	int sizeRow,sizeCol;
	std::cin >> sizeRow;
	std::cin >> sizeCol;
	std::vector<std::vector<int>> matrix(sizeRow, std::vector<int>(sizeCol));
	std::vector<int> rowIndex, colIndex;
	std::cout << "Fill the matrix:\n";

	for (int i = 0; i < sizeRow; i++)
	{
		for (int j = 0; j < sizeCol; j++)
		{
			std::cin >> matrix[i][j];
			if (matrix[i][j] == 0)
			{
				rowIndex.push_back(i);
				colIndex.push_back(j);
			}
		}
	}

	for (int i = 0; i < sizeRow; i++)
	{
		for (int j = 0; j < sizeCol; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << "\n";
	}

	std::cout << "\n";

	for (int i = 0; i < sizeRow; i++)
	{
		for (int j = 0; j < sizeCol; j++)
		{
			if (std::find(rowIndex.begin(), rowIndex.end(), i) != rowIndex.end() || std::find(colIndex.begin(), colIndex.end(), j) != colIndex.end())
			{
				matrix[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < sizeRow; i++)
	{
		for (int j = 0; j < sizeCol; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << "\n";
	}

	return 0;
}