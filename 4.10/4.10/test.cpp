#include<iostream>
using namespace std;

////类型模板空间
//template <class T1,class T2>
//T1 Add(const T1 &q, const T2& b)
//{
//	return a + b;
//}
//
////非类习惯模板，作为常量使用 
//template<class T,size_t N>
//	class Array
//	{
//	private:
//		T a[N];
//	};
//
//	template<class T>
//	bool isEqual(T& a, T&b)
//	{
//		return a--b;
//	}
//	int main()
//	{
//		int a = 10, b = 20;
//	}

//
//template<class T1, class T2>
//class Data
//{
//public:
//	Data() { cout << "Data<T1, T2>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};
//template<>
//class Data<int, char>
//{
//public:
//	Data() { cout << "Data<int, char>" << endl; }
//private:
//	int _d1;
//	char _d2;
//};
//void TestVector()
//{
//	Data<int, int> d1;
//	Data<int, char> d2;
//}
//
////两个参数特化为指针
//template <typename T1, typename T2>
//class Data <T1*, T2*>
//{
//public:
//	Data() { cout << "Data<T1*, T2*>" << endl; }
//
//private:
//	T1 _d1;
//	T2 _d2;
//};
////特化为引用
//template <typename T1, typename T2>
//class Data <T1&, T2&>
//{
//public:
//	Data(const T1& d1, const T2& d2)
//		: _d1(d1)
//		, _d2(d2)
//	{
//		cout << "Data<T1&, T2&>" << endl;
//	}
//
//private:
//	const T1 & _d1;
//	const T2 & _d2;
//};

//template <class T>
//void Copy(T* dest, const T* src, size_t sz, bool isPODtype)
//{
//	if (isPODtype)
//		memccpy(dest, src, sizeof(T)*sz);
//	else
//	{
//		for (int i = 0; i < sz; i++)
//		{
//			dst[i] = src[i];
//		}
//	}
//}
//bool IsPODType(const char* strType)
//{
//	const char* arrType[] = { "char", "short", "int", "long", "long long", "float",
//		"double", "long double" };
//	for (size_t i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
//	{
//		if (0 == strcmp(strType, arrType[i]))
//			return true;
//	}
//
//	return false;
//}
//template<class T>
//void Copy(T* dst, const T* src, size_t size)
//{
//	if (IsPODType(typeid(T).name()))
//		memcpy(dst, src, sizeof(T)*size);
//	else
//	{
//		for (size_t i = 0; i < size; ++i)
//			dst[i] = src[i];
//	}
//}// 代表内置类型
struct TrueType
{
	static bool Get()
	{
		return true;
	}
};
// 代表自定义类型
struct FalseType
{
	static bool Get()
	{
		return false;
	}
};
//                                                     
template <>
struct TypeTraits<int>
{
	typedef TrueType _isPodType;
};