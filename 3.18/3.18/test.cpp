#include<iostream>
using namespace std;
#include<assert.h>

////饿汉模式
//class Singleton{
//public:
//	static Singleton * getInstance()
//	{
//		return &_sin;
//	}
//
//private:
//	Singleton(){}
//	/*防拷贝
//	Singleton(const Singleton&s);*/
//	Singleton(const Singleton&s) = delete;
//	static Singleton _sin;
//
//};
//Singleton Singleton::_sin;


//int main()
//{
//	Singleton *ps = Singleton::getInstance();
//	//Singleton s(*ps);
//
//	Singleton *ps2 = Singleton::getInstance();
//	return 0;
//}
//
////懒汉模式
//#include<thread><pthread.h>
////互斥锁
//#include<mutex>
//class Singleton
//{
//public:
//	 static Singleton*getInstance()
//	{
//		 if (_ps == nullptr){
//			 _mtx.lock();
//			 if (_ps == nullptr){
//				 _ps = new Singleton;
//			 }
//			 _mtx.unlock();
//		 }
//		return _ps;
//	}
//	 //~Singleton()
//	 //{
//		// if (_ps){
//		//	 //无线递归，导致栈溢出
//		//	 delete _ps;
//		//	 _ps = nullptr;
//		// }
//	 //}
//	 ~Singleton()
//	 {
//		 cout << "~Singletn()" << endl;
//	 }
//	 class GC{
//	 public:
//		 ~GC(){
//			 if (_ps){
//				 delete _ps;
//				 _ps = nullptr;
//			 }
//		 }
//	 };
//private:
//	//私有化构造函数保证全局唯一
//	Singleton(){}
//	Singleton(const Singleton&s);
//	static Singleton*_ps;
//	//保证这吧锁全局唯一，将它定义成静态的成员变量
//	static mutex _mtx;
//	static GC _gc;
//};
//Singleton * Singleton::_ps = nullptr;
//mutex Singleton::_mtx;
//Singleton::GC Singleton::_gc;
//
//void fun(){
//	for (int i = 0; i < 10; i++)
//	{
//		cout << i << endl;
//	}
//}
//void testSing()
//{
//	cout << Singleton::getInstance() << endl;
//}
//int main()
//{
//	Singleton *ps = Singleton::getInstance();
//	Singleton *ps2 = Singleton::getInstance();
//	/*int i = 0;
//	i++;*/
//	thread t1(testSing);
//	thread t2(testSing);
//	 
//	t1.join();
//	t2.join();
//	system("pause");
//	return 0;
//}


//template <typename T>
//void Swap(T& a, T& b)
//{
//	T tmp = a;
//	a = b;
//	b = tmp;
//}
//
//
//int main()
//{
//	int a = 1, b = 2;
//	double c = 2.0, d = 3.0;
//	Swap(c, d);
//	Swap(a, b);
//
//	return 0;
//}


////typedef int VDataType;
//template<class T>
//class Vector{
//public:
//	Vector()
//		:_a(nullptr)
//		, _capacity(0)
//		, _size(0)
//	{}
//	~Vector(){
//		if (_a){
//			delete _a;
//			_size = _capacity = 0;
//		}
//	}
//	void pushBack(const T& x){
//		if (_size == _capacity){
//			size_t newcapacity = _capacity==0 ? 3 : _capacity*2;
//			T* tmp = new T[newcapacity];
//			if (_a){
//				memcpy(tmp, _a, sizeof(T)*_capacity);
//				delete[] _a;
//				_a = tmp;
//			}
//			_capacity = newcapacity;
//		}
//		_a[_size] = x;
//		_size++;
//	}
// T operator[](size_t pos) 
//	{
//		assert(pos < _size);
//
//		return _a[pos];
//	}
//	size_t Size()
//	{
//		return _size;
//	}
//private:
//	T *_a;
//	size_t _size;
//	size_t _capacity;
//};

//template<class T>
//class Vector
//{
//public:
//	Vector(size_t capacity = 5)
//		:_data(new T[capacity])  // new int[capacity]  new char[capacity]
//		, _size(0)
//		, _capacity(capacity)
//	{}
//
//	/*Vector();*/
//	// pushBack(&sqlist, DataType x)
//	void pushBack(T x)
//	{
//		// check capacity
//		_data[_size++] = x;
//	}
//
//	// v1[i]
//	const T& operator[](size_t i) const
//	{
//		cout << "const T& operator[](size_t i) const" << endl;
//		assert(i < _size);
//		return _data[i];
//	}
//
//	T& operator[](size_t i)
//	{
//		cout << "T& operator[](size_t i)" << endl;
//		assert(i < _size);
//		return _data[i];
//	}
//
//	size_t Size() const
//	{
//		return _size;
//	}
//
//	~Vector()
//	{
//		if (_data)
//		{
//			delete[] _data;
//			_data = nullptr;
//			_size = 0;
//			_capacity = 0;
//		}
//	}
//private:
//	T* _data;
//	size_t _size;
//	size_t _capacity;
//};
//
//
//
//int main()
//{
//	Vector<int> v1;
//	v1.pushBack(1);
//	v1.pushBack(2);
//	v1.pushBack(3);
//	v1.pushBack(4);
//	for (size_t i = 0; i < v1.Size(); ++i){
//		cout << v1[i] << ' ';
//	}
//	cout << endl;
//	system("pause");
//	/*Vector<double> v2;*/
//	//如果想让v1中存放int类型，v2中放double类型就不能满足了
//	return 0;
//}


#include<vector>
#include<stack>
#include<string>

//int main()
//{
//	string s1("hello");
//	cout << s1 << endl;
//	for (size_t i = 0; i < s1.size(); ++i){
//		cout << s1[i] << " ";
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}

//int main()
//{
//	string s1; // 构造空的string类对象s1
//	string s2("hello bit"); // 用C格式字符串构造string类对象s2
//	string s3(10, 'a'); // 用10个字符'a'构造string类对象s3
//	string s4(s2); // 拷贝构造s4
//	string s5(s3, 5); // 用s3中前5个字符构造string对象s5
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//	cout << s4 << endl;
//	cout << s5 << endl;
//
//
//	system("pause");
//	return 0;
//
//}
//void teststring()
//{
//	string num("1234");
//	//迭代器给出了统一的方式去访问容器
//	string::iterator it = num.begin();
//	int value = 0;
//	while (it != num.end()){
//		/*cout << *it << " ";
//		++it;*/
//		value*=10;
//		value+=*it-'0';
//		++it;
//		
//	}
//	cout <<value<< endl;
//	
//}
//int StrToNum(const string& str){
//	string str("1234");
//	string::iterator it = str.begin();
//		int value = 0;
//		while (it != str.end()){
//
//			value *= 10;
//			value += *it - '0';
//			++it;
//		}
//}
//int StrToNum(const string&str){
//	int value = 0;
//	for (size_t i = 0; i < str.size(); ++i){
//		value *= 10;
//		value += str[i] - '0';
//	}
//	return value;
//}
//int StrToNum(const string&str){
//	int value = 0;
//	for (auto e:str){
//		value *= 10;
//		value +=e - '0';
//	}
//	return value;
//}
void teststring2(){
	string s("hello");
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}
int main()
{
	teststring2();


	system("pause");
	return 0;
}
