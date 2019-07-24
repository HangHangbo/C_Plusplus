#include <iostream>

using namespace std;

void Swap(int& left, int& right) {
	int temp = left;
	left = right;
	right = temp;
}
void Swap(double& left, double& right) {
	double temp = left;
	left = right;
	right = temp;
}
void Swap(char& left, char& right) {
	char temp = left;
	left = right;
	right = temp;
}

//交换函数模板
template<typename T>
void Swap(T& left, T& right) {
	T temp = left;
	left = right;
	right = temp;
}  

//相加函数的模板实现
template<class T> T Add(const T& left, const T& right) {
	return left + right;
}

////隐拾实例化
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.0, d2 = 20.0;
//	Add(a1, a2);
//	Add(d1, d2);
//	/*
//	该语句不能通过编译，因为在编译期间，当编译器看到该实例化时，需要推演其实参类型
//	通过实参a1将T推演为int，通过实参d1将T推演为double类型，但模板参数列表中只有一个T，
//	编译器无法确定此处到底该将T确定为int 或者 double类型而报错
//	注意：在模板中，编译器一般不会进行类型转换操作，因为一旦转化出问题，编译器就需要背黑锅
//	Add(a1, d1);
//	*/
//	// 此时有两种处理方式：1. 用户自己来强制转化 2. 使用显式实例化
//	Add(a, (int)d);
//	return 0;
//}  


//显式实例化
//int main(void) {
//	int a = 10;
//	double b = 20.0;
//	// 显式实例化
//	Add<int>(a, b);
//	return 0;
//}  

// 动态顺序表
template<class T>
class Vector
{
public:
	Vector(size_t capacity = 10)
		: _pData(new T[capacity])
		, _size(0)
		, _capacity(capacity)
	{}
	// 使用析构函数演示：在类中声明，在类外定义。
	~Vector();
	void PushBack(const T& data)
	{
		// _CheckCapacity();
		_pData[_size++] = data;
	}
	void PopBack()
	{
		--_size;
	}
	size_t Size()
	{
		return _size;
	}
	T& operator[](size_t pos)
	{
		assert(pos < _size);
		return _pData[pos];
	}
private: T* _pData;
		 size_t _size;
		 size_t _capacity;
};  

int main(){
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	v.PopBack();
	cout << v.Size() << endl;
	for (int i = 0; i < v.Size();i++){
		cout << v[i] << endl;
	}
	system("pause");
	return 0;
}