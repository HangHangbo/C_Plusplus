#include <iostream>
using namespace std;


//�������麯�������Ϊ�����ࣺ���������࣬����ʵ����
//�����ࣺ�ӿڼ̳�
//class Car
//{
//public:
//	virtual void Drive() = 0;
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "����" << endl;
//	}
//};
//
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "�ÿ�" << endl;
//	}
//};
//
//int main()
//{
//	//Car c;
//	Benz b;
//	b.Drive();
//	BMW d;
//	d.Drive();
//	return 0;
//}

//class Car
//{
//public:
//	virtual void Drive() final {}
//};
//class Benz :public Car
//{
//public:
//	//virtual void Drive() { cout << "Benz-����" << endl; }
//};


class Car
{
public:
	virtual void Drive() = 0;
	virtual void drive() = 0;
};

// virtual  + override 
// ����Ϊoverride�ĺ���������д�����һ������
//class Benz :public Car
//{
//public:
//	virtual void drive() override { cout << "Benz-����" << endl; }
//};

//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Func1()" << endl;
//	}
//	virtual void Func3()
//	{
//		cout << "Func1()" << endl;
//	}
//private:
//	int _b = 1;
//};
//
//int main()
//{
//	Base b;
//	cout << sizeof(Base) << endl;
//	return 0;
//}

//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//	void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//private:
//	int _b = 1;
//};
//class Derive : public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//private:
//	int _d = 2;
//};
//
//int global = 10;  //���ݶ�
//int main()
//{
//	/*Base b;*/
//	Derive d;
//	int tmp = 2;  // ջ��
//
//	int* ptr = new int;  // ����
//
//	cout << "ջ��" << &tmp << endl;
//	cout << "�ѣ�" << ptr << endl;
//	cout << "���ݶΣ�" << &global << endl;
//	printf("����Σ� %p\n", &Base::Func3); 
//
//	printf("��� %p\n", *((int*)&d));
//
//	return 0;
//}

//class Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//	virtual void func2(){};
//};
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
//	virtual void func2(){};
//};
//void Func(Person& p)
//{
//	p.BuyTicket();
//	p.func2();
//}
//int main()
//{
//	Person Mike;
//	Func(Mike);
//	Student Johnson;
//	Func(Johnson);
//	return 0;
//}

//class Base {
//public:
//	virtual void func1() { cout << "Base::func1" << endl; }
//	virtual void func2() { cout << "Base::func2" << endl; }
//private:
//	int a;
//};
//class Derive :public Base {
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//	virtual void func4() { cout << "Derive::func4" << endl; }
//private:
//	int b;
//};
//����һ������ָ�룬 ��ʾһ�෵��ֵΪvoid,��������Ϊ0�ĺ���
typedef void(*VFPTR)();

void PrintVF(VFPTR vfpt[])
{
	printf("��� %p\n", vfpt);
	//�����nullptr
	while (*vfpt != nullptr)
	{
		VFPTR vf = *vfpt;
		printf("0x%p-->", vf);
		vf();
		//cout << endl;
		++vfpt;
	}
}

//int main()
//{
//	Base b;
//	Derive d;
//	PrintVF((VFPTR*)*(int*)&b);
//
//	PrintVF((VFPTR*)*(int*)&d);
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
//��������͸���ĸ�����ͬ�������Լ�������麯�����ڵ�һ��ֱ�Ӹ���������
class Derive : public Base1, public Base2 {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};

int main()
{
	Base1 b1;
	Base2 b2;
	Derive d;
	Base2* pb2 = &d;
	PrintVF((VFPTR*)*(int*)&b1);
	PrintVF((VFPTR*)*(int*)&b2);
	cout << "Derived: " << endl;
	PrintVF((VFPTR*)*(int*)&d);
	PrintVF((VFPTR*)*(int*)pb2);
	PrintVF((VFPTR*)*(int*)((char*)&d + sizeof(Base1)));
	cout << sizeof(Derive) << endl;

	return 0;
}
