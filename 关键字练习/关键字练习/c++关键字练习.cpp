//#include
//using namespace std;
//	//命名空间
//namespace N1 //N1为命名空间的名称
//{
//	//命名空间中的内容既可以定义变量，也可以定义函数
//	int a=10;
//	int Add(int left, int right){
//	return left + right;
//	}
//}
////命名空间的嵌套
//namespace N2
//{
//	int b=20;
//	int c;
//	int Add(int left, int right){
//	return left + right;
//	}
//	namespace N3
//	{
//	int d;
//	int e;
//	int sub(int left, int right){
//	return left - right;
//	}
//	}
//}
//namespace N1 //同一工程中允许存在多个相同名称的命名空间，编译器最后会合并成同一命名空间中
//{
//	int Mul(int left, int right){
//	return left*right;
//	}
//}
////使用using namespace 命名空间引用
//using namespace N2;
////命名空间的使用
//int main()
//{
//	//printf("%d\n", a);错误示范编译器无法识别a
//	printf("%d\n", N1::a);
//	printf("%d\n", b);
//	system(“pause”);
//	return 0;
//}
//c++中的输入(cin标准输出)&输出(cont标准输出)
//使用cout和cin时，必须包含头文件以及std标准命名空间

#include<iostream>
using namespace std;

//int main()
//{
//	int a;
//	double b;
//	char c;
//	
//	cin >> a;
//	cin >> b >> c;
//
//	cout << a << endl;
//	cout << b << " " << endl;
//
//	/cout << “hello world” << endl;/
//
//	system(“pause”);
//	return 0;
//}

//缺省函数
//缺省函数是声明或者定义函数时为函数指定一个默认值，在调用该函数时，如果没有指定实参则采用该默认值，否则使用函数的指定实参。
//void TestFunc(int a = 10)
//{
//	cout << a << endl;
//}
//void main()
//{
//	TestFunc();//没有传参数，使用参数的默认值
//	TestFunc(20);//传参时，使用指定的实参
//	system(“pause”);
//}

////全缺省参数
//void TestFunc(int a = 10, int b = 20, int c = 30){
//	cout << “a=” << a<< endl;
//	cout << “b=” <<b<< endl;
//	cout << “c=” << c<< endl;
//	system(“pause”);
//
//}
////半缺省函数
//void TestFunc(int a, int b = 20, int c = 30){
//	cout << “a=” << a << endl;
//	cout << “b=” << b << endl;
//	cout << “c=” << c << endl;
//	system(“pause”);
//
//}
//注意
//1）缺省函数参数必须从右往左依次来给，不能有间隔
//2)缺省函数不能在函数声明和定义中同时出现，如果生命与定义位置同时出现，恰巧两个位置提供的值不同，编译器就无法确定到底哪个是缺省值,如下
//a.h
//void TestFunc(int a = 10);
////a.c
//void TestFunc(int a = 20){
//
//}
//3)缺省值必须是常量或者全局变量
//4)c语言不支持

//////函数重载（一个词可以有多重含义，可以通过上下文来判断该词的真是含义，即该词被重载了）
//////函数重载是函数的一种特殊情况，c++允许在同一作用域中声明几个功能类似的同名函数，这些同名函数的形参列表（参数个数或者类型或者顺序）必须不同，常用来实现数据类型不同的问题
//int Add(int left, int right){
//	return left + right;
//}
//double Add(double left, double right){
//	return left + right;
//}
//long Add(long left, long right){
//	return left + right;
//}
//
////int main()
////{
////	cout << Add(10,20) << endl;
////	cout << Add(10.0,20.0) << endl;
////	cout << Add(10L,20L) << endl;
////	system(“pause”);
////}
//
////extern"c"
////有时候c++工程中可能需要将某些函数按照c语言的风格来编译，在函数前加external“c”，就是告诉编译器将该函数有c语言规则来编译
//extern “C” int Add(int left, int right);
//int main(){
//	Add(1, 2);
//	return 0;
//}

//引用：引用不是定义新的变量，只是给已存在的变量取了一个别名，编译器不会引用变量开辟内存空间，它和它引用的变量共同用同一块空间
//类型&引用变量名（对象名）=引用实体
//void TestRef()
//{
//	int a = 10;
//	int &ra = a;//定义引用类型
//
//	printf("%p\n", &a);
//	printf("%p\n", &ra);
//	system(“pause”);
//
//}
//void main()
//{
//	TestRef();
//}

//引用在定义时必须初始化
//一个变量可以有多个引用
//引用一旦引用一个实体，再不能引用其他实体
//void TestRef()
//{
//	int a = 10;
//	//int &ra;该语句编译时会出错
//	int&ra = a;
//	int&rra = a;
//	printf("%p %p %p ", &a, &ra, &rra);
//
//}
//void main()
//{
//	TestRef();
//	system(“pasue”);
//}
//常引用
//void TestConstRef()
//{
//	const int a = 10;
//	const int&ra = a;
//	//int &ra=a;编译时会出错，a为常量
//}
////应用使用的场景
////1)做参数
//void Swap(int& left, int& right){
//	int temp = left;
//	left = right;
//	right = temp;
//}
////2)做返回值
//int& TestRefReturn(int &a){
//	a += 10;
//	return a;
//}
//int &Add(int a, int b){
//	int c = a + b;
//	return c;
//}
//
//int main()
//{
//	int&ret = Add(1, 2);
//	Add(3, 4);
//	cout << “Add(1,2)=” << ret << endl;//7
//	system(“pause”);
//	return 0;
//}

//引用和指针的区别
//语法概念上引用就是一个别名，没有独立空间，其和引用实体共用同一块空间

//int main()
//{
//	int a = 10;
//	int &ra = a;
//
//	cout << &a << endl;
//	cout << &ra << endl;
//	system(“pause”);
//
//	return 0;
//}

//int TestAuto()
//{
//	return 10;
//}
//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = ‘a’;
//	auto d = TestAuto();
//
//	cout << typeid(b).name() << endl;
//
//	cout << typeid©.name() << endl;
//	cout << typeid(d).name() << endl;//typeid返回类型的文字信息
//	system(“pause”);
//	return 0;
//}

//auto与指针和引用结合在一起使用
//用auto声明指针类型时，用auto和auto没有任何区别，但是auto声明的引用类型时必须加&
//int main()
//{
//	int x = 10;
//	auto a= &x;
//	auto b = &x;
//	auto&c = x;
//
//	cout << typeid(a).name() << endl;//int *
//	cout << typeid(b).name() << endl;//int *
//	cout << typeid©.name() << endl;//int
//	system(“pause”);
//	return 0;
//}

////在同一行用auto定义多个变量时，这些变量必须是相同类型的，否则编译器会报错，
////因为编译器只对第一个类型进行推导，然后用定义出来的类型定义其他变量
////auto不能推导的场景
////void TestAuto(auto a){}
////auto不能直接用来声明数组
//void TestAuto()
//{
//	int a[] = { 1, 2, 3, 4 };
//	auto b[] = { 5, 8 };
//}

//范围for的语法
//遍历一个数组
void TestFor()
{
	int array[] = { 1, 2, 3, 4 };
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
		array[i] *= 2;
	for (int *p = array; p < array + sizeof(array) / sizeof(array[0]); ++p)
		cout << *p << endl;
	for (auto& e : array)
		e *= 2;
	for (auto e : array)
		cout << e << " " << endl;
	system("pause");

}
int main()
{
	TestFor();
	return 0;
}
//for循环后的括号由冒号“：”分为两部分，第一部分是范围内用于迭代的变量，第二部分则表达被迭代的范围。
//for循环迭代的范围必须是确定的
//对数组而言，就是数组的第一个元素到最后一个元素的范围
//迭代的对象要实现++和–的操作