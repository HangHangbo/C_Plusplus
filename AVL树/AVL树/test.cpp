#include <iostream>

using namespace std;

//�ڵ㶨��

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
	////����
	//AVLTree(const pNode root = nullptr)
	//	:_root(root)
	//{}
	//����
	bool insert(const T &val)
	{
		//����
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
		//�����µĽڵ�ƽ�ⱱ�ƻ�
		while (parent)
		{
			//����˫��ƽ������
			if (cur == parent->_pLeft)
				parent->_bf--;
			else
				parent->_bf++;
			//parent �ڵ�ƽ������ Ϊ 2 -2
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

	//������
	void _RotateL(pNode parent)
	{
		pNode NodeR = parent->_pRight;
		pNode NodeRL = NodeR->_pLeft;
		pNode Pparent = parent->_pParent;
		//1.  ��NodeRL ����
		//��ת��NodeR�����ӣ���Ϊ˫�׵ĵ��Һ���
		parent->_pRight = NodeRL;
		//���NodeR�����Ӵ��ڸ���˫�׽ڵ�
		if (NodeRL)
			NodeRL->_pParent = parent;

		//2. ��parent����
		//parent��ΪNodeR������
		parent->_pParent = NodeR;
		//����˫�׽ڵ�
		NodeR->_pLeft = parent;

		//3.��NodeR ����
		NodeR->_pParent = Pparent;
		if (Pparent == nullptr)
		{
			NodeR->_pParent = nullptr;
			_root = NodeR;
		}
		//parent������ ������˫�׽ڵ�����ӻ��Һ���
		else
		{
			if (Pparent->_pLeft = parent)
				Pparent->_pLeft = NodeR;
			else
			{
				Pparent->_pRight = NodeR;
			}
		}
		//����ƽ������
		NodeR->_bf = 0;
		parent->_bf = 0;
	}
	//������
	 void _RotateR(pNode parent)
	{
		 pNode NodeL = parent->_pLeft;	//parent ����
		 pNode NodeLR = NodeL->_pRight;	//parent ���ӵ��Һ���
		 pNode Pparent = parent->_pParent;	//parent �ĸ��ڵ�
		 
		 //1.  ��NodeLR����
		 //��ת��ɺ�NodeL���Һ��� ��Ϊ˫�׵�����
		 parent->_pLeft = NodeLR;
		 //��� NodeL���Һ��Ӵ��ڣ�����˫�׽ڵ�
		 if (NodeLR)
			NodeLR->_pParent = parent;

		 //2.  ��parent����
		 //parent��ΪNodeL���Һ���
		 parent->_pParent = NodeL;
		 //����˫�׽ڵ�
		 NodeL->_pRight = parent;

		 //3. �� NodeL����
		 
		 NodeL->_pParent = Pparent;
		 //���parent�Ǹ��ڵ㣬����NodeLΪ�µĸ��ڵ�
		 if (Pparent == nullptr)
		 {
			 _root = NodeL;
			 NodeL->_pParent = nullptr;
		 }
		 //parent��������������˫�׵�����Ҳ�п������Һ���
		 else
		 {
			 if (Pparent->_pLeft = parent)
				 Pparent->_pLeft = NodeL;
			 else
			 {
				 Pparent->_pRight = NodeL;
			 }
		 }
		 //���ݵ�����Ľṹ���²��ֽڵ��ƽ������
		 NodeL->_bf = 0;
		 parent->_bf = 0;
		 cout << "R over" << endl;
	}
	 //���������½ڵ����ϸ����������Ҳ�
	 void _RotateLR(pNode parent)
	 {
		 pNode NodeL = parent->_pLeft;
		 pNode NodeLR = NodeL->_pRight;
		 //��¼NodeLR��ƽ�����ӣ�������ת����Ҫ��������ƽ������
		 int bf = NodeLR->_bf;
		 //����
		 _RotateL(NodeL);
		 //����
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