///////////////////////////////////////////////////
//Source:	Shrenik Daga, Syracuse University   //
//			shdaga@syr.edu						//
/////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <deque>
#include <algorithm>
#include <map>
#include <math.h>

struct TreeNode 
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isSame(TreeNode* s, TreeNode* t)
{
	if (s == nullptr && t == nullptr)
		return true;

	if (s == nullptr || t == nullptr)
		return false;

	if (s->val != t->val)
		return false;

	return isSame(s->left, t->left) && isSame(s->right,t->right);
}

bool isSubtree(TreeNode* s, TreeNode* t) 
{
	if (s == nullptr)
		return false;

	if (isSame(s, t))
		return true;

	return isSubtree(s->left, t) || isSubtree(s->right,t);
}

int main()
{
	return 0;
}