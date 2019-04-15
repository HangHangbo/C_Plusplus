#include<iostream>
#include<string>

using namespace std;
//
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "peter"; // 姓名
//	int _age = 18; // 年龄
//};
//// 继承后父类的Person的成员（成员函数+成员变量）都会变成子类的一部分。这里体现出了Student和
////Teacher复用了Person的成员。下面我们使用监视窗口查看Student和Teacher对象，可以看到变量的复用。调用
////Print可以看到成员函数的复用。
//class Student : public Person
//{
//protected:
//	int _stuid; // 学号
//};
//class Teacher : public Person
//{
//protected:
//	int _jobid; // 工号
//};
//int main()
//{
//	Student s;
//	Teacher t;
//	s.Print();
//	t.Print();
//	system("pause");
//	return 0;
//}//// 实例演示三种继承关系下基类成员的各类型成员访问关系的变化 
//class Person
//{
//public:
//	void Print()
//	{
//		cout << _name << endl;
//	}
//protected:
//	string _name; // 姓名
//private:
//	int _age; // 年龄
//};
////class Student : protected Person
////class Student : private Person
//class Student : public Person
//{
//protected:
//	int _stunum; // 学号
//};

//// Student的_num和Person的_num构成隐藏关系，可以看出这样代码虽然能跑，但是非常容易混淆
//class Person
//{
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; // 身份证号
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " 姓名:" << _name << endl;
//		cout << " 身份证号:" << Person::_num << endl;
//		cout << " 学号:" << _num << endl;
//	}
//protected:
//	int _num = 999; // 学号
//};
//void Test()
//{
//	Person p;
//	Student s;
//	s.Print();
//};
//int main()
//{
//	Test();
//	system("pause");
//	return 0;
//}

// C++98中构造函数私有化，派生类中调不到基类的构造函数。则无法继承
class NonInherit
{
public:
	static NonInherit GetInstance()
	{
		return NonInherit();
	}
private:
	NonInherit()
	{}
};           