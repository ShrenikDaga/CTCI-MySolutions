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

void countNeighbours(std::vector<std::vector<char>>& grid, int row, int column)
{
	if(row < 0 || column < 0 || column >= grid[0].size() ||  row >= grid.size() ||  grid[row][column] == '0' || grid[row][column] == '-')
		return;

	grid[row][column] = '-';

	countNeighbours(grid,row-1,column);
	countNeighbours(grid,row+1,column);
	countNeighbours(grid,row,column-1);
	countNeighbours(grid,row,column+1);

}

int numIslands(std::vector<std::vector<char>>& grid)
{
	int numOfIslands = 0;

	int row = 0, column = 0;

	while (row < grid.size() && column < grid[0].size())
	{
		if (grid[row][column] == '1')
		{
			++numOfIslands;
			countNeighbours(grid, row, column);
		}
		else
			++column;

		if (column == grid[0].size())
		{
			++row;
			column = 0;
		}
	}
	return numOfIslands;
}

int main()
{
	std::vector<std::vector<char>> input{ {'1','1','0','0','0'} ,{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','1','1','1'} };
	std::cout<<numIslands(input);
	return 0;
}