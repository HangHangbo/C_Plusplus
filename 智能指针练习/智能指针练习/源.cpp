#include <iostream>
#include <thread>
#include <mutex>
#include <memory>
#include <vector>
using namespace std;
//class A
//{};
//
//int fun()
//{
//	throw "Error";
//	int a = 10;
//	throw a;
//	throw A();
//}
//
//int main()
//{
//	try
//	{
//		fun();
//	}
//	catch ()
//	{
//	}
//	catch ()
//	{
//	}
//	return 0;
//}

//int Division(int a, int b)
//{
//	if (b == 0)
//		throw "Division by zero !";
//	return a / b;
//}
//
//void test()
//{
//	int a, b;
//	cin >> a >> b;
//	try
//	{
//		Division(a, b);
//	}
//	catch (const int a)
//	{
//		cout << a << endl;
//	}
//	catch (const char c)
//	{
//		cout << c << endl;
//	}
//	/*catch (const char* str)
//	{
//		cout << str << endl;
//	}*/
//}
//
//int main()
//{
//	try
//	{
//		test();
//	}
//	catch (const int a)
//	{
//		cout << a << endl;
//	}
//	catch (const char c)
//	{
//		cout << c << endl;
//	}
//	/*catch (const char* str)
//	{
//	cout << str << endl;
//	}*/
//	catch (...)
//	{
//		cout << "Unknow Error" << endl;
//	}
//	return 0;
//}

//double Division(int a, int b)
//{
//	// ��b == 0ʱ�׳��쳣
//	if (b == 0)
//	{
//		throw "Division by zero condition!";
//	}
//	return (double)a / (double)b;
//}
//void Func()
//{
//	// ������Կ������������0�����׳��쳣�����������arrayû�еõ��ͷš�
//	// �������ﲶ���쳣�󲢲������쳣���쳣���ǽ������洦�����ﲶ������
//	// �����׳�ȥ��
//	int* array = new int[10];
//	try {
//		int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << endl;
//	}
//	catch (...)
//	{
//		cout << "delete []" << array << endl;
//		delete[] array;
//		throw;
//	}
//	// ...
//	cout << "delete []" << array << endl;
//	
//	delete[] array;
//}
//
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (const char* str)
//	{
//		cout << str << endl;
//	}
//	return 0;
//}
//#include <vector>
//int main()
//{
//	try
//	{
//		vector<int> v;
//		//v.reserve(1000000000);
//		v.at(100) = 10;
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "Unknow Error" << endl;
//	}
//	int a = 0;
//	int b = 2;
//	return 0;
//}

//template <class T>
//class SmartPtr
//{
//public:
//	SmartPtr(T* ptr)
//		:_ptr(ptr)
//	{}
//
//	~SmartPtr()
//	{
//		if (_ptr)
//		{
//			delete _ptr;
//			_ptr = nullptr;
//			cout << "delete _ptr" << endl;
//		}
//	}
//private:
//	T* _ptr;
//};

//#include <vector>
//void _MergeSort(int* a, int left, int right, int* tmp)
//{
//	if (left >= right) return;
//	int mid = left + ((right - left) >> 1);
//	// [left, mid]
//	// [mid+1, right]
//	_MergeSort(a, left, mid, tmp);
//	_MergeSort(a, mid + 1, right, tmp);
//	int begin1 = left, end1 = mid;
//	int begin2 = mid + 1, end2 = right;
//	int index = left;
//	while (begin1 <= end1 && begin2 <= end2)
//	{
//		if (a[begin1] < a[begin2])
//			tmp[index++] = a[begin1++];
//		else
//			tmp[index++] = a[begin2++];
//	}
//	while (begin1 <= end1)
//		tmp[index++] = a[begin1++];
//	while (begin2 <= end2)
//		tmp[index++] = a[begin2++];
//	memcpy(a + left, tmp + left, sizeof(int)*(right - left + 1));
//}
//
//void MergeSort(int* a, int n)
//{
//	int* tmp = new int;
//	//RAII
//	SmartPtr<int> sp(tmp);
//	///_MergeSort(a, 0, n - 1, tmp);
//	// ������账����һЩ�����߼�
//	vector<int> v(1000000000, 10);
//	// ...
//	cout << "delete tmp" << endl;
//	delete tmp;
//}
//int main()
//{
//	int a[5] = { 4, 5, 2, 3, 1 };
//	try
//	{
//		MergeSort(a, 5);
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	
//	catch (...)
//	{
//		cout << "Unknow Error" << endl;
//	}
//	
//	return 0;
//}
//����ָ�룺
// ʵ��RAII˼��
// ��ָ��һ������

//template <class T>
//class SmartPtr
//{
//public:
//	SmartPtr(T* ptr)
//		:_ptr(ptr)
//	{}
//
//	~SmartPtr()
//	{
//		if (_ptr)
//		{
//			delete _ptr;
//			_ptr = nullptr;
//			//cout << "delete _ptr" << endl;
//		}
//	}
//
//	//*ptr  ptr->
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//
//private:
//	T* _ptr;
//};

//struct Date
//{
//	int _year = 1900;
//	int _month = 1;
//	int _day = 1;
//
//	~Date()
//	{
//		cout << "~Date()" << endl;
//	}
//};
//
//template <class T>
//class AutoPtr
//{
//public:
//	AutoPtr(T* ptr)
//		:_ptr(ptr)
//	{}
//	//����Ȩת�ƣ���������ͷ�
//	AutoPtr(AutoPtr<T>& ap)
//		:_ptr(ap._ptr)
//	{
//		ap._ptr = nullptr;
//	}
//
//
//
//	~AutoPtr()
//	{
//		if (_ptr)
//		{
//			delete _ptr;
//			_ptr = nullptr;
//			//cout << "delete _ptr" << endl;
//		}
//	}
//
//	//*ptr  ptr->
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//
//private:
//	T* _ptr;
//};
//// ����
//// ʵ��RAII + ָ��
//// ȱ�㣺���ܿ���
//template <class T>
//class UniquePtr
//{
//public:
//	UniquePtr(T* ptr)
//		:_ptr(ptr)
//	{}
//	~UniquePtr()
//	{
//		if (_ptr)
//		{
//			delete _ptr;
//			_ptr = nullptr;
//			//cout << "delete _ptr" << endl;
//		}
//	}
//
//	//*ptr  ptr->
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//
//private:
//	//ֻ��������ʵ��
//	UniquePtr(const UniquePtr<T>& up);
//	UniquePtr<T>& operator=(const UniquePtr<T>& up);
//	//����Ϊdelete����
//	/*UniquePtr(const UniquePtr<T>& up) = delete;
//	UniquePtr<T>& operator=(const UniquePtr<T>& up) = delete;*/
//	T* _ptr;
//};

struct Date
{
	int _year = 1;
	int _month = 1;
	int _day = 1;

	~Date()
	{
		cout << "~Date()" << endl;
	}
};

//int main()
//{
//	/*int* pa = new int(1);*/
//	SmartPtr<int> sp(new int(1));
//	//*pa = 8;
//	*sp = 10;
//
//	//Date* pd = new Date;
//	SmartPtr<Date> spd(new Date);
//	//pd->_year = 2019;
//	spd->_year = 2018;
//	spd.operator->()->_year = 2020;
//	//�������죺Ĭ��--> ǳ����--> �����ͷ�
//	SmartPtr<Date> spd2 = spd;
//	spd2->_year = 2021;
//
//	Date* pd3 = new Date;
//	Date* pd4 = pd3;
//	return 0;
//}
//int main()
//{
//	AutoPtr<Date> ap(new Date);
//	AutoPtr<Date> ap2 = ap; 
//	AutoPtr<Date> ap3 = ap2;
//	Date* p = new Date;
//	Date* p2 = p;
//	Date* p3 = p;
//	p->_year = 2019;
//	p2->_year = 2019;
//	p3->_year = 2020;
//
//	//����Ȩת�ƣ�ָ�����գ� C++98: auto_ptr ��ֹʹ��
//	//ap->_year = 2019;
//	//ap2->_year = 2020;
//	ap3->_year = 2019;
//	(*ap3)._year = 2020;
//	return 0;
//}

//int main()
//{
//	UniquePtr<Date> up(new Date);
//	//UniquePtr<Date> upcopy(up);
//	up->_year = 0;
//	return 0;
//}

//int main()
//{
//	/*shared_ptr<Date> sp(new Date);
//	shared_ptr<Date> spcopy(sp);
//	shared_ptr<Date> sp2(new Date);
//	sp2 = sp;
//
//	cout << sp.use_count() << endl;
//	return 0;*/
//
//	//�Ƿ�ʹ�ã�������RAII˼��
//	//Date* pd = new Date;
//	//shared_ptr<Date> sp(pd);
//	//shared_ptr<Date> spcopy(pd);
//
//
//	shared_ptr<Date> sp(new Date);
//	shared_ptr<Date> spcopy(sp);
//	spcopy = sp;
//	shared_ptr<Date> sp2(new Date);
//	shared_ptr<Date> sp2copy(sp2);
//	cout << sp.use_count() << endl;
//	cout << sp2.use_count() << endl;
//	return 0;
//}

//template <class T>
//class SharedPtr
//{
//public:
//	//���캯���ڵ�һ��������Դ�����
//	// sharedPtr<T> sp(new T)
//	SharedPtr(T* ptr)
//		:_ptr(ptr)
//		, _useCount(new int(1))
//		, _mtx(new mutex)
//	{}
//
//	SharedPtr(const SharedPtr<T>& sp)
//		:_ptr(sp._ptr)
//		, _useCount(sp._useCount)
//		, _mtx(sp._mtx)
//	{
//		//��ǰָ����Դ�����ü�����1
//		addRef();
//	}
//
//	SharedPtr<T>& operator=(const SharedPtr<T>& sp)
//	{
//		// ������������ָ�����ͬһƬ�ռ�����������Ҫ���и�ֵ
//		//if (this != &sp)
//		if (_ptr != sp._ptr)
//		{
//			if (subRef() == 0)
//			{
//				delete _ptr;
//				delete _useCount;
//				delete _mtx;
//			}
//
//			_ptr = sp._ptr;
//			_useCount = sp._useCount;
//			_mtx = sp._mtx;
//			addRef();
//		}
//		return *this;
//
//	}
//
//	~SharedPtr()
//	{
//		if (subRef() == 0)
//		{
//			delete _ptr;
//			delete _mtx;
//			delete _useCount;
//			_ptr = nullptr;
//			_mtx = nullptr;
//			_useCount = nullptr;
//			//cout << "delete _ptr" << endl;
//		}
//	}
//
//	int addRef()
//	{
//		_mtx->lock();
//		++(*_useCount);
//		_mtx->unlock();
//		return *_useCount;
//	}
//
//	int subRef()
//	{
//		_mtx->lock();
//		--(*_useCount);
//		_mtx->unlock();
//		return *_useCount;
//	}
//
//	//*ptr  ptr->
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//	int useCount()
//	{
//		return *_useCount;
//	}
//
//private:
//	T* _ptr;
//	//int _useCount;
//	//static int _useCount;
//	int* _useCount;
//	mutex* _mtx;
//};
//mutex mtx;
//
//void Fun(SharedPtr<Date>& sp, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		//����ָ�뱾�����̰߳�ȫ�����ǹ������Դ��һ���̰߳�ȫ��
//		//��Ҫ��Դ��ʹ���߱�֤�����̰߳�ȫ
//		SharedPtr<Date> spcopy(sp);
//		mtx.lock();
//		sp->_year++;
//		mtx.unlock();
//	}
//		
//}
//
//void FunLib(const shared_ptr<Date>& sp, int n)
//{
//	for (int i = 0; i < n; i++)
//		shared_ptr<Date> spcopy(sp);
//}


//int main()
//{
//	//Date* pd = new Date;
//	SharedPtr<Date> sp(new Date);
//	/*SharedPtr<Date> spcopy(sp);
//	SharedPtr<Date> cpcopy2(sp);
//	SharedPtr<Date> sp2(new Date);
//	sp2 = sp;*/
//	int n = 100000;
//	thread t1(Fun, sp, n);
//	thread t2(Fun, sp, n);
//	t1.join();
//	t2.join();
//	cout << sp.useCount() << endl;
//	return 0;
//}

//int main()
//{
//	//Date* pd = new Date;
//	//shared_ptr<Date> sp(new Date);
//	SharedPtr<Date> sp(new Date);
//	//SharedPtr<Date> spcopy(new Date);
//	/*SharedPtr<Date> cpcopy2(sp);
//	SharedPtr<Date> sp2(new Date);
//	sp2 = sp;*/
//	int n = 10000;
//	thread t1(Fun, sp, n);
//	thread t2(Fun, sp, n);
//	t1.join();
//	t2.join();
//	cout << sp.useCount() << endl;
//	cout << sp->_year << endl;
//	return 0;
//}

//struct ListNode
//{
//	int _data;
//	shared_ptr<ListNode> _prev;
//	shared_ptr<ListNode> _next;
//	~ListNode(){ cout << "~ListNode()" << endl; }
//};

//struct ListNode
//{
//	int _data;
//	weak_ptr<ListNode> _prev;
//	weak_ptr<ListNode> _next;
//	~ListNode(){ cout << "~ListNode()" << endl; }
//};
//
//int main()
//{
//	//weak_ptr<ListNode> node0(new ListNode);
//	shared_ptr<ListNode> node1(new ListNode);
//	shared_ptr<ListNode> node2(new ListNode);
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//
//	node1->_next = node2;
//	node2->_prev = node1;
//	
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//	return 0;
//}

//template <class T>
//class Free
//{
//public:
//	void operator()(T* ptr)
//	{
//		free(ptr);
//		ptr = nullptr;
//	}
//};
//
//template <class T>
//class DeleteArray
//{
//public:
//	void operator()(T* ptr)
//	{
//		delete[] ptr;
//		ptr = nullptr;
//	}
//};
//
//int main()
//{
//
//	Free<Date> Del1;
//	DeleteArray<Date> DelArray;
//	shared_ptr<Date> sp(new Date);  // delete 
//	shared_ptr<Date> sp2((Date*)malloc(sizeof(Date)), Del1); // free
//	shared_ptr<Date> sp3(new Date[10], DelArray);  // delete[]
//
//	return 0;
//
//}

mutex mtx;
//RAII: ���ö�����������ڿ��ƽ�����������
template <class MTX>
class LockGurad
{
public:
	LockGurad(MTX& mtx)
		:_mtx(mtx)
	{
		_mtx.lock();
	}

	LockGurad(const LockGurad<MTX>& lg) = delete;

	~LockGurad()
	{
		_mtx.unlock();
	}
private:
	MTX& _mtx;
};

void fun()
{
	try{
		//mtx.lock();
		//vector<int> v;
		//v.at(10) = 10;  // �쳣����ת
		LockGurad<mutex> lg(mtx);
		int i;
		cin >> i;
		if (i > 100)
			return;

		//mtx.unlock();
		cout << "cin finised" << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	cout << "exception dealed" << endl;
}



//int main()
//{
//	thread t1(fun);
//	thread t2(fun);
//	t1.join();
//	t2.join();
//	return 0;
//}
int n = 0;
void Func()
{
	for (size_t i = 0; i < 10000000; ++i)
	{
		//LockGurad<mutex> lock(mtx);
		++n;
	}
}

int main()
{
	int begin = clock();
	thread t1(Func);
	thread t2(Func);
	t1.join();
	t2.join();
	int end = clock();
	cout << n << endl;
	cout << "cost time:" << end - begin << endl;
	return 0;
}