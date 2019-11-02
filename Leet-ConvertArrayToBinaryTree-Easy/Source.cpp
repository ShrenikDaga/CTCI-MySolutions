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

TreeNode* sortedArrayToBST(std::vector<int>& nums, int start, int end)
{
	if (end <= start)return nullptr;
	int mid = (end + start) / 2;

	TreeNode* node = new TreeNode(nums[mid]);
	node->left = sortedArrayToBST(nums,start,mid);
	node->right = sortedArrayToBST(nums,mid+1,end);
	return node;
}

TreeNode* sortedArrayToBST(std::vector<int>& nums)
{
	return sortedArrayToBST(nums,0,nums.size());
}

int main()
{
	std::vector<int> input = { -10,-3,0,5,9 };
	TreeNode* root = sortedArrayToBST(input);
	return 0;
}