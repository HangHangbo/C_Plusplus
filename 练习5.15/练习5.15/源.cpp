#include <iostream>
using namespace std;


//包含纯虚函数的类称为抽象类：不完整的类，不能实例化
//抽象类：接口继承
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
//		cout << "舒适" << endl;
//	}
//};
//
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "好开" << endl;
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
//	//virtual void Drive() { cout << "Benz-舒适" << endl; }
//};


class Car
{
public:
	virtual void Drive() = 0;
	virtual void drive() = 0;
};

// virtual  + override 
// 声明为override的函数必须重写父类的一个函数
//class Benz :public Car
//{
//public:
//	virtual void drive() override { cout << "Benz-舒适" << endl; }
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
//int global = 10;  //数据段
//int main()
//{
//	/*Base b;*/
//	Derive d;
//	int tmp = 2;  // 栈上
//
//	int* ptr = new int;  // 堆上
//
//	cout << "栈：" << &tmp << endl;
//	cout << "堆：" << ptr << endl;
//	cout << "数据段：" << &global << endl;
//	printf("代码段： %p\n", &Base::Func3); 
//
//	printf("虚表： %p\n", *((int*)&d));
//
//	return 0;
//}

//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//	virtual void func2(){};
//};
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
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
//定义一个函数指针， 表示一类返回值为void,参数个数为0的函数
typedef void(*VFPTR)();

void PrintVF(VFPTR vfpt[])
{
	printf("虚表： %p\n", vfpt);
	//虚表以nullptr
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
//子类的虚表和父类的个数相同，子类自己定义的虚函数放在第一个直接父类的虚表中
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
