#include<iostream>
#include<queue>
#include<deque>
#include<stack>
using namespace std;

//int main()
//{
//	//priority_queue<int>  q;
//	priority_queue<int>  q;
//	q.push(1);
//	q.push(3);
//	q.push(7);
//	q.push(8);
//	q.push(324);
//	q.push(3);
//	while (!q.empty())
//	{
//		cout << q.top()<< endl;
//		q.pop();
//	}
//	system("pause");
//
//	return 0;
//}

////
//template <class T,class Container =deque<T>>
//class Queue
//{
//public:
//	void Push(const T& x)
//	{
//		_con.push_back(x);
//	}
//	void Pop()
//	{
//		_con.pop_front();
//	}
//	size_t Size()
//	{
//		return _con.size();
//	}
//	bool Empty()
//	{
//		return _con.empty();
//	}
//	T& Front()
//	{
//		return _con.front();
//	}
//	T& Back()
//	{
//		return _con.back();
//	}
//private:
//	Container _con;
//};
//
//int main()
//{
//	Queue<int> q;
//	q.Push(1);
//	q.Push(2);
//	q.Push(3);
//	q.Push(4);
//	q.Push(5);
//	while (!q.Empty())
//	{
//		cout << q.Front()<< endl;
//		q.Pop();
//	}
//	system("pause");
//	return 0;
//}

//给定一个二叉树，返回它的 前序 遍历。


// Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	void preorder(TreeNode* root, vector<int>& v)
	{
		if (root == nullptr)
			return;
		v.push_back(root->val);
		preorder(root->left, v);
		preorder(root->right, v);
	}
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> v;
		preorder(root, v);
		return v;
	}
};


//给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
    TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	bool getPath(TreeNode*cur, TreeNode*node, stack<TreeNode*>& s)
	{
		if (cur == nullptr)
			return false;
		//先入栈
		s.push(cur);
		//当前节点是要找的节点
		if (cur == node)
			return true;
		//当前节点不是要找的节点，再去看左右节点
		if (getPath(cur->left, node, s))
		{

			return true;
		}
		if (getPath(cur->right, node, s))
		{
			return true;
		}
		//当前节点不存在要搜索的节点的路径上，出栈
		s.pop();
		return false;
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		stack<TreeNode*> path1;
		stack<TreeNode*> path2;
		getPath(root, p, path1);
		getPath(root, q, path2);
		//裁剪路径，使两个路径一样长
		while (path1.size() != path2.size())
		{
			if (path1.size()>path2.size())
			{
				path1.pop();
			}
			else
			{
				path2.pop();
			}
		}
		//寻找第一个相同节点，几位公共祖先
		while (!path1.empty())
		{
			if (path1.top() == path2.top())
				break;
			path1.pop();
			path2.pop();
		}
		return path1.top();
	}
};

/*
使用队列实现栈的下列操作：

push(x) -- 元素 x 入栈
pop() -- 移除栈顶元素
top() -- 获取栈顶元素
empty() -- 返回栈是否为空
*/

class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		if (!v.empty())
			v.push(x);
		else
			s.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int a;
		if (s.empty())
		{
			while (v.size()>1)
			{
				s.push(v.front());
				v.pop();
			}
			a = v.front();
			v.pop();

		}
		else
		{
			while (s.size()>1)
			{
				v.push(s.front());
				s.pop();
			}
			a = s.front();
			s.pop();

		}
		return a;
	}

	/** Get the top element. */
	int top() {
		/* if(s.empty())
		{
		while(v.size()!=1)
		{
		s.push(v.front());
		v.pop();
		}
		int a=v.front();
		s.push(v.front());
		return a;

		}
		else
		{
		while(s.size()!=1)
		{
		v.push(s.front());
		}
		int a=s.front();
		v.push(s.front());
		return a;

		}*/

		if (!s.empty())
			return s.back();
		else
			return v.back();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return s.empty() && v.empty();
	}
private:
	queue<int> s;
	queue<int> v;
};

//给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）



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
	vector<vector<int>> levelOrder(TreeNode* root) {
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
		return treeVec;
	}
};

//操作给定的二叉树，将其变换为源二叉树的镜像。


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
		queue<TreeNode*> q;
		if (pRoot)
			q.push(pRoot);
		while (!q.empty())
		{
			TreeNode* cur = q.front();
			q.pop();
			swap(cur->left, cur->right);
			if (cur->left)
				q.push(cur->left);
			if (cur->right)
				q.push(cur->right);
		}
	}
};

