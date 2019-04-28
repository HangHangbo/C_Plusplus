#include<iostream>
using namespace std; 

struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};
class Solution {
public:
	bool istree(TreeNode *root1, TreeNode *root2)
	{
		if (root2 == nullptr)
			return true;
		if (root1 == nullptr)
			return false;
		if (root1->val == root2->val)
			return istree(root1->left, root2->left) && istree(root1->right, root2->right);
		else
			return false;
	}
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot1 == nullptr || pRoot2 == nullptr)
			return false;
		return istree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
	}
};
int main()
{
	Solution s;
	TreeNode *s1 = new TreeNode(1);
	TreeNode *s2 = new TreeNode(1);
	TreeNode *s3 = new TreeNode(1);
	TreeNode *s4 = new TreeNode(1);
	TreeNode *s5 = new TreeNode(1);
	s1->left = s2; s1->right = s3;
	s2->left = s4; s2->right = s5;


	TreeNode *v1 = new TreeNode(1);
	TreeNode *v2 = new TreeNode(1);
	TreeNode *v3 = new TreeNode(1);
	TreeNode *v5 = new TreeNode(1);
	TreeNode *v5 = new TreeNode(1);
	v1->left = v2; v1->right = v3;
	s.HasSubtree(s1, v1);
	return 0;
}