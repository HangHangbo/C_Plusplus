#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
//
////二叉树的中序遍历遍历
// //Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
//
// //递归
//class Solution {
//public:
//	void Traversal(TreeNode*node, vector<int>& s)
//	{
//		if (node == nullptr)
//			return;
//		Traversal(node->left, s);
//		s.push_back(node->val);
//		Traversal(node->right, s);
//	}
//	vector<int> inorderTraversal(TreeNode* root) {
//		vector<int> s;
//		Traversal(root, s);
//		return s;
//	}
//};
//
////非递归
//class Solution {
//public:
//	vector<int> inorderTraversal(TreeNode* root) {
//		vector<int> s;
//		stack<TreeNode*> st;
//		TreeNode * cur = root;
//		while (cur || !st.empty())
//		{
//			while (cur)
//			{
//				st.push(cur);
//				cur = cur->left;
//			}
//			cur = st.top();
//			s.push_back(cur->val);
//			st.pop();
//			cur = cur->right;
//		}
//		return s;
//	}
//	
//};
////两个栈实现队列
//
//class MyQueue {
//public:
//	/** Initialize your data structure here. */
//	MyQueue() {
//
//	}
//
//	/** Push element x to the back of queue. */
//	void push(int x) {
//		s.push(x);
//	}
//
//	/** Removes the element from in front of queue and returns that element. */
//	int pop() {
//		if (v.empty())
//		{
//			while (!s.empty())
//			{
//				v.push(s.top());
//				s.pop();
//			}
//		}
//		int a = v.top();
//		v.pop();
//		return a;
//	}
//
//	/** Get the front element. */
//	int peek() {
//		if (v.empty())
//		{
//			while (!s.empty())
//			{
//				v.push(s.top());
//				s.pop();
//			}
//		}
//		return v.top();
//	}
//
//	/** Returns whether the queue is empty. */
//	bool empty() {
//		return s.empty() && v.empty();
//	}
//private:
//	stack<int> s; //入队栈
//	stack<int> v; //出队栈
//};

//给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
// Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	int getHeight(TreeNode* root)
	{
		if (root == nullptr)
			return 0;
		int left = getHeight(root->left);
		int right = getHeight(root->right);
		return left>right ? left + 1 : right + 1;
	}
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> treeVec;
		treeVec.resize(getHeight(root));
		//存放节点
		queue<TreeNode *>node;
		//存放层号
		queue<int> index;
		//入队根节点
		if (root)
		{
			node.push(root);
			index.push(0);
		}
		//遍历队列
		while (!node.empty())
		{
			TreeNode *cur = node.front();
			node.pop();
			int curIndex = index.front();
			index.pop();
			//按层号存放当前节点
			treeVec[curIndex].push_back(cur->val);
			//带入下一层的子节点
			if (cur->left)
			{
				node.push(cur->left);
				index.push(curIndex + 1);
			}
			if (cur->right)
			{
				node.push(cur->right);
				index.push(curIndex + 1);
			}
		}
		vector<vector<int>> retreeVec;
		for (int i = treeVec.size() - 1; i >= 0; i--)
		{
			vector<int> tmp = treeVec[i];
			retreeVec.push_back(tmp);
		}
		return retreeVec;
	}
};