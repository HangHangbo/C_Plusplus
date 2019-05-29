#include <iostream>
#include <vector>
//using namespace std;
//int main()
//{
//	int num[4] = { 0 };
//	for (int i = 0; i < 4; i++)
//	{
//		cin >> num[i];
//	}
//	int A, B, C;
//	A = (num[0] + num[2]) / 2;
//	B = (num[1] + num[3]) / 2;
//	C = B - num[1];
//	if ((num[0]==A-B) && (num[1]==B-C) && (num[2]==A+B)&&(num[3]==B+C))
//	{
//		cout << A << ' ' << B << ' ' << C << endl;
//	}
//	else
//	{
//		cout << "No" << endl;
//	}
//	system("pause");
//	return 0;
//}
//class A
//{
//	friend long fun(A s)
//	{
//		if (s.x < 3){
//			return 1;
//		}
//		return s.x + fun(A(s.x - 1));
//	}
//public:
//	A(long a)
//	{
//		x = a--;
//		cout << x << endl;
//	}
//private:
//	long x;
//};
//int main()
//{
//	int sum = 0;
//	for (int i = 0; i < 5; i++)
//	{
//		sum += fun(A(i));
//	}
//	cout << sum;
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int i = 3;
//	int a = i++;
//	return 0;
//}
//int main()
//{
//	int i = 10;
//	int j = 1;
//	const int *p1;//(1)
//	int const *p2 = &i; //(2)
//	p2 = &j;//(3)
//	int *const p3 = &i;//(4)
//	*p3 = 20;//(5)
//	*p2 = 30;//(6)
//	p3 = &j;//(7)
//	return 0;
//}
class A
{
public:
	A() :m_iVal(0)
	{ 
		test();
	}	// 0
	virtual void func() { 
		std::cout << m_iVal; 
	}
	void test(){ func(); }
public:
	int m_iVal;
};
class B : public A
{
public:
	B(){ 
		test();
	}
	virtual void func()
	{
		++m_iVal;
		std::cout << m_iVal;     //1
	}
};
int main(int argc, char* argv[])
{
	A*p = new B;
	p->test();
	return 0;
}