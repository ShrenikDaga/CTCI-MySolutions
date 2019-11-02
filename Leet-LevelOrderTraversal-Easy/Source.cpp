///////////////////////////////////////////////////
//Source:	Shrenik Daga, Syracuse University   //
//			shdaga@syr.edu						//
/////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <queue>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* createBinaryTree(int value)
{
	TreeNode* newNode = new TreeNode(value);
	return newNode;
}

void addLeft(TreeNode*& node, int val)
{
	node->left = new TreeNode(val);
}

void addRight(TreeNode*& node, int val)
{
	node->right = new TreeNode(val);
}



std::vector<std::vector<int>> levelOrder(TreeNode* root)
{
	std::vector<std::vector<int>> result;
	
	if (!root)
		return result;

	std::queue<TreeNode*> queue;
	queue.push(root);
	queue.push(nullptr);
	std::vector<int> levelDigits;
	
	while (!queue.empty())
	{
		TreeNode* temp = queue.front();
		queue.pop();
		
		if (temp == nullptr)
		{
			result.push_back(levelDigits);
			levelDigits.resize(0);
			if (queue.size() > 0)
				queue.push(nullptr);
		}
		else
		{
			levelDigits.push_back(temp->val);
			if (temp->left) queue.push(temp->left);
			if (temp->right)queue.push(temp->right);
		}
	}
	return result;
}

int main()
{
	TreeNode* root = createBinaryTree(5);
	addLeft(root, 1);
	addRight(root, 6);

	addLeft(root->right, 7);
	addRight(root->right, 16);

	std::vector<std::vector<int>> output = levelOrder(root);

	return 0;
}