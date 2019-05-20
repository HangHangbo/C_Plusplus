#include <iostream>
#include <memory>
using namespace std;

template <class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{}

	~SmartPtr()
	{
		if (_ptr)
		{
			delete _ptr;
			_ptr = nullptr;
			//cout << "delete _ptr" << endl;
		}
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;
};
template<class T>
class AutoPtr
{
public:
	AutoPtr(T* ptr = NULL)
		: _ptr(ptr)
	{}

	~AutoPtr()
	{
		if (_ptr)
			delete _ptr;
	}

	// 一旦发生拷贝，就将ap中资源转移到当前对象中，然后另ap与其所管理资源断开联系，
	// 这样就解决了一块空间被多个对象使用而造成程序奔溃问题
	AutoPtr(AutoPtr<T>& ap)
		: _ptr(ap._ptr)
	{
		ap._ptr = NULL;
	}

	AutoPtr<T>& operator=(AutoPtr<T>& ap)
	{
		// 检测是否为自己给自己赋值
		if (this != &ap)
		{
			// 释放当前对象中资源
			if (_ptr)
				delete _ptr;

			// 转移ap中资源到当前对象中
			_ptr = ap._ptr;
			ap._ptr = NULL;
		}

		return *this;
	}

	T& operator*() { return *_ptr; }
		T* operator->() { return _ptr; }
private:
	T* _ptr;
};

//struct Date
//{
//	int _year = 1990;
//	int _month = 1;
//	int _day = 1;
//
//	~Date()
//	{
//		cout << "~Date "<< endl;
//	}
//};
//int main()
//{
//
//	//int *pa = new int(1);   //先申请资源再初始化
//	//SmartPtr<int>sp(pa);
//	//*pa = 8;
//	SmartPtr<int>sp(new int(1));//资源申请马上初始化
//	*sp = 10;
//
//	//Date *pd = new Date;
//	SmartPtr<Date> spd(new Date);
//	//pd->_day = 2;
//	spd->_day = 3;
//	system("pause");
//	return 0;
//}
int main()
{
	auto_ptr<Date>ap(new Date);
	auto_ptr<Date>ap2 = ap;
	system("pause");
	return 0;
}