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
		TreeNode *node = new TreeNode(0);
		int i = 0;
		node->val = pre[i];
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