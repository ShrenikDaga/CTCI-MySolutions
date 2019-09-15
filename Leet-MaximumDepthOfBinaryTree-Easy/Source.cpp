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

TreeNode* createTree()
{
	TreeNode* root = new TreeNode(3);

	root->left = new TreeNode(9);

	root->right = new TreeNode(20);

	root->right->left = new TreeNode(15);

	root->right->right = new TreeNode(7);

	return root;
}

int maxDeptOfTree(TreeNode* root)
{
	if (root == nullptr)
		return 0;
	int countleft = maxDeptOfTree(root->left)+1;
	int countright = maxDeptOfTree(root->right)+1;

	return countleft > countright ? countleft : countright;
	
}

int main()
{
	TreeNode* root = createTree();

	std::cout << maxDeptOfTree(root) << std::endl;

	return 0;
}