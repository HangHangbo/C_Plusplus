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
//	// 当b == 0时抛出异常
//	if (b == 0)
//		throw "Division by zero condition!";
//	else
//		return ((double)a / (double)b);
//}
//// 被选中的处理代码是调用链中与该对象类型匹配且离抛出异常位置最近的那一个。
//void test()
//{
//	double a, b;
//	cin >> a >> b;
//	try{
//		Division(a, b);
//	}
//	//异常是通过抛出对象而引发的，
//	//该对象的类型决定了应该激活哪个catch的处理代码。
//	catch (const double a)
//	{
//		cout << a << endl;
//	}
//	catch (const char c)
//	{
//		cout << c << endl;
//	}
//	//当test中catch获取的字符串类型的异常被注释时，会返回上一个函数栈帧里继续找这个类型的catch捕获，没有的话继续返回更上一级的栈帧中找，
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
//	catch (...) //可以catch任意类型的异常
//	{
//		cout << "Unkown Error" << endl;
//	}
//	system("pause");
//	return 0;
//}
//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//	{
//		throw "Division by zero condition!";
//	}
//	return (double)a / (double)b;
//}
//void Func()
//{
//	// 这里可以看到如果发生除0错误抛出异常，另外下面的array没有得到释放。
//	// 所以这里捕获异常后并不处理异常，异常还是交给外面处理，这里捕获了再
//	// 重新抛出去。
//	int* array = new int[10];
//	try {
//		int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << endl;
//	}
//	catch (...)//当Division抛出异常时先catch异常，释放没来的来得及释放的空间再抛出异常
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
	catch (...)//防止代码崩掉
	{
		cout << "Unknown Error" << endl;
	}
	system("pause");
	return 0;
}