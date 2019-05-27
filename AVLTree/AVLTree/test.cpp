#include <iostream>
using namespace std;

template<class T>
struct AVLTreeNode
{
	AVLTreeNode(const T&date)
	: _pLeft(nullptr)
	, _pRight(nullptr)
	, _pParent(nullptr)
	, _date(date)
	, _bf(0)
	{}
	AVLTreeNode<T>* _pLeft;	//左孩子
	AVLTreeNode<T>* _pRight;	//右孩子
	AVLTreeNode<T>* _pParent;	//双亲节点
	T _date;
	int _bf;
};
template <class T>
class AVLtree
{
public:
private:
	AVLTreeNode _pNode;
};