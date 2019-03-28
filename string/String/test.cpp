#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<assert.h>
#include<string.h>


class String
{
public:
	//增容
	void Reserve(size_t newcapacity)
	{
		if (newcapacity > _capacity){
			char* str = new char[newcapacity + 1];
			strcpy(str, _str);
			delete[] _str;
			_str = str;
			_capacity = newcapacity;
		}
	}
	typedef char* Iterator;
	typedef char* const_Iterator;
	//全缺省，缺省值为" "
	String(const char* str = " ")  //构造
		:_size(strlen(str))
		, _capacity(_size)
		, _str(new char[_size + 1])
	{
		strcpy(_str, str);
	}
	//拷贝构造，现代写法

	String(const String &s)
		:_str(nullptr)
		, _size(0)
		, _capacity(0)
	{
		String tmp(s._str);
		Swap(tmp);
	}
	//赋值运算符重载
	//现代写法
	String& operator=(String s){
		Swap(s);
		return *this;
	}

	char& operator[](size_t n){
		assert(n < _size);
		return _str[n];
	}
	const char& operator[](size_t n)const
	{
		assert(n < _size);
		return _str[n];
	}
	void Swap(String & tmp)
	{
		swap(_str, tmp._str);
		swap(_size,tmp._size);
		swap(_capacity, tmp._capacity);
	}

	
	~String()
	{
		if (_str){
			delete[] _str;
			_str = nullptr;
		}
	}

	

	//后插
	void PushBack(char c)
	{
		
		if (_size == _capacity){

			size_t newc = (_capacity == 0 ? 15 : _capacity * 2);
			Reserve(newc);
		}
		_str[_size++] = c;
		_str[_size] = '\0';
	}

	//Iterator
	Iterator begin()
	{
		return _str;
	}
	Iterator end()
	{
		return _str + _size;
	}
	const Iterator begin()const
	{
		return _str;
	}
	const Iterator end()const
	{
		return _str + _size;
	}
	void Popback()
	{
		assert(_size > 0);

	}
	size_t Size()
	{
		return _size;
	}
	size_t Capacity()
	{
		return _capacity;
	}

	//+= 类
	String& operator+=(const String & s)
	{
		Append(s._str);
		return *this;
	}

	//+= 字符串
	String& operator+=(const char c)
	{
		PushBack(c);
		return *this;
	}
	String & operator+=(const char *str)
	{
		Append(str);
		return *this;
	}

	//尾插
	void Append(const char* str){
		size_t sz = _size+ strlen(str);
		if (sz > _capacity)
		{
			Reserve(sz);
		}
		strcpy(_str+_size, str);
		_size = sz;
	}
	void Resize(size_t n, char c = '\0')
	{

		//n>_capacity 需要增容 给增容的空间赋值为c
		//n>_size 给增容的空间赋值为c
		if (n>_capacity)
		{
			Reserve(n);
		}
		if (n > _size){
			memset(_str + _size, c, n - _size);
		}
		_size = n;
		_str[_size] = '\0';
	
		
		//_size=n _[_size]='\0'
	}
	//在pos位置插入字符c
	void Insert(size_t pos,const char c)
	{
		assert(_size > pos);
		if (_size == _capacity)
		{
			//增容
			size_t newc = (_capacity == 0 ? 15 : _capacity * 2);
			Reserve(newc);
		}
		size_t end =_size;
		while (end > pos)
		{
			//从后向前挪动
			_str[end] = _str[end - 1];
			--end;
		}
		_str[pos] = c;
		_str[++_size] = '\0';

		
	}
	//插入字符串
	void Insert(size_t pos, const char* str)
	{
		assert(pos < _size);
		size_t len = strlen(str);
		if (_capacity < _size + len){
			//size_t newc = (_capacity == 0 ? len + 1 : len + _size);
			Reserve(len + _size);
		}
		//从后向前挪动数据
		size_t end = _size + len;
		while (end>pos + len - 1){
			//第一个挪动的为'\0'
			_str[end] = _str[end - len];
			--end; 
		}
		//从pos位置拷贝str
		for (int i = 0; i < len; i++){
			_str[i + pos] = str[i];
		}
		_size += len;
	}
	void Clear()
	{
		_size = 0;
		_str[_size] = '\0';
	}
	const char* C_Str()const
	{
		return _str;
	}
	bool Empty()const
	{
		return 0 == _size;
	}


	void Erase(size_t pos, size_t len)
	{
		assert(pos < _size);
		//从pos开始的字符全都被删除
		if (pos + len>_size){
			_size = pos;
			_str[_size] = '\0';
		}
		else
		{
			size_t start = pos + len;
			//以pos+len位置开始一个一个向前挪动len个位置
			while (start < _size){
				_str[pos++] = _str[start++];
			}
			_size -= len;
			_str[_size] = '\0';
		}
	}
	friend ostream& operator<<(ostream& _cout, const String &s);
private:
	size_t _size;  //有效字符长度，不含‘\0’
	size_t _capacity; //实际能存放的最大字符数 不含‘\0’,实际申请的空间少一个字节
	char * _str;
};
ostream& operator<<(ostream& _cout, const String &s)
{
	for (auto&e : s)
	{
		_cout << e << " ";
	}
	return _cout;
}
//类+类
String operator+(const String & s1, const String & s2)
{
	String s3(s1);
	s3 += s2;
	return s3;
}
//类+字符串
String operator+(const String&s1, const char *str)
{
	String s3(s1);
	s3 += str;
	return s3;
}
//字符串+类
String operator+(const char *str, const String& s1)
{
	String s3(str);
	s3 += s1;
	return s3;

}
//void Test1()
//{
//	String s("sad");
//	s.PushBack('a');
//	s.PushBack('b');
//	s.PushBack('c');
//	s.PushBack('d');
//	cout << s << endl;  //s a d a b c d
//	//s.Insert(0, 'a');
//	//s.Insert(2, 't');
//	//s.Insert(3, 'p');  //a s  t p a d a b c d
//	//cout << s << endl;
//	//s.Insert(2, "po"); //a s  p o t p a d a b c d
//	s.Append("asd");
//	cout << s << endl;
//	/*String s2(s);
//	s.Erase(2,10);
//	
//	/*cout << s << endl;
//	cout << s2 << endl;*/
//
//}



int main()
{
	String s1("as");
	String s2("as");
	String s3; 
	String s4; 
	String s5;
	char *str = "df";
	s3 = s1 + s2;
	s4 = s1 + str;
	s5 = str + s1;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;

	
	system("pause");
	return 0;
}