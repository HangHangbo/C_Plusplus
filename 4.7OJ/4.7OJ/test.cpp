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

//����һ������������������ ǰ�� ������


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


//����һ��������, �ҵ�����������ָ���ڵ������������ȡ�

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
		//����ջ
		s.push(cur);
		//��ǰ�ڵ���Ҫ�ҵĽڵ�
		if (cur == node)
			return true;
		//��ǰ�ڵ㲻��Ҫ�ҵĽڵ㣬��ȥ�����ҽڵ�
		if (getPath(cur->left, node, s))
		{

			return true;
		}
		if (getPath(cur->right, node, s))
		{
			return true;
		}
		//��ǰ�ڵ㲻����Ҫ�����Ľڵ��·���ϣ���ջ
		s.pop();
		return false;
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		stack<TreeNode*> path1;
		stack<TreeNode*> path2;
		getPath(root, p, path1);
		getPath(root, q, path2);
		//�ü�·����ʹ����·��һ����
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
		//Ѱ�ҵ�һ����ͬ�ڵ㣬��λ��������
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
ʹ�ö���ʵ��ջ�����в�����

push(x) -- Ԫ�� x ��ջ
pop() -- �Ƴ�ջ��Ԫ��
top() -- ��ȡջ��Ԫ��
empty() -- ����ջ�Ƿ�Ϊ��
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

//����һ���������������䰴��α����Ľڵ�ֵ�� �������أ������ҷ������нڵ㣩



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
		//��Žڵ�
		queue<TreeNode *>node;
		//��Ų��
		queue<int> index;
		//��Ӹ��ڵ�
		if (root)
		{
			node.push(root);
			index.push(0);
		}
		//��������
		while (!node.empty())
		{
			TreeNode *cur = node.front();
			node.pop();
			int curIndex = index.front();
			index.pop();
			//����Ŵ�ŵ�ǰ�ڵ�
			treeVec[curIndex].push_back(cur->val);
			//������һ����ӽڵ�
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

//���������Ķ�����������任ΪԴ�������ľ���


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

