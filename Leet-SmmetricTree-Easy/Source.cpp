///////////////////////////////////////////////////
//Source:	Shrenik Daga, Syracuse University   //
//			shdaga@syr.edu						//
/////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>

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

bool isSymmetric(TreeNode* leftNode, TreeNode* rightNode)
{
	if (leftNode==nullptr && rightNode == nullptr)
		return true;
	if (leftNode == nullptr || rightNode == nullptr)
		return false;
	if (leftNode->val == rightNode->val)
		return isSymmetric(leftNode->left, rightNode->right) && isSymmetric(leftNode->right, rightNode->left);
	return false;
}

bool helper(TreeNode* root)
{
	if (!root)
		return true;

	return isSymmetric(root->left,root->right);
}



int main()
{
	TreeNode* root = createBinaryTree(5);
	addLeft(root, 1);
	addRight(root, 1);

	addLeft(root->left, 16);
	addRight(root->left,7);

	addLeft(root->right, 7);
	addRight(root->right, 16);

	std::cout << helper(root);


	return 0;
}