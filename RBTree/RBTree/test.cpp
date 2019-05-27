#include <iostream>
using namespace std;
enum Color{Red,Black};
template <class K,class V>
struct RBTreeNode
{
	pair<K, V> _kv;
	Color _color;

	RBTreeNode<K, V>* _pLeft;
	RBTreeNode<K, V>* _pRight;
	RBTreeNode<K, V>* _pParent;

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
	bool Insert(pair<K, V>& kv)
	{
		//二叉树搜索树的插入
		if (_header->_pParent == nullptr)
		{
			//空树，插入跟节点，颜色为黑
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

	}
private:
	pNode _header;
};