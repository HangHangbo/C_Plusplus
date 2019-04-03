#include<iostream>
using namespace std;

template<class T>                        //list�Ľڵ���
struct ListNode
{
	ListNode(const T&val = T())        //ȱʡ���캯��
	:_next(nullptr)
	, _prev(nullptr)
	, _date(val)
	{}
	ListNode<T>* _next;          //ָ����һ���ڵ�
	ListNode<T>* _prev;          //ָ����һ���ڵ�
	T _date;                     //����
};

template <class T,class Ref,class Ptr>
struct ListIterator             //������
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
	//iterator++  �ƶ�����һ��λ��
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
	//*iterator  ��ȡdata
	Ref operator*()
	{
		return _node->_date;
	}
	//iterator !=l.end()  �Ƚ�
	bool operator!=(const self& it)
	{
		return _node!= it._node;
	}

	Ptr operator->()
	{
		return &_node->_date;
	}
};

//���������



template <class T>
class List
{
public:
	typedef ListNode<T> Node;
	typedef Node* pNode;
	typedef ListIterator<T,T&,T*> iterator;//����Сд������������ʶ�� ����ʹ�û��ڷ�Χ��forѭ��
	//const �����ܵ��÷�const��Ա������ֻ�ܵ���const��Ա����
	//����const��Ա����operator++��operator--���Ͳ����޸ĳ�Ա_node ��ֵ
	//����const�������޷�ִ��++��--�������ʲ���
	//typedef const ListIterator<T> const iterator;�������������
	typedef ListIterator<T, const T&,const T*> const_iterator;
	List(const T& val = T()) //����
		:_head(new Node(val))
	{
		_head->_next = _head;
		_head->_prev = _head;
	}

	void PushBack(const T&val)                        //β��
	{
		/*pNode curNode = new Node(val);
		pNode prev = _head->_prev;
		prev->_next = curNode;
		curNode->_prev = prev;
		curNode->_next = _head;
		_head->_prev = curNode;*/
		Insert(end(), val);
	}
	iterator begin()
	{
		return iterator(_head->_next);
	}
	iterator end()
	{
		return iterator(_head);
	}
	void Insert(iterator pos,const T& val)                //posǰ����һ���ڵ�
	{
		pNode newNode = new Node(val);
		pNode cur = pos._node;
		pNode prev = cur->_prev;
		prev->_next = newNode;
		newNode->_prev = prev;
		cur->_prev = newNode;
		newNode->_next = cur;
	}

	iterator Erase(iterator pos)                              //ɾ��pos�ڵ�
	{
		if (pos != end())
		{
			pNode cur = pos._node;
			pNode prev = cur->_prev;
			pNode next = cur->_next;
			prev->_next = next;
			next->_prev = prev;
			delete(cur);
			pos = iterator(next);                           //���µ�������ָ����һ��λ��
		
		}
		return pos;
	}
	void Popback()
	{
		pNode cur = _head->_prev;
		pNode prev = cur->_prev;
		prev->_next = _head;
		_head->_prev = prev;
		delete(cur);
	}
private:
	pNode _head;              //����Ľڵ㣬ͷָ�룬
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