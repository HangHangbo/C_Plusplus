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
		//���ٿռ�
		_start = new T[v.Capacity()];
		//��������
		for (size_t i = 0; i < v.Size(); i++)
		{
			_start[i] = v[i];
		}
		//����
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
	void PushBack(const T& val)                                   //���������ã��ȿ��Բ����������ͣ�Ҳ���Բ����Զ�������
	{
		//if (Size() == Capacity())
		if (_finish == _endOfStrage)
		{
			size_t newC = (_start == nullptr ? 1 : 2 * Capacity());
			Reserve(newC);
		}
		*_finish = val;
		//����Size
		++_finish;
	}
	void Reserve(size_t newC)
	{
		if (newC > Capacity())
		{
			size_t sz = Size();
			//�����¿ռ�
			T *tmp = new T[newC];
			//���ռ��Ƿ�Ϊ��
			if (_start)
			{
				//����ԭ�пռ�
				//memcpy(tmp, _start, size(T)*sz);  //ǳ���� pushback 3���ַ�����ʱ���ͷ�ԭ�пռ�����
				//���������T���͵ĸ�ֵ�����������ɿ���
				for (size_t i = 0; i < sz; i++)
				{
					tmp[i] = _start[i];
				}

				//�ͷ�ԭ�пռ�
				delete[] _start;
			}
			//����_start
			_start = tmp;
			//����_finish
			_finish = tmp + sz;
			//����_endOfStrage
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
		//���ݺ����pos��λ��
		Iterator end = _finish;
		pos = _start + len;
		//��ǰŲ��Ԫ��
		while (end > pos)
		{
			*end = *(end - 1);
		}
		//��pos������Ԫ��
		*pos = val;
		//����_finishָ��
		++_finish;
	}
	
	//erase ���µ�����ʧЧ�������ܵ��µ���������Խ�磬����λ���쳣
	//��ȡerase�ķ���ֵ���µ�����
	//�Ӻ���ǰ����Ų��
	/*
	Iterator Erase(Iterator pos)
	{
		assert��pos < _finish && pos >= _start);
		//��ʼŲ����λ��
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
	T* _start;                //��һ��Ԫ�ؿ�ʼ��λ�ã�eg��int ��һ���ֽڵ�λ��
	T* _finish;               //���һ��Ԫ�صĽ���λ�ã�eg��int�� ���һ���ֽڵ���һ��λ��
	T* _endOfStrage;          //�ѷ���õĿռ�Ľ���λ��
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