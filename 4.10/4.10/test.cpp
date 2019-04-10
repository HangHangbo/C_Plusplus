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


template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};
template<>
class Data<int, char>
{
public:
	Data() { cout << "Data<int, char>" << endl; }
private:
	int _d1;
	char _d2;
};
void TestVector()
{
	Data<int, int> d1;
	Data<int, char> d2;
}