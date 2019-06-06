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
			_header->_pParent = NodeR;
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
			_header->_pParent = NodeL;
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
	}
	bool Insert(pair<K, V>& kv)
	{
		//二叉树搜索树的插入
		if (_header->_pParent == nullptr)
		{
			//空树，插入跟节点，颜色为黑
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

		//调整，变色
		while (cur != _header->_pParent&&cur->_pParent->_color == Red)
		{
			pNode parent = cur->_pParent;
			pNode gParent = parent->_pParent;
			if (gParent->_pLeft == parent)
			{
				pNode uncle = gParent->_pRight;
				//uncle 存在且为红
				if (uncle&&uncle->_color == Red)
				{
					parent->_color = uncle->_color = Black;
					gParent->_color = Red;
					cur = gParent;
				}
				//u 不存在/ u为黑
				else
				{
					//检查是否由双旋场景：左右
					//首先左单旋 swap  右单旋
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
				//u不存在/u存在且为黑
				else{
					//检查是否有双旋场景，右左
					//先右旋 swap 左单旋
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
			//红黑树跟始终为黑色
			_header->_pParent->_color = Black;
			//为了实现后续的迭代器
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

			// 空树也是红黑树
			if (nullptr == pRoot)
				return true;
				// 检测根节点是否满足情况
			if (Black != pRoot->_color)
			{
				cout << "违反红黑树性质二：根节点必须为黑色" << endl;
				return false;
			}
			// 获取任意一条路径中黑色节点的个数
			size_t BlackCount = 0;
			pNode pCur = pRoot;
			while (pCur)
			{
				if (Black == pCur->_color)
					BlackCount++;
				pCur = pCur->_pLeft;
			}
			// 检测是否满足红黑树的性质，k用来记录路径中黑色节点的个数
			size_t k = 0;
			return _IsValidRBTree(pRoot, k, BlackCount);
		}
		bool _IsValidRBTree(pNode pRoot, size_t k, const size_t BlackCount)
		{
			//走到null之后，判断k和Black是否相等
			if (nullptr == pRoot)
			{
				if (k != BlackCount)
				{
					cout << "违反性质四：每条路径中黑色节点的个数必须相同" << endl;
					return false;
				}
				return true;
			}

			// 统计黑色节点的个数
			if (Black == pRoot->_color)
				k++;
			// 检测当前节点与其双亲是否都为红色
			pNode pParent = pRoot->_pParent;
			if (pParent && Red == pParent->_color && Red == pRoot->_color)
			{
				cout << "违反性质三：没有连在一起的红色节点" << endl;
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
			cout << "异常" << num << endl;
	}/*
	rbt.Inorder();
	cout<<rbt.IsValidRBTree()<<endl;*/
	system("pause");
	return 0;
}