#include <iostream>

using namespace std;

//节点定义

template <class T>
struct AVLTreeNode
{
	AVLTreeNode(const T &val=T())
	: _pLeft(nullptr)
	, _pRight(nullptr)
	, _pParent(nullptr)
	, _data(val)
	, _bf(0)
	{}
	AVLTreeNode<T>* _pLeft;
	AVLTreeNode<T>* _pRight;
	AVLTreeNode<T>* _pParent;
	T _data;
	int _bf;
};

template <class T>
class AVLTree
{
	typedef	AVLTreeNode<T> Node;
	typedef Node* pNode;
public:
	////构造
	//AVLTree(const pNode root = nullptr)
	//	:_root(root)
	//{}
	//插入
	bool insert(const T &val)
	{
		//空树
		if (_root == nullptr)
		{
			_root = new Node(val);
			return true;
		}
		pNode cur = _root;
		pNode parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_data > val)
				cur = cur->_pLeft;
			else if (cur->_data < val)
				cur = cur->_pRight;
			else
				return false;
		}
		pNode newNode = new Node(val);
		if (val < parent->_data)
			parent->_pLeft = newNode;
		else
			parent->_pRight = newNode;
		newNode->_pParent = parent;
		cur = newNode;
		//插入新的节点平衡北破坏
		while (parent)
		{
			//更新双亲平衡因子
			if (cur == parent->_pLeft)
				parent->_bf--;
			else
				parent->_bf++;
			//parent 节点平衡因子 为 2 -2
			if (parent->_bf == 0)
				break;
			else if (parent->_bf==1||parent->_bf==-1)
			{
				cur = parent;
				parent = parent->_pParent;
			}
			else if (parent->_bf = 2)
			{

			}
		}
		return true;
	}

	//单左旋
	void _RotateL(pNode parent)
	{
		pNode NodeR = parent->_pRight;
		pNode NodeRL = NodeR->_pLeft;
		pNode Pparent = parent->_pParent;
		NodeRL->_pParent = parent;
		parent->_pRight=
	}
	//单右旋
	 void _RotateR(pNode parent)
	{

	}
	void Inorder()
	{
		_Inorder(_root);
		cout << endl;
	}

	void _Inorder(pNode root)
	{
		if (root)
		{
			_Inorder(root->_pLeft);
			cout << root->_data << " ";
			_Inorder(root->_pRight);
		}
	}
private:
	pNode _root=nullptr;
};

int main()
{
	AVLTree<int> bt;
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
	bt.insert(2);
	bt.Inorder();
	cout << endl;
	bt.insert(6);
	bt.Inorder();
	cout << endl;
	bt.insert(0);
	bt.Inorder();
	cout << endl;
	bt.insert(9);
	bt.Inorder();
	cout << endl;
	system("pause");
	return 0;
}