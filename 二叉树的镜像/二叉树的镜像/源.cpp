#include<iostream>
#include<queue>
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
	void Mirror(TreeNode *pRoot) {
		queue<TreeNode *> q;
		if (!pRoot)
			q.push(pRoot);
		while (!q.empty())
		{
			TreeNode *cur = q.front();
			q.pop();
			swap(cur->left, cur->right);
			if (cur->left != nullptr)
				q.push(cur->left);
			if (cur->right != nullptr)
				q.push(cur->right);
		}
	}
};
int main()
{
	Solution s;
	TreeNode *s1 = new TreeNode(1);
	TreeNode *s2 = new TreeNode(2);
	TreeNode *s3 = new TreeNode(3);
	TreeNode *s4 = new TreeNode(4);
	TreeNode *s5 = new TreeNode(5);
	TreeNode *s6 = new TreeNode(6);
	s1->left = s2; s1->right = s3; s2->left = s4; s4->left = s5; s5->left = s6;
	s.Mirror(s1);
	return 0;
}