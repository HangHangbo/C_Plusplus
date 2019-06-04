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
			else if (parent->_bf == 2&&cur->_bf==1)
			{
				_RotateL(parent);
			}
			else if (parent->_bf == -2&&cur->_bf==-1)
			{
				_RotateR(parent);
			}
			else if (parent->_bf == 2 && cur->_bf == -1)
			{
				_RotateRL(parent);
			}
			else if (parent->_bf == -2 && cur->_bf == 1)
			{
				_RotateLR(parent);
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
		//1.  对NodeRL 操作
		//旋转后NodeR的左孩子，作为双亲的的右孩子
		parent->_pRight = NodeRL;
		//如果NodeR的左孩子存在跟新双亲节点
		if (NodeRL)
			NodeRL->_pParent = parent;

		//2. 对parent操作
		//parent作为NodeR的左孩子
		parent->_pParent = NodeR;
		//更新双亲节点
		NodeR->_pLeft = parent;

		//3.对NodeR 操作
		NodeR->_pParent = Pparent;
		if (Pparent == nullptr)
		{
			NodeR->_pParent = nullptr;
			_root = NodeR;
		}
		//parent是子树 可能是双亲节点的左孩子或右孩子
		else
		{
			if (Pparent->_pLeft = parent)
				Pparent->_pLeft = NodeR;
			else
			{
				Pparent->_pRight = NodeR;
			}
		}
		//调整平衡因子
		NodeR->_bf = 0;
		parent->_bf = 0;
	}
	//单右旋
	 void _RotateR(pNode parent)
	{
		 pNode NodeL = parent->_pLeft;	//parent 左孩子
		 pNode NodeLR = NodeL->_pRight;	//parent 左孩子的右孩子
		 pNode Pparent = parent->_pParent;	//parent 的父节点
		 
		 //1.  对NodeLR操作
		 //旋转完成后NodeL的右孩子 作为双亲的左孩子
		 parent->_pLeft = NodeLR;
		 //如果 NodeL的右孩子存在，更新双亲节点
		 if (NodeLR)
			NodeLR->_pParent = parent;

		 //2.  对parent操作
		 //parent作为NodeL的右孩子
		 parent->_pParent = NodeL;
		 //更新双亲节点
		 NodeL->_pRight = parent;

		 //3. 对 NodeL操作
		 
		 NodeL->_pParent = Pparent;
		 //如果parent是跟节点，更新NodeL为新的跟节点
		 if (Pparent == nullptr)
		 {
			 _root = NodeL;
			 NodeL->_pParent = nullptr;
		 }
		 //parent是子树，可能是双亲的左孩子也有可能是右孩子
		 else
		 {
			 if (Pparent->_pLeft = parent)
				 Pparent->_pLeft = NodeL;
			 else
			 {
				 Pparent->_pRight = NodeL;
			 }
		 }
		 //根据调整后的结构更新部分节点的平衡因子
		 NodeL->_bf = 0;
		 parent->_bf = 0;
		 cout << "R over" << endl;
	}
	 //左右旋，新节点插入较高左子树的右侧
	 void _RotateLR(pNode parent)
	 {
		 pNode NodeL = parent->_pLeft;
		 pNode NodeLR = NodeL->_pRight;
		 //记录NodeLR的平衡因子，两次旋转后需要用来调节平衡因子
		 int bf = NodeLR->_bf;
		 //左旋
		 _RotateL(NodeL);
		 //右旋
		 _RotateR(parent);
		 if (bf == -1)
			 parent->_bf = 1;
		 else if (bf == 1)
			 NodeL->_bf = -1;
	 }
	 void _RotateRL(pNode parent)
	 {
		 pNode NodeR = parent->_pRight;
		 pNode NodeRL = NodeR->_pLeft;

		 int bf = NodeRL->_bf;
		 _RotateR(NodeR);
		 _RotateL(parent);
		 if (bf == 1)
		 {
			 parent->_bf = -1;
		 }
		 else if (bf == -1)
		 {
			 NodeR->_bf = 1;
		 }
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
	//16, 3, 7, 11, 9, 26, 18, 14, 15
	AVLTree<int> bt;
	bt.insert(16);
	bt.Inorder();
	bt.insert(3);
	bt.Inorder();
	bt.insert(7);
	bt.Inorder();
	bt.insert(11);
	bt.Inorder();
	bt.insert(9);
	bt.Inorder();
	bt.insert(26);
	bt.Inorder();
	bt.insert(18);
	bt.Inorder();
	bt.insert(14);
	bt.Inorder();
	bt.insert(15);
	bt.Inorder();
	system("pause");
	return 0;
}