#include <iostream>

using namespace std;

//class A
//{
//public:
//	virtual void f(){}
//};
//class B :public A
//{
//};
//void fun(A *pa)
//{
//	//dynamic_cast�����Ƿ�ת���ɹ����ܳɹ���ת���������򷵻�
//	B* pb1 = static_cast<B*>(pa);
//	B* pb2 = dynamic_cast<B*>(pa);
//
//	cout << "pb1" <<"->"<< pb1 << endl;
//	cout << "pb2" <<"->"<<pb2 << endl;
//}
//int main()
//{
//	A a;
//	B b;
//	fun(&a);
//	fun(&b);
//	system("pause");
//	return 0;
//}
class A
{
public:
	explicit A(int a)
	{
		cout << "A(int a)" << endl;
	}
	A(const A& a)
	{
		cout << "A(const A& a)" << endl;
	}
private:
	int _a;
};
int main()
{
	A a1(1);
	//��ʽת��->A tmp(1);A a2(tmp);
	A a2 = 1;
	return 0;
}