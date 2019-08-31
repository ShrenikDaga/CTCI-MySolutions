///////////////////////////////////////////////////
//Source:	Shrenik Daga, Syracuse University   //
//			shdaga@syr.edu						//
/////////////////////////////////////////////////

#include <iostream>
#include <string>
#include<unordered_map>
#include <map>
#include <vector>

bool isValidSudoku(std::vector<std::vector<char>>& board) 
{
	std::map<char, int> row[9], col[9], blk[9];
	char c;
	for (int i = 0; i < 9; i++) 
	{
		for (int j = 0; j < 9; j++) 
		{
			c = board[i][j];
			if ((c != '.') && (0 < row[i][c]++ || 0 < col[j][c]++ || 0 < blk[i / 3 * 3 + j / 3][c]++)) return false;
		}
	}
	return true;
}

int main()
{
	std::vector<std::vector<char>> board{
	std::vector<char> {'5','3','.','.','7','.','.','.','.'},
	std::vector<char> {'6','.','.','1','9','5','.','.','.'},
	std::vector<char> {'.','9','8','.','.','.','.','6','.'},
	std::vector<char> {'8','.','.','.','6','.','.','.','3'},
	std::vector<char> {'4','.','.','8','.','3','.','.','1'},
	std::vector<char> {'7','.','.','.','2','.','.','.','6'},
	std::vector<char> {'.','6','.','.','.','.','2','8','.'},
	std::vector<char> {'.','.','.','4','1','9','.','.','5'},
	std::vector<char> {'.','.','.','.','8','.','.','7','9'},
	};

	bool x = isValidSudoku(board);

	return 0;
}