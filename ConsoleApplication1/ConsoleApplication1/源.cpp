//#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<assert.h>


class String
{
public:
	typedef char* Iterator;
	typedef char* const_Iterator;
	//ȫȱʡ��ȱʡֵΪ" "
	String(char* str = " ")  //����
		:_size(strlen(str))
		, _capacity(_size)
		, _str(new char[_size + 1])
	{
		strcpy(_str, str);
	}
	//�������죬�ִ�д��

	String(const String &s)
		:_str(nullptr)
		, _size(0)
		, _capacity(0)
	{
		String tmp(s._str);
		Swap(tmp);
	}
	//��ֵ���������
	//�ִ�д��
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
		swap(_size, tmp._size);
		swap(_capacity, tmp._capacity);
	}


	~String()
	{
		if (_str){
			delete[]_str;
			_str = nullptr;
		}
	}

	//����
	void Reserve(size_t newcapacity)
	{
		if (newcapacity > _capacity){
			char* str = new char[newcapacity + 1];
			strcpy(str, _str);
			delete[]_str;
			_str = str;
			_capacity = newcapacity;
		}
	}

	//���
	void PushBack(char c)
	{

		if (_size == _capacity){

			size_t newc = (_capacity = 0 ? 15 : _capacity * 2);
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

	//β��
	void Append(const char* str){
		size_t sz = _capacity < strlen(str);
		if (sz + _size)
		{
			Reserve(sz + _size);
		}
		strcpy(_str + _size, str);
		_size += sz;
	}
	void Resize(size_t n, char c = '\0')
	{

		//n>_capacity ��Ҫ���� �����ݵĿռ丳ֵΪc
		//n>_size �����ݵĿռ丳ֵΪc
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
	//��posλ�ò����ַ�c
	void Insert(size_t pos, const char c)
	{
		assert(_size > pos);
		if (_size == _capacity)
		{
			//����
			size_t newc = (_capacity == 0 ? 15 : _capacity * 2);
			Reserve(newc);
		}
		size_t end = _size;
		while (end > pos)
		{
			//�Ӻ���ǰŲ��
			_str[end] = _str[end - 1];
			--end;
		}
	}
	//�����ַ���
	//void Insert(size_t pos, const char* str)
	//{
	//	assert(pos < _size);
	//	size_t len = strlen(str);
	//	if (_capacity < _size + len){
	//		//size_t newc = (_capacity == 0 ? len + 1 : len + _size);
	//		Reserve(len + _size);
	//	}
	//	//�Ӻ���ǰŲ������
	//	size_t end = _size + len;
	//	while (end>pos + len - 1){
	//		//��һ��Ų����Ϊ'\0'
	//		_str[end] = _str[end - len];
	//		--end; 
	//	}
	//	//��posλ�ÿ���str
	//	for (int i = 0; i < len; i++){
	//		_str[i + pos] = str[i];
	//	}
	//	_size += len;
	//}

	void Erase(size_t pos, size_t len)
	{
		assert(pos < _size);
		//��pos��ʼ���ַ�ȫ����ɾ��
		if (pos + len>_size){
			_size = pos;
			_str[_size] = '\0';
		}
		else
		{
			size_t start = pos + len;
			//��pos+lenλ�ÿ�ʼһ��һ����ǰŲ��len��λ��
			while (start < _size){
				_str[pos++] = _str[start++];
			}
			_size -= len;
			_str[_size] = '\0';
		}
	}
	friend ostream& operator<<(ostream& _cout, const String &s);
private:
	size_t _size;  //��Ч�ַ����ȣ�������\0��
	size_t _capacity; //ʵ���ܴ�ŵ�����ַ��� ������\0��,ʵ������Ŀռ���һ���ֽ�
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

int main()
{
	String s;
	s.PushBack('a');
	s.PushBack('b');
	s.PushBack('c');
	s.PushBack('d');
	cout << s << endl;
	system("pause");
	return 0;
}