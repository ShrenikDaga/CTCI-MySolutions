#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
//TODO:
/*
* Include the provision to add all for the root node
* Fix input
*/
struct TreeNode
{
	std::vector<TreeNode*> subList = {};
	int data;
};

struct MaximumAverage
{
	double maxAverage = 0;
	TreeNode* maxNode;
};

TreeNode* createTree()
{
	int input[8] = {20,12,18,11,2,3,15,8};
	/*20 is initialized*/
	TreeNode* root = new TreeNode;
	root->data = input[0];

	for (int i = 1; i < 3; i++)
	{
		/*12 and 18 initialized*/
		TreeNode* child = new TreeNode;
		child->data = input[i];
		root->subList.push_back(child);
	}
	
	TreeNode* lastNode = root->subList[0];
	for (int x = 3; x < 7; x++)
	{
		/*11 2 3 15 initialized*/
		TreeNode* child = new TreeNode;
		child->data = input[x];
		lastNode->subList.push_back(child);
	}
	
	/*commonNode is reference of 15*/
	TreeNode* commonNode;
	commonNode = lastNode->subList.back();

	lastNode = root->subList[1];
	lastNode->subList.push_back(commonNode);

	TreeNode* finalNode = new TreeNode;

	finalNode->data = input[7];
	lastNode->subList.push_back(finalNode);

	return root;
}

TreeNode* mostPopularNode(TreeNode* head,MaximumAverage* maxavg)
{
	if (head->subList.empty())
		return NULL;

	double average=0, sum=0;
	
	for (TreeNode* child : head->subList)
	{
		mostPopularNode(child, maxavg);
	}
	sum = 0;
	for (TreeNode* child : head->subList)
	{
		sum += child->data;
	}
	sum += head->data;
	average = sum / head->subList.size()+1;
	
	if (average > maxavg->maxAverage)
	{
		maxavg->maxAverage = average;
		maxavg->maxNode = head;
	}
	return maxavg->maxNode;
}

int main()
{
	std::cout << "Hello World!\n";
	MaximumAverage maximumAvg;
	maximumAvg.maxAverage = 0;
	TreeNode* head = createTree();
	TreeNode* max;

	maximumAvg.maxNode = head;

	max = mostPopularNode(head,&maximumAvg);

	std::cout << "Anser:\n" << max->data;


	return 0;


}