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
	//删除
	bool erase(const T& val)
	{
		/*if (_root = nullptr)
		{
			return false;
		}*/
		pNode cur = _root;
		pNode parent = nullptr;
		while (cur->_date!=val&&cur!=nullptr)
		{
			parent = cur;
			if (cur->_date > val)
				cur = cur->_pLeft;
			else if (cur->_date<val)
				cur = cur->_pRight;
		}
		//不存在，没找到
		if (cur == nullptr)
			return false;
		//cur是叶子节点
		if (cur->_pLeft == nullptr&&cur->_pRight == nullptr)
		{
			//是否删除root
			if (cur != _root)
			{
				//判断cur是parent的哪个节点
				if (parent->_pLeft == cur)
					parent->_pLeft = nullptr;
				else
					parent->_pRight = nullptr;
			}
			else{
				//删除root，树为空
				_root = nullptr;
			}
			delete cur;
			cur = nullptr;
		}
		//cur左孩子为空
		else if (cur->_pLeft==nullptr)
		{
			if (cur != _root)
			{
				//cur在parent左边
				if (parent->_pLeft = cur)
				{
					parent->_pLeft = cur->_pRight;
				}
				else	//parent右边
				{
					parent->_pRight = cur->_pRight;
				}
			}
			else
			{
				_root = _root->_pRight;
			}
			delete cur;
			cur = nullptr;
		}
		//右孩子为空
		else if (cur->_pLeft == nullptr)
		{
			if (cur != _root)
			{
				//parent左边
				if (parent->_pLeft = cur)
				{
					parent->_pLeft = cur->_pLeft;
				}
				else  //parent右边
				{
					parent->_pRight = cur;
				}
			}
			else
			{
				_root = cur->_pLeft;
			}
			delete cur;
			cur = nullptr;
		}
		//左右孩子都不为空
		else
		{
			//1.寻找替代节点
			pNode pNext = cur->_pLeft;
			parent = cur;
			while (pNext->_pRight)
			{
				parent = pNext;
				pNext = pNext->_pRight;
			}
			//2.置换
			cur->_date = pNext->_date;
			//指向置换节点的指针指控
			if (parent->_pRight == pNext)
				parent->_pRight = nullptr;
			else
			{
				//parent 的左孩子这个节点 的左孩子不为空，
				if (pNext->_pLeft == nullptr)
					parent->_pLeft = nullptr;
				else
					parent->_pLeft = pNext->_pLeft;
			}
				 
			//3.删除置换节点
				delete pNext;
				pNext = nullptr;
		}
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
	BSTree<int> bt;
	bt.insert(5);
	bt.Inorder();
	cout << endl;
	bt.insert(3);
	bt.Inorder();
	cout << endl;
	bt.insert(4);
	bt.Inorder();
	cout << endl;
	bt.insert(1);
	bt.Inorder();
	cout << endl;
	bt.insert(7);
	bt.Inorder();
	cout << endl;
	bt.insert(8);
	bt.Inorder();
	cout << endl;
	/*bt.insert(2);*/
	bt.Inorder();
	cout << endl;
	bt.insert(6);
	bt.Inorder();
	cout << endl;
	bt.insert(0);
	bt.insert(12);
	bt.insert(10);
	bt.insert(11);
	bt.insert(9);
	bt.insert(13);
	bt.Inorder();
	cout << endl;

	bt.erase(3);
	bt.Inorder();
	cout << endl;


	//bt.erase(4);
	//bt.Inorder();
	//cout << endl;
	//bt.erase(8);
	//bt.Inorder();
	//bt.erase(0);
	//bt.Inorder();
	//bt.erase(1);
	//bt.Inorder();
	//bt.erase(2);
	//bt.Inorder();
	//bt.erase(5);
	//bt.Inorder();
	//bt.erase(3);
	//bt.Inorder();
	//bt.erase(7);
	//bt.Inorder();
	//bt.erase(6);
	//bt.Inorder();
	//bt.erase(9);
	//bt.Inorder();
	system("pause");
	return 0;
}
// 1 4 2 6 5 3 8 9
//1 2 3 4 5 6 8 9