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

//��������ģ��
template<typename T>
void Swap(T& left, T& right) {
	T temp = left;
	left = right;
	right = temp;
}  

//��Ӻ�����ģ��ʵ��
template<class T> T Add(const T& left, const T& right) {
	return left + right;
}

////��ʰʵ����
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.0, d2 = 20.0;
//	Add(a1, a2);
//	Add(d1, d2);
//	/*
//	����䲻��ͨ�����룬��Ϊ�ڱ����ڼ䣬��������������ʵ����ʱ����Ҫ������ʵ������
//	ͨ��ʵ��a1��T����Ϊint��ͨ��ʵ��d1��T����Ϊdouble���ͣ���ģ������б���ֻ��һ��T��
//	�������޷�ȷ���˴����׸ý�Tȷ��Ϊint ���� double���Ͷ�����
//	ע�⣺��ģ���У�������һ�㲻���������ת����������Ϊһ��ת�������⣬����������Ҫ���ڹ�
//	Add(a1, d1);
//	*/
//	// ��ʱ�����ִ���ʽ��1. �û��Լ���ǿ��ת�� 2. ʹ����ʽʵ����
//	Add(a, (int)d);
//	return 0;
//}  


//��ʽʵ����
//int main(void) {
//	int a = 10;
//	double b = 20.0;
//	// ��ʽʵ����
//	Add<int>(a, b);
//	return 0;
//}  

// ��̬˳���
template<class T>
class Vector
{
public:
	Vector(size_t capacity = 10)
		: _pData(new T[capacity])
		, _size(0)
		, _capacity(capacity)
	{}
	// ʹ������������ʾ�������������������ⶨ�塣
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