#include<iostream>
#include<queue>
#include<vector>

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
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> num;
		if (root == nullptr)
		{
			return num;
		}
		queue<TreeNode *> s;
		TreeNode *tmp;
		s.push(root);
		while (!s.empty())
		{
			tmp = s.front();
			if (tmp->left != nullptr)
			{
				s.push(tmp->left);
			}
			if (tmp->right != nullptr)
			{
				s.push(tmp->right);
			}
			num.push_back(tmp->val);
			s.pop();
		}
		return num;
	}
};

int main()
{
	Solution s;
	vector<int> c;
	TreeNode * s1 = new TreeNode(1);
	TreeNode * s2 = new TreeNode(2);
	TreeNode * s3 = new TreeNode(3);
	TreeNode * s4 = new TreeNode(4);
	TreeNode * s5 = new TreeNode(5);
	TreeNode * s6 = new TreeNode(6);
	s1->left = s2;
	s1->right = s3;
	s2->left = s4;
	s2->right = s5;
	s3->left = s6;
	c=s.PrintFromTopToBottom(s1);
	return 0;
}