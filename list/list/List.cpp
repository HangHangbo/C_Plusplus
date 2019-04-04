#include<iostream>
using namespace std;

template<class T>                        //list的节点类
struct ListNode
{
	ListNode(const T&val = T())        //缺省构造函数
	:_next(nullptr)
	, _prev(nullptr)
	, _date(val)
	{}
	ListNode<T>* _next;          //指向下一个节点
	ListNode<T>* _prev;          //指向上一个节点
	T _date;                     //数据
};

template <class T,class Ref,class Ptr>
struct ListIterator             //迭代器
{
	typedef ListNode<T>* pNode;
	typedef ListIterator<T,Ref,Ptr> self;
	pNode _node;

	ListIterator(pNode node)
		:_node(node)
	{}
	//++iterator
	self & operator++()
	{
		_node = _node->_next;
		return *this;
	}
	//iterator++  移动到下一个位置
	self operator++(int)
	{
		self tmp(*this);
		_node = _node->_next;
		return tmp;
	}
	//--iterator
	self& operator--()
	{
		_node = _node->_prev;
		return *this;
	}
	//iterator--
	self operator--(int)
	{
		self tmp(*);
		_node = _node->_prev;
		return tmp;
	}
	//*iterator  获取data
	Ref operator*()
	{
		return _node->_date;
	}
	//iterator !=l.end()  比较
	bool operator!=(const self& it)
	{
		return _node!= it._node;
	}

	Ptr operator->()
	{
		return &_node->_date;
	}
};

//反响迭代器



template <class T>
class List
{
public:
	typedef ListNode<T> Node;
	typedef Node* pNode;
	typedef ListIterator<T,T&,T*> iterator;//必须小写，编译器不能识别 不能使用基于范围的for循环
	//const 对象不能调用非const成员函数，只能调用const成员函数
	//但是const成员函数operator++，operator--，就不能修改成员_node 的值
	//导致const迭代器无法执行++，--操作，故不能
	//typedef const ListIterator<T> const iterator;这样定义迭代器
	typedef ListIterator<T, const T&,const T*> const_iterator;
	List(const T& val = T()) //构造
		:_head(new Node(val))
	{
		_head->_next = _head;
		_head->_prev = _head;
	}
	size_t Size()const
	{
		size_t count = 0;
		pNode cur = _head->_next;
		while (cur != _head)
		{
			count++;
			cur = cur->_next;
		}
		return count;
	}
	bool Empty()
	{
		return _head->_next == _head;
	}
	void PushBack(const T&val)                        //尾插
	{
		/*pNode curNode = new Node(val);
		pNode prev = _head->_prev;
		prev->_next = curNode;
		curNode->_prev = prev;
		curNode->_next = _head;
		_head->_prev = curNode;*/
		Insert(end(), val);
	}
	iterator begin()                                   //迭代器正向
	{
		return iterator(_head->_next);
	}
	iterator end()
	{
		return iterator(_head);
	}
	iterator Insert(iterator pos,const T& val)                //pos前插入一个节点
	{
		pNode newNode = new Node(val);
		pNode cur = pos._node;
		pNode prev = cur->_prev;
		prev->_next = newNode;
		newNode->_prev = prev;
		cur->_prev = newNode;
		newNode->_next = cur;
		return iterator(newNode);
	}
	void Clear()                                    //销毁链表
	{
		pNode cur = _head->_next;
		while (cur != _head)
		{
			_head->_next = cur->_next;
			delete (cur);
			cur = _head->_next;
		}
		_head->_next = _head;
		_head->_prev = _head;
	}

	iterator Erase(iterator pos)                              //删除pos节点
	{
		if (pos != end())
		{
			pNode cur = pos._node;
			pNode prev = cur->_prev;
			pNode next = cur->_next;
			prev->_next = next;
			next->_prev = prev;
			delete(cur);
			pos = iterator(next);         //更新迭代器，指向下一个位置
		
		}
		return pos;
	}
	void Popback()                                      //尾删
	{
		pNode cur = _head->_prev;
		pNode prev = cur->_prev;
		prev->_next = _head;
		_head->_prev = prev;
		delete(cur);
	}
	void PushFront(const T&val)                     //头插
	{
		pNode newNode = new Node(val);
		pNode cur = _head->_prev;
		pNode ret = _head;
		cur->_next = newNode;
		newNode->_prev = cur;
		ret->_prev = newNode;
		newNode->_next =ret;
		_head = newNode;
	}
private:
	pNode _head;              //链表的节点，头指针，
};

int main()
{
	List<int>lst;
	lst.PushBack(1);
	lst.PushBack(2);
	lst.PushBack(3);
	lst.PushBack(4);
	/*lst.Erase(lst.begin());
	lst.Erase(--lst.end());*/
	lst.Popback();
	lst.PushFront(0);
	cout<<lst.Size()<<endl;

	lst.Clear();
	cout << lst.Empty() << endl;
	auto lit = lst.begin();
	while (lit != lst.end())
	{
		cout << *lit << " ";
		++lit;
	}
	cout << endl;
	system("pause");
	return 0;
}