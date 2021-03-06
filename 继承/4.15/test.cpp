#include<iostream>
#include<string>

using namespace std;
//
////class Person
////{
////public:
////	void Print()
////	{
////		cout << "name:" << _name << endl;
////		cout << "age:" << _age << endl;
////	}
////protected:
////	string _name = "peter"; // 姓名
////	int _age = 18; // 年龄
////};
////// 继承后父类的Person的成员（成员函数+成员变量）都会变成子类的一部分。这里体现出了Student和
//////Teacher复用了Person的成员。下面我们使用监视窗口查看Student和Teacher对象，可以看到变量的复用。调用
//////Print可以看到成员函数的复用。
////class Student : public Person
////{
////protected:
////	int _stuid; // 学号
////};
////class Teacher : public Person
////{
////protected:
////	int _jobid; // 工号
////};
////int main()
////{
////	Student s;
////	Teacher t;
////	s.Print();
////	t.Print();
////	system("pause");
////	return 0;
////}
////// 实例演示三种继承关系下基类成员的各类型成员访问关系的变化 
////class Person
////{
////public:
////	void Print()
////	{
////		cout << _name << endl;
////	}
////protected:
////	string _name; // 姓名
////private:
////	int _age; // 年龄
////};
//////class Student : protected Person
//////class Student : private Person
////class Student : public Person
////{
////protected:
////	int _stunum; // 学号
////};
//
////// Student的_num和Person的_num构成隐藏关系，可以看出这样代码虽然能跑，但是非常容易混淆
////class Person
////{
////protected:
////	string _name = "小李子"; // 姓名
////	int _num = 111; // 身份证号
////};
////class Student : public Person
////{
////public:
////	void Print()
////	{
////		cout << " 姓名:" << _name << endl;
////		cout << " 身份证号:" << Person::_num << endl;
////		cout << " 学号:" << _num << endl;
////	}
////protected:
////	int _num = 999; // 学号
////};
////void Test()
////{
////	Person p;
////	Student s;
////	s.Print();
////};
////int main()
////{
////	Test();
////	system("pause");
////	return 0;
////}
//
//// C++98中构造函数私有化，派生类中调不到基类的构造函数。则无法继承
///*class NonInherit
//{
//public:
//	static NonInherit GetInstance()
//	{
//		return NonInherit();
//	}
//private:
//	NonInherit()
//	{}
//};    */       
//
////class Base1 {
////public:
////	int _b1;
////};
////class Base2 {
////public:
////	int _b2;
////};
////class Derive : public Base1, public Base2 {
////public:
////	int _d;
////};
////int main()
////{
////	// A. p1 == p2 == p3
////	// B. p1 < p2 < p3
////	// C. p1 == p3 != p2
////	// D. p1 != p2 != p3
////	Derive d;
////	Base1* p1 = &d;
////	Base2* p2 = &d;
////	Derive* p3 = &d;
////	return 0;
////}

#include <iostream>
#include <string>
using namespace std;

//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//
//// Display --> Person
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	//cout << s._stuNum << endl;
//}
//void main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//}

//class Person
//{
//public:
//	Person() { ++_count; }
//protected:
//	string _name; // 姓名
//public:
//	static int _count; // 统计人的个数。
//};
//int Person::_count = 0;
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // 研究科目
//};
//void TestPerson()
//{
//	Student s1;
//	Student s2;
//	Student s3;
//	Graduate s4;
//	cout << " 人数 :" << Person::_count << endl;
//	//Student::_count = 0;
//	cout << " 人数 :" << Person::_count << endl;
//	cout << s1._count << endl;
//	cout << Student::_count << endl;
//	cout << "static address: " << endl;
//	cout << &Person::_count << endl;
//	cout << &s1._count << endl;
//	cout << &s2._count << endl;
//	cout << &s3._count << endl;
//	cout << &s4._count << endl;
//
//}
//
//int main()
//{
//	TestPerson();
//	return 0;
//}

//class Person
//{
//public:
//	string _name; // 姓名
//};
//class Student : virtual public Person
//{
//protected:
//	int _num; //学号
//};
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // 职工编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//void Test()
//{
//	// 这样会有二义性无法明确知道访问的是哪一个
//	// 数据冗余
//	Assistant a;
//	a.Student::_name = "peter";
//	a.Teacher::_name = "James";
//	//a._name = "ag";
//}
//
//
//int main()
//{
//	Test();
//	return 0;
//}

//class A
//{
//public:
//	int _a;
//};
//class B : virtual public A
////class B : virtual public A
//{
//public:
//	int _b;
//};
//
//class C : virtual public A
////class C : virtual public A
//{
//public:
//	int _c;
//};
//class D : public B, public C
//{
//public:
//	int _d;
//};
//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//	return 0;
//}

//class Base1 {
//public:
//	int _b1;
//};
//class Base2 {
//public:
//	int _b2;
//};
//class Derive : public Base1, public Base2 {
//public:
//	int _d;
//};
//int main()
//{
//	// A. p1 == p2 == p3
//	// B. p1 < p2 < p3
//	// C. p1 == p3 != p2
//	// D. p1 != p2 != p3
//	Derive d;
//	Base1* p1 = &d;
//	Base2* p2 = &d;
//	Derive* p3 = &d;
//	return 0;
//}

//多态前提： 继承
// 1.  调用函数的类型必须是指针或者引用
// 2.  被调用函数必须为虚函数，并且被重写（函数名，参数，返回值全部相同）
// 3.  函数重写: 协变： 返回值的类型可以是继承关系

//class A
//{};
//class B : public A
//{
//
//};
//
//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//};
//
//class S2 : public Student
//{
//public:
//	virtual void BuyTicket() { cout << "买票-免费" << endl; }
//};
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//
//void Func2(Student& p)
//{
//	p.BuyTicket();
//}
//
//int main()
//{
//	Person p;
//	Student s;
//	S2 s2;
//	/*p.BuyTicket();
//	s.BuyTicket();*/
//	//多态看实际指向的对象，调用对象对应类型的代码
//	//非多态看类型
//	Func(p);
//	Func(s);
//
//	Func2(s2);

//	return 0;
//}
class A
{
public:
	int a;
};
//class B :public A
class B :virtual public A
{
public :
	int b;
};
//class C :public A
class C :virtual public A
{
public:
	int c;
};
class D : public B, public C
{
public:
	int d;
};
int main()
{
	D d;
	cout << sizeof(d) << endl;
	d.B::a = 1;
	d.C::a = 2;
	d.b = 3;
	d.c = 4;
	d.d = 5;
	system("pause");
	return 0;
}