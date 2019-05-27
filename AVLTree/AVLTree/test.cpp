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
	AVLTreeNode<T>* _pLeft;	//����
	AVLTreeNode<T>* _pRight;	//�Һ���
	AVLTreeNode<T>* _pParent;	//˫�׽ڵ�
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