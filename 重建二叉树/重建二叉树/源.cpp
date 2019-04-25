#include<iostream>
#include<vector>

using namespace std;
 //Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.size()==0)
		{
			return nullptr;
		}
		TreeNode *root = new TreeNode(pre[0]);
		int i = 0;
		for (i; i < vin.size() && vin[i] != pre[0]; i++);
		vector<int> pre_left;  //左子树的前序遍历
		vector<int> pre_right; //右子树的前序遍历
		vector<int> vin_left;  //左子树的中序遍历
		vector<int> vin_right; //右子树的中序遍历
		int j = 1;
		for (j; j < pre.size(); j++)
		{
			if (j < i + 1){ pre_left.push_back(pre[j]); }
			else{ pre_right.push_back(pre[j]); }
		}
		int k = 0;
		for (k; k < i; k++)
		{
			vin_left.push_back(vin[k]);
		}
		for (k += 1; k < vin.size(); k++)
		{
			vin_right.push_back(vin[k]);
		}
		root->left = reConstructBinaryTree(pre_left,vin_left);
		root->right = reConstructBinaryTree(pre_right, vin_right);
		return root;
	}
};
int main()
{
	Solution s;
	vector<int> pre = { 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> vin = { 4, 7, 2, 1, 5, 3, 8, 6 };
	TreeNode *head = new TreeNode(0);
	head = s.reConstructBinaryTree(pre, vin);
	return 0;
}