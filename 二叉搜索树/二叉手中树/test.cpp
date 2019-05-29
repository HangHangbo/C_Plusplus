#include <iostream>

using namespace std;
template <class T>
struct BSTNode
{
	BSTNode(const T& val = T())
	:_date(val)
	, _pLeft(nullptr)
	, _pRight(nullptr)
	{}
	T _date;
	BSTNode<T>* _pLeft;
	BSTNode<T>* _pRight;
};
template <class T>
class BSTree
{
public:
	typedef BSTNode<T> Node;
	typedef Node* pNode;
	//构造
	BSTree(const pNode root = nullptr)
		:_root(root)
	{}
	//查找
	pNode find(const T& val)
	{
		if (_root == nullptr)
		{
			return nullptr;
		}
		pNode cur = _root;
		while (cur)
		{
			if (cur->_date == val)
				return cur;
			else if (cur->val > val)
				cur = cur->_pLeft;
			else
				cur = cur->_pRight;
		}
		return nullptr;
	}
	//插入
	bool insert(const T&val)
	{
		if (_root == nullptr)
		{
			_root = new Node(val);
			return true;
		}
		pNode cur = _root;
		pNode parent = nullptr;
		while(cur){
			parent = cur;
			if (cur->_date > val)
				cur = cur->_pLeft;
			else if (cur->_date < val)
				cur = cur->_pRight;
			else
				return false;
		}
		pNode newNode = new Node(val);
		if (parent->_date<val)
			parent->_pRight = newNode;
		else
			parent->_pLeft = newNode;
		return true;
	}
	void Inorder()
	{
		_Inorder(_root);
	}
	void _Inorder(pNode root)
	{
		if (root == nullptr)
		{
			return;
		}
		_Inorder(root->_pLeft);
		cout << root->_date << " ";
		_Inorder(root->_pRight);
	}
private:
	pNode _root;
};
int main()
{
	BSTree<int> s;
	s.insert(1);
	s.Inorder();
	cout << endl;
	s.insert(4);
	s.Inorder();
	cout << endl;
	s.insert(2);
	s.Inorder();
	cout << endl;
	s.insert(6);
	s.Inorder();
	cout << endl;
	s.insert(5);
	s.Inorder();
	cout << endl;
	s.insert(3);
	s.Inorder();
	cout << endl;
	s.insert(8);
	s.Inorder();
	cout << endl;
	s.insert(9);
	s.Inorder();
	system("pause");
	return 0;
}
// 1 4 2 6 5 3 8 9
//1 2 3 4 5 6 8 9