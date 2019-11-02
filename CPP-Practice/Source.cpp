#include <vector>
#include <iostream>

void printVector(const std::vector<int> &V)
{
	for (int i : V)
	{
		std::cout << i << " ";
	}
	std::cout << "End." << std::endl;
}

int main()
{
	std::vector<int> V1(5);
	printVector(V1);
	V1.assign(3,9);
	printVector(V1);

}