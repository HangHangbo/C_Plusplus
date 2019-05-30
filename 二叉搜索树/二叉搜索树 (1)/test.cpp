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
	//����
	BSTree(const pNode root = nullptr)
		:_root(root)
	{}
	//����
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
	//����
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
	//ɾ��
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
		//�����ڣ�û�ҵ�
		if (cur == nullptr)
			return false;
		//cur��Ҷ�ӽڵ�
		if (cur->_pLeft == nullptr&&cur->_pRight == nullptr)
		{
			//�Ƿ�ɾ��root
			if (cur != _root)
			{
				//�ж�cur��parent���ĸ��ڵ�
				if (parent->_pLeft == cur)
					parent->_pLeft = nullptr;
				else
					parent->_pRight = nullptr;
			}
			else{
				//ɾ��root����Ϊ��
				_root = nullptr;
			}
			delete cur;
			cur = nullptr;
		}
		//cur����Ϊ��
		else if (cur->_pLeft==nullptr)
		{
			if (cur != _root)
			{
				//cur��parent���
				if (parent->_pLeft = cur)
				{
					parent->_pLeft = cur->_pRight;
				}
				else	//parent�ұ�
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
		//�Һ���Ϊ��
		else if (cur->_pLeft == nullptr)
		{
			if (cur != _root)
			{
				//parent���
				if (parent->_pLeft = cur)
				{
					parent->_pLeft = cur->_pLeft;
				}
				else  //parent�ұ�
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
		//���Һ��Ӷ���Ϊ��
		else
		{
			//1.Ѱ������ڵ�
			pNode pNext = cur->_pLeft;
			parent = cur;
			while (pNext->_pRight)
			{
				parent = pNext;
				pNext = pNext->_pRight;
			}
			//2.�û�
			cur->_date = pNext->_date;
			//ָ���û��ڵ��ָ��ָ��
			if (parent->_pRight == pNext)
				parent->_pRight = nullptr;
			else
			{
				//parent ����������ڵ� �����Ӳ�Ϊ�գ�
				if (pNext->_pLeft == nullptr)
					parent->_pLeft = nullptr;
				else
					parent->_pLeft = pNext->_pLeft;
			}
				 
			//3.ɾ���û��ڵ�
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