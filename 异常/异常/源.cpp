#include<iostream>

using namespace std;

//class A
//{};
//
//int fun()
//{
//	throw "Error";
//	int a = 10;
//	throw a;
//	throw A();
//}
//
//int main()
//{
//	try{
//		fun();
//	}
//	catch ()
//	{
//	}
//	catch ()
//	{
//	}
//	return 0;
//}
//double Division(int a, int b)
//{
//	// ��b == 0ʱ�׳��쳣
//	if (b == 0)
//		throw "Division by zero condition!";
//	else
//		return ((double)a / (double)b);
//}
//// ��ѡ�еĴ�������ǵ���������ö�������ƥ�������׳��쳣λ���������һ����
//void test()
//{
//	double a, b;
//	cin >> a >> b;
//	try{
//		Division(a, b);
//	}
//	//�쳣��ͨ���׳�����������ģ�
//	//�ö�������;�����Ӧ�ü����ĸ�catch�Ĵ�����롣
//	catch (const double a)
//	{
//		cout << a << endl;
//	}
//	catch (const char c)
//	{
//		cout << c << endl;
//	}
//	//��test��catch��ȡ���ַ������͵��쳣��ע��ʱ���᷵����һ������ջ֡�������������͵�catch����û�еĻ��������ظ���һ����ջ֡���ң�
//	/*catch (const char *str)
//	{
//		cout << str << endl;
//	}*/
//}
//int main()
//{
//
//	try{
//		test();
//	}
//	catch (const double a)
//	{
//		cout << a << endl;
//	}
//	catch (const char c)
//	{
//		cout << c << endl;
//	}
//	catch (const char *str)
//	{
//		cout << str << endl;
//	}
//	catch (...) //����catch�������͵��쳣
//	{
//		cout << "Unkown Error" << endl;
//	}
//	system("pause");
//	return 0;
//}
//double Division(int a, int b)
//{
//	// ��b == 0ʱ�׳��쳣
//	if (b == 0)
//	{
//		throw "Division by zero condition!";
//	}
//	return (double)a / (double)b;
//}
//void Func()
//{
//	// ������Կ������������0�����׳��쳣�����������arrayû�еõ��ͷš�
//	// �������ﲶ���쳣�󲢲������쳣���쳣���ǽ������洦�����ﲶ������
//	// �����׳�ȥ��
//	int* array = new int[10];
//	try {
//		int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << endl;
//	}
//	catch (...)//��Division�׳��쳣ʱ��catch�쳣���ͷ�û�������ü��ͷŵĿռ����׳��쳣
//	{
//		cout << "delete []" << array << endl;
//		delete[] array;
//		throw;
//	}
//	// ...
//	cout << "delete []" << array << endl;
//	delete[] array;
//}
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	return 0;
//}
#include<vector>
int main()
{
	try{
		vector<int> v;
		//v.reserve(1000000000);//bad allocation
		v.at(100)=10;
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
	catch (...)//��ֹ�������
	{
		cout << "Unknown Error" << endl;
	}
	system("pause");
	return 0;
}