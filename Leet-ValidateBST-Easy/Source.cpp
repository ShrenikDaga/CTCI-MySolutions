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

//bool isValidBST(TreeNode* root)
//{
//	if (root == nullptr)
//		return false;
//	bool leftValid = isValidBST(root->left);
//	bool rightValid = isValidBST(root->right);
//
//	return rightValid && leftValid;
//}

bool helper(TreeNode* root, long low,long high)
{
	if (!root)
		return true;
	if (root->val <= low || root->val >= high) return false;
	return helper(root->left, low, root->val) && helper(root->right, root->val, high);
}

bool isValidBST(TreeNode* root)
{
	return helper(root,LONG_MIN,LONG_MAX);
}

int main()
{
	TreeNode* root = createBinaryTree(5);
	addLeft(root, 1);
	addRight(root,8);
	addLeft(root->right,7);
	addRight(root->right,16);
	
	std::cout << isValidBST(root);


	return 0;
}