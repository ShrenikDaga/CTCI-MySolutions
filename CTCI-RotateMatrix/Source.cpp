///////////////////////////////////////////////////
//Source:	Shrenik Daga, Syracuse University   //
//			shdaga@syr.edu						//
/////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::cout << "Enter size";
	int size;
	std::cin >> size;
	
	std::vector<std::vector<int>> matrix(size,std::vector<int>(size));

	for (int i = 0; i < size*size; i++)
	{
		matrix[i / size][i % size] = i+1;
	}
	
	for (int i = 0; i < size*size; i++)
	{
		std::cout<<matrix[i / size][i % size]<<" ";
		if (i%size == size-1)
			std::cout << "\n";
	}
	std::cout << "Rotate:\n";
	for (int i = (size * size)-1; i >= 0; i--)
	{
		std::cout << matrix[i % size][std::abs((i / size)-(size-1))] << " ";
		if (i%size == 0)
			std::cout << "\n";
	}

	return 0;
}