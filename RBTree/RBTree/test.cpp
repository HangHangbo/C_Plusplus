#include <iostream>
#include <time.h>
using namespace std;
enum Color{Red,Black};
template <class K,class V>
struct RBTreeNode
{
	pair<K, V> _kv;
	Color _color;

	RBTreeNode<K, V>* _pLeft=nullptr;
	RBTreeNode<K, V>* _pRight=nullptr;
	RBTreeNode<K, V>* _pParent=nullptr;

};
template <class K,class V>
class RBTree
{
public:
	typedef RBTreeNode<K,V> Node;
	typedef Node* pNode;
	RBTree()
		:_header(new Node)
	{
		_header->_pLeft = _header;
		_header->_pRight = _header;
	}
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
			_header->_pParent = NodeR;
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
			_header->_pParent = NodeL;
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
	}
	bool Insert(pair<K, V>& kv)
	{
		//�������������Ĳ���
		if (_header->_pParent == nullptr)
		{
			//������������ڵ㣬��ɫΪ��
			pNode root = new Node;
			root->_kv = kv;
			root->_color = Black;
			_header->_pParent = root;
			root->_pParent = _header;
			_header->_pLeft = root;
			_header->_pRight = root;
			return true;
		}
		pNode cur = _header->_pParent;
		pNode parent = nullptr;
		while (cur)
		{
			if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_pLeft;
			}
			else if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_pRight;
			}
			else
				return false;
		}
		cur = new Node;
		cur->_kv = kv;
		if (parent-> _kv.first>cur->_kv.first)
			parent->_pLeft = cur;
		else
			parent->_pRight = cur;
		cur->_pParent = parent;

		//��������ɫ
		while (cur != _header->_pParent&&cur->_pParent->_color == Red)
		{
			pNode parent = cur->_pParent;
			pNode gParent = parent->_pParent;
			if (gParent->_pLeft == parent)
			{
				pNode uncle = gParent->_pRight;
				//uncle ������Ϊ��
				if (uncle&&uncle->_color == Red)
				{
					parent->_color = uncle->_color = Black;
					gParent->_color = Red;
					cur = gParent;
				}
				//u ������/ uΪ��
				else
				{
					//����Ƿ���˫������������
					//�������� swap  �ҵ���
					if (parent->_pRight == cur)
					{
						_RotateL(parent);
						swap(parent, cur);
					}
					_RotateR(gParent);
					parent->_color = Black;
					gParent->_color = Red;
					break;
				}
			}
			else
			{
				pNode uncle = gParent->_pLeft;
				if (uncle&&uncle->_color == Red)
				{
					parent->_color = uncle->_color = Black;
					gParent->_color = Red;
					cur = gParent;
				}
				//u������/u������Ϊ��
				else{
					//����Ƿ���˫������������
					//������ swap ����
					if (parent->_pLeft == cur)
					{
						_RotateR(parent);
						swap(parent, cur);
					}
					_RotateL(gParent);
					parent->_color = Black;
					gParent->_color = Red;
				}
			}
			//�������ʼ��Ϊ��ɫ
			_header->_pParent->_color = Black;
			//Ϊ��ʵ�ֺ����ĵ�����
			_header->_pLeft = leftMost();
			_header->_pRight = rightMost();
			return true;
		}
	}
		pNode leftMost()
		{
			pNode cur = _header->_pLeft;
			while (cur&& cur->_pLeft)
			{
				cur = cur->_pLeft;
			}
			return cur;
		}
		pNode rightMost()
		{
			pNode cur = _header->_pRight;
			while (cur&&cur->_pRight)
			{
				cur = cur->_pRight;
			}
			return cur;
		}
		void Inorder()
		{
			_Inorder(_header->_pParent);
			cout << endl;
		}
		void _Inorder(pNode root)
		{
			if (root){
				_Inorder(root->_pLeft);
				cout << root->_kv.first << " ";
				_Inorder(root->_pRight);
			}
		}
		bool IsValidRBTree()
		{
			pNode pRoot = _header->_pParent;

			// ����Ҳ�Ǻ����
			if (nullptr == pRoot)
				return true;
				// �����ڵ��Ƿ��������
			if (Black != pRoot->_color)
			{
				cout << "Υ����������ʶ������ڵ����Ϊ��ɫ" << endl;
				return false;
			}
			// ��ȡ����һ��·���к�ɫ�ڵ�ĸ���
			size_t BlackCount = 0;
			pNode pCur = pRoot;
			while (pCur)
			{
				if (Black == pCur->_color)
					BlackCount++;
				pCur = pCur->_pLeft;
			}
			// ����Ƿ��������������ʣ�k������¼·���к�ɫ�ڵ�ĸ���
			size_t k = 0;
			return _IsValidRBTree(pRoot, k, BlackCount);
		}
		bool _IsValidRBTree(pNode pRoot, size_t k, const size_t BlackCount)
		{
			//�ߵ�null֮���ж�k��Black�Ƿ����
			if (nullptr == pRoot)
			{
				if (k != BlackCount)
				{
					cout << "Υ�������ģ�ÿ��·���к�ɫ�ڵ�ĸ���������ͬ" << endl;
					return false;
				}
				return true;
			}

			// ͳ�ƺ�ɫ�ڵ�ĸ���
			if (Black == pRoot->_color)
				k++;
			// ��⵱ǰ�ڵ�����˫���Ƿ�Ϊ��ɫ
			pNode pParent = pRoot->_pParent;
			if (pParent && Red == pParent->_color && Red == pRoot->_color)
			{
				cout << "Υ����������û������һ��ĺ�ɫ�ڵ�" << endl;
				return false;
			}
			return _IsValidRBTree(pRoot->_pLeft, k, BlackCount) &&
				_IsValidRBTree(pRoot->_pRight, k, BlackCount);
		}
private:
	pNode _header;
};

int main()
{
	srand(time(nullptr));
	RBTree<int, int> rbt;
	/*int arr[] = { 5, 7, 9, 1, 3, 4, 10, 6, 8 };
	for (const auto& e : arr)
	{
		rbt.Insert(make_pair(e, e));
	}*/
	int n;
	cin >> n;
	while (n--)
	{
		int num = rand();
		rbt.Insert(make_pair(num, n));
		if (!rbt.IsValidRBTree())
			cout << "�쳣" << num << endl;
	}/*
	rbt.Inorder();
	cout<<rbt.IsValidRBTree()<<endl;*/
	system("pause");
	return 0;
}