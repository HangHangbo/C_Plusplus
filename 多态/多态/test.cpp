#include<iostream>

using namespace std;

//class Person {
//public:
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//class Student : public Person {
//public:
//	virtual ~Student() { cout << "~Student()" << endl; }
//};
//// ֻ��������Student������������д��Person�����������������delete��������������������ܹ��ɶ�
////̬�����ܱ�֤p1��p2ָ��Ķ�����ȷ�ĵ�������������
//int main()
//{
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//	delete p1;
//	delete p2;
//	return 0;
//}
//class Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//};
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
//};
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//int main()
//{
//	Person ps;
//	Student st;
//
//	Func(ps);
//	Func(st);
//	return 0;
//}


////Э��
//class A{};
//class B : public A {};
//class Person {
//public:
//	virtual A* f() { return new A; }
//};
//class Student : public Person {
//public:
//	virtual B* f() { return new B; }
//};

class Base
{
public:
	virtual void Func1()
	{
		cout << "Base" << endl;
	}
private:
	int b = 1;
};
class Derive :public Base
{
public:
	virtual void Func1()
	{
		cout << "Derive" << endl;
	}
private:
	int d = 2;
};
int a = 0;
static int b = 0;
int main()
{
	Base b;
	Derive d;
	char *q = "asd";
	cout << (int*)(*(int*)&b) << endl;
	printf("%p\n", &Base::Func1);
	printf("%p\n", &a);
	printf("%p\n", &b);
	printf("%p\n", q);
	system("pause");
	return 0;
}