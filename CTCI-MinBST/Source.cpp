#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

struct TreeNode
{
	TreeNode* Left;
	TreeNode* Right;;
	int data;
};

void DisplayVector(std::vector<int> elementsVector)
{
	std::cout << "Elements:\n";
	for (int i:elementsVector)
	{
		std::cout << i << " ";
	}
	std::cout << "\n";
}

TreeNode* CreateBST(std::vector<int> digits)
{
	if (digits.empty())
		return NULL;
	TreeNode* root = new TreeNode;
	root->Left = NULL; root->Right = NULL;
	size_t const half = digits.size() / 2;

	std::vector<int> leftDigits(digits.begin(), digits.begin() + half);
	std::vector<int> rightDigits(digits.begin() + half+1, digits.end());

	root->data = *(digits.begin() + half);
	if (!(leftDigits.empty() && rightDigits.empty()))
	{
		root->Left = CreateBST(leftDigits);
		root->Right = CreateBST(rightDigits);
	}
	return root;
}

void DisplayBST(TreeNode* root,int indent=0)
{
	if (root == NULL)
	{
		std::cout << "NULL";
		return;
	}

	
	std::cout << root->data << "\n";
	std::cout << "<-"; DisplayBST(root->Left);
	std::cout << "->"; DisplayBST(root->Right);

	return;

}

int main()
{
	int inputSize=0,inputDigit;
	std::vector<int> elements;
	TreeNode* RootNode;

	std::cout << "Hello.\nEnter the size of input: ";
	std::cin >> inputSize;

	while (inputSize)
	{
		std::cin >> inputDigit;
		elements.push_back(inputDigit);
		inputSize--;
	}

	DisplayVector(elements);

	TreeNode* node = new TreeNode;
	RootNode = node;

	node = CreateBST(elements);
	DisplayBST(node);
	return 0;
}