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
//	string _name = "peter"; // ����
//	int _age = 18; // ����
//};
//// �̳к����Person�ĳ�Ա����Ա����+��Ա�����������������һ���֡��������ֳ���Student��
////Teacher������Person�ĳ�Ա����������ʹ�ü��Ӵ��ڲ鿴Student��Teacher���󣬿��Կ��������ĸ��á�����
////Print���Կ�����Ա�����ĸ��á�
//class Student : public Person
//{
//protected:
//	int _stuid; // ѧ��
//};
//class Teacher : public Person
//{
//protected:
//	int _jobid; // ����
//};
//int main()
//{
//	Student s;
//	Teacher t;
//	s.Print();
//	t.Print();
//	system("pause");
//	return 0;
//}//// ʵ����ʾ���ּ̳й�ϵ�»����Ա�ĸ����ͳ�Ա���ʹ�ϵ�ı仯 
//class Person
//{
//public:
//	void Print()
//	{
//		cout << _name << endl;
//	}
//protected:
//	string _name; // ����
//private:
//	int _age; // ����
//};
////class Student : protected Person
////class Student : private Person
//class Student : public Person
//{
//protected:
//	int _stunum; // ѧ��
//};

//// Student��_num��Person��_num�������ع�ϵ�����Կ�������������Ȼ���ܣ����Ƿǳ����׻���
//class Person
//{
//protected:
//	string _name = "С����"; // ����
//	int _num = 111; // ���֤��
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " ����:" << _name << endl;
//		cout << " ���֤��:" << Person::_num << endl;
//		cout << " ѧ��:" << _num << endl;
//	}
//protected:
//	int _num = 999; // ѧ��
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

// C++98�й��캯��˽�л����������е���������Ĺ��캯�������޷��̳�
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