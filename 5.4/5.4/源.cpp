#include<iostream>

using namespace std;
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
//int main()
//{
//	Base b;
//	Derive d;
//	system("pause");
//	return 0;
//}
class Base {
public:
	virtual void func1() { cout << "Base::func1" << endl; }
	virtual void func2() { cout << "Base::func2" << endl; }
private:
	int a;
};

class Derive : public Base{
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int b;
};
typedef void(*VFPTR) ();      //����һ��void�͵ĺ���ָ�룬�����һ��ָ�����飬
void PrintVTable(VFPTR vTable[])
{
	printf("���ָ�룺%p\n", vTable);  //��ӡ���ָ��ĵ�ַ
	for (size_t i = 0; vTable[i] != nullptr; i++)
	{
		printf("vTable[%d]:%p->", i, vTable[i]);  //��ӡ���ָ�������ݣ����ָ��������nullptr����
		VFPTR vf = vTable[i];
		vf();
	}
}
int main()
{
	Base b;
	PrintVTable((VFPTR*)(*(int*)&b));
	Derive d;
	PrintVTable((VFPTR*)(*(int*)&d));
	system("pause");
	return 0;

}