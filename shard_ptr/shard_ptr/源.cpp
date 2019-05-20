#include <iostream>
#include <thread>
#include <memory>
#include <mutex>
using namespace std;
class Date
{
public:
	Date() { cout << "Date()" << endl; }
	~Date(){ cout << "~Date()" << endl; }
	int _year;
	int _month;
	int _day;
};
template <class T>
class SharedPtr
{
public:
	//构造函数在第一申请资源后调用
	//sharedPtr<T> sp(new T)
	SharedPtr(T* ptr)
		:_ptr(ptr)
		,_useCount(new int(1))
		,_mtx(new mutex）
	{}

	SharedPtr(const SharedPtr<T>& sp)
		:_ptr(sp._ptr)
		, _useCount(sp._useCount)
		, _mtx(sp._mtx)
	{
		++(*_useCount);
	}
	SharedPtr<T> &operator=(const SharedPtr<T>&sp)
	{
		//两个智能指针管理同一片空间的情况，不需要进行赋值。                                                                                                                                                                                          
		//if (this != &sp)
		if (_ptr!=sp._ptr)
		{
			if (--(*_useCount) == 0)
			{
				delete _ptr;
				delete _useCount;
				delete _mtx;
			}
			_ptr = sp._ptr;
			_useCount = sp._useCount;
			_mtx = sp._mtx;
			++(*_useCount);
		}
		return *this;
	}
	
	~SharedPtr()

	{
		//if (_ptr)
		if (--(*_useCount))
		{
			delete _ptr;
			delete _useCount;
			delete _mtx;
			_mtx = nullptr;
			_useCount = nullptr;
			_ptr = nullptr;
			cout << "~SharedPtr" << endl;
		}
	}
	T&operator *()
	{
		return *_ptr;
	}
	T*operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;
	int * _useCount;
	mutex* _mtx;
};

//int main()
//{
//	// shared_ptr通过引用计数支持智能指针对象的拷贝
//	shared_ptr<Date> sp(new Date);
//	shared_ptr<Date> copy(sp);
//	cout << "ref count:" << sp.use_count() << endl;
//	cout << "ref count:" << copy.use_count() << endl;
//	system("pause");
//	return 0;
//}
int main()
{
	//Date *pd = new Date;
	SharedPtr<Date>sp(new Date);
	SharedPtr<Date>spcopy1(sp);
	SharedPtr<Date>spcopy2(sp);
	SharedPtr<Date>sp2(new Date);
	sp2 = sp;
	//system("pause");
	return 0;

