#include <iostream>
#include <memory>
using namespace std;

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
//	T& operator*()
//	{
//		return *_ptr;
//	}
//	T* operator->()
//	{
//		return _ptr;
//	}
//private:
//	T* _ptr;
//};
//template<class T>
//class AutoPtr
//{
//public:
//	AutoPtr(T* ptr = NULL)
//		: _ptr(ptr)
//	{}
//
//	~AutoPtr()
//	{
//		if (_ptr)
//			delete _ptr;
//	}
//
//	// һ�������������ͽ�ap����Դת�Ƶ���ǰ�����У�Ȼ����ap������������Դ�Ͽ���ϵ��
//	// �����ͽ����һ��ռ䱻�������ʹ�ö���ɳ���������
//	AutoPtr(AutoPtr<T>& ap)
//		: _ptr(ap._ptr)
//	{
//		ap._ptr = NULL;
//	}
//
//	AutoPtr<T>& operator=(AutoPtr<T>& ap)
//	{
//		// ����Ƿ�Ϊ�Լ����Լ���ֵ
//		if (this != &ap)
//		{
//			// �ͷŵ�ǰ��������Դ
//			if (_ptr)
//				delete _ptr;
//
//			// ת��ap����Դ����ǰ������
//			_ptr = ap._ptr;
//			ap._ptr = NULL;
//		}
//
//		return *this;
//	}
//
//	T& operator*() { return *_ptr; }
//		T* operator->() { return _ptr; }
//private:
//	T* _ptr;
//};
//
////struct Date
////{
////	int _year = 1990;
////	int _month = 1;
////	int _day = 1;
////
////	~Date()
////	{
////		cout << "~Date "<< endl;
////	}
////};
////int main()
////{
////
////	//int *pa = new int(1);   //��������Դ�ٳ�ʼ��
////	//SmartPtr<int>sp(pa);
////	//*pa = 8;
////	SmartPtr<int>sp(new int(1));//��Դ�������ϳ�ʼ��
////	*sp = 10;
////
////	//Date *pd = new Date;
////	SmartPtr<Date> spd(new Date);
////	//pd->_day = 2;
////	spd->_day = 3;
////	system("pause");
////	return 0;
////}
//int main()
//{
//	auto_ptr<Date>ap(new Date);
//	auto_ptr<Date>ap2 = ap;
//	system("pause");
//	return 0;
//}









