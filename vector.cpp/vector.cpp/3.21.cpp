#include<iostream>
using namespace std;
#include<assert.h>
#include<string>

template <class T>

class Vector
{
public:
	typedef T* Iterator;
	typedef const T* const_Iterator;
	Vector()
		: _start(nullptr)
		, _finish(nullptr)
		, _endOfStrage(nullptr)
	{}
	
	Vector(const Vector<T>& v)
	{
		//开辟空间
		_start = new T[v.Capacity()];
		//拷贝内容
		for (size_t i = 0; i < v.Size(); i++)
		{
			_start[i] = v[i];
		}
		//更新
		_finish = _start + v.Size();
		_endOfStrage = _start + v.Capacity();
	}

	~Vector()
	{
		if (_start)
		{
			delete[]_start;
			_start = nullptr;
			_finish = nullptr;
			_endOfStrage = nullptr;
		}
	}
	size_t Size()const
	{
		return _finish - _start;
	}
	size_t Capacity()const
	{
		return _endOfStrage - _start;
	}
	void PushBack(const T& val)                                   //这里是引用，既可以插入内置类型，也可以插入自定义类型
	{
		//if (Size() == Capacity())
		if (_finish == _endOfStrage)
		{
			size_t newC = (_start == nullptr ? 1 : 2 * Capacity());
			Reserve(newC);
		}
		*_finish = val;
		//更新Size
		++_finish;
	}
	void Reserve(size_t newC)
	{
		if (newC > Capacity())
		{
			size_t sz = Size();
			//申请新空间
			T *tmp = new T[newC];
			//检查空间是否为空
			if (_start)
			{
				//拷贝原有空间
				//memcpy(tmp, _start, size(T)*sz);  //浅拷贝 pushback 3次字符类型时会释放原有空间两次
				//深拷贝，调用T类型的赋值运算符重载完成拷贝
				for (size_t i = 0; i < sz; i++)
				{
					tmp[i] = _start[i];
				}

				//释放原有空间
				delete[] _start;
			}
			//更新_start
			_start = tmp;
			//更新_finish
			_finish = tmp + sz;
			//更新_endOfStrage
			_endOfStrage = tmp + newC;

		}
	}
	void Insert(Iterator pos, const T& val)
	{
		assert(pos >= _start&&pos <_finish);
		size_t len = pos - _start;
		if (_finish == _endOfStrage)
		{
			size_t newC = (_start == nullptr ? 1 : 2 * Capacity());
			Reserve(newC);
		}
		//增容后更新pos的位置
		Iterator end = _finish;
		pos = _start + len;
		//向前挪动元素
		while (end > pos)
		{
			*end = *(end - 1);
		}
		//在pos出插入元素
		*pos = val;
		//更新_finish指针
		++_finish;
	}
	
	//erase 导致迭代器失效，，可能导致迭代器访问越界，或者位置异常
	//获取erase的返回值更新迭代器
	//从后向前依次挪动
	/*
	Iterator Erase(Iterator pos)
	{
		assert（pos < _finish && pos >= _start);
		//起始挪动的位置
		Iterator begin = pos + 1;
		while (begin < _finish)
		{
			*(begin - 1) = *begin;
			begin++;
		}
		--_finish;
		return pos;
	}
	*/
	Iterator Erase(Iterator pos)
	{
		assert(pos < _finish && pos >= _start);
		Iterator begin = pos + 1;
		while (begin < _finish)
		{
			*(begin - 1) = *begin;
			begin++;
		}
		--_finish;
		return pos;
	}

	
	
	void Resize(size_t n,const T& val=T())
	{
		if (n <= Size())
		{
			//_finish - _start
			_finish = _start + n;
		}
		else
		{
			if (n > Capacity())
			{
				Reserve(n);
			}
			//Size()  n
			while (_finish != _start + n)
			{
				*_finish = val;
				_finish++;
			}
		}
	}
	
	T& operator=(Vector<T> v)
	{
		Swap(v);
		return *this;
	}
	void Swap(Vector<T>& v)
	{
		swap(_start, v._start);
		swap(_finish, v._finish);
		swap(_endOfStrage, v._endOfStrage);
	}
	 T& operator[]( size_t pos)const
	{
		assert(pos < Size());
		return _start[pos];
	}
	 Iterator begin()
	 {
		 return _start;
	 }
	 Iterator end()
	 {
		 return _finish;
	 } 
	Iterator begin()const
	 {
		 return _start;
	 }
	 Iterator end()const
	 {
		 return _finish;
	 }

private:
	T* _start;                //第一个元素开始的位置，eg：int 第一个字节的位置
	T* _finish;               //最后一个元素的结束位置，eg，int。 最后一个字节的下一个位置
	T* _endOfStrage;          //已分配好的空间的结束位置
};
template <class T>
void PrintVectorFor(const Vector<T>& v)
{
	for (auto &e:v)
	{
		cout << e<<" ";
	}
	cout << endl;
}
template <class T>
void PrintVector(const Vector<T>& v)
{
	auto *it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
int main()
{
	
	Vector<int> v1;
	v1.PushBack(1);
	v1.PushBack(1);
	v1.PushBack(1);
	v1.PushBack(1);
	PrintVectorFor(v1);
	Vector<string> v2;
	v2.PushBack("hello");
	v2.PushBack("world");
	PrintVector(v2);
	
	Vector<int> v3(v1);
	PrintVectorFor(v3);
	system("pause");
	
	return 0;
}
//int main()
//{
//	Vector<string> v2;
//	/*Vector<int> v1;
//	v1.PushBack(1);
//	v1.PushBack(1);
//	v1.PushBack(1);
//	v1.PushBack(1);
//	v1.PushBack(1);*/
//	v2.PushBack("1");
//	v2.PushBack("1");
//	v2.PushBack("1");
//	v2.PushBack("1");
//	PrintVector(v2);
//	system("pause");
//	return 0;
//}
//void testVector1()
//{
//	Vector<int> v;
//	v.PushBack(1);
//	v.PushBack(2);
//	v.PushBack(3);
//	v.PushBack(4);
//	v.PushBack(56);
//
//	PrintVectorFor(v);
//
//	Vector<string> v2;
//	v2.PushBack("hello");
//	v2.PushBack("world");
//	v2.PushBack("bite");
//	v2.PushBack("tech");
//	v2.PushBack("school");
//	PrintVectorFor(v2);
//
//}
//
//
//int main()
//{
//	testVector1();
//
//	system("pause");
//	return 0;
//}