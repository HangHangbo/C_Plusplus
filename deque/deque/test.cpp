#include<iostream>
using namespace std;

template <class T,class Ref,class Ptr>
class DequeIterator
{
public:
	typedef DequeIterator<T, Ref, Ptr> self;
	Ref operator*()
	{
		return *cur;
	}
	self &operator++()
	{
		cur++;
		if (cue == last)
		{
			node++;
			first = *node;
			last = first + bufferLen;
			cur = first;
		}
	}

private:
	T* first;
	T* last;
	T* cur;
	T** node;
};


template<class T>
class Deque
{
public:
	Deque();
	~Deque();
	iterator begin()
	{
		return _start;
	}
	iterator end()
	{
		return _finish;
	}
private:
	iterator _start;
	iterator _finish;

};
