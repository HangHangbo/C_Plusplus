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

//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base" << endl;
//	}
//private:
//	int b = 1;
//};
//class Derive :public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive" << endl;
//	}
//private:
//	int d = 2;
//};
//int a = 0;
//static int b = 0;
//int main()
//{
//	Base b;
//	Derive d;
//	char *q = "asd";
//	cout << (int*)(*(int*)&b) << endl;
//	printf("%p\n", &Base::Func1);
//	printf("%p\n", &a);
//	printf("%p\n", &b);
//	printf("%p\n", q);
//	system("pause");
//	return 0;
//}

class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1;
};
class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2;
};
class Derive : public Base1, public Base2 {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};
//����һ������ָ�룬��ʾһ�෵��ֵΪvoid����������Ϊ0�ĺ�����
typedef void(*VFPTR)();
void PrintfVF(VFPTR vfpt[])
{
	printf("���%p", vfpt);
	//���Ϊnullptr
	while (*vfpt != nullptr)
	{
		VFPTR vf = *vfpt;
		printf("0x%p-->", vf);
		vf();
		cout << endl;
		++vfpt;
	}
}
int main()
{
	Base1 b;
	Derive d;
	return 0;
}