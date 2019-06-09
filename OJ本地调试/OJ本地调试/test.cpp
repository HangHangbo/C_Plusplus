#include <iostream>
#include <string>
#include <vector>
using namespace std;





//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	char *p;
//	char str[] = "asdfghjkl";
//	p = str;
//	p += 5;
//	return 0;
//}
//
////杨辉三角变形
//#include <iostream>
//
//using namespace std;
//int main()
//{
//	int num = 0;
//	while (cin >> num)
//	{
//		if (num == 1 || num == 2)
//			cout << -1 << endl;
//		else if (num % 2 == 1)
//			cout << 2 << endl;
//		else if (num % 4 == 0)
//			cout << 3 << endl;
//		else if (num % 4 == 2)
//			cout << 4 << endl;
//	}
//	return 0;
//}

//超长正整数相加

//int main()
//{
//	string addend,sugend;
//	cin >> addend;
//	cin >> sugend;
//	string result;
//	int next = 0;
//	auto add = addend.rbegin();
//	auto sug = sugend.rbegin();
//	while (add != addend.rend())
//	{
//		int num;
//		if (sug != sugend.rend())
//			num = *add + *sug + next-'0';
//		else
//			num = *add + next-'0';
//		if (num > 9)
//		{
//			next = 1;
//			num = num % 10;
//		}
//		else
//		{
//			next = 0;
//		}
//		cout << "=>"<<num << endl;
//		result.push_back(num);
//		if (sug != sugend.rend())
//		{
//			add++;
//			sug++;
//		}
//		else
//		{
//			add++;
//		}
//	}
//	if (sug != sugend.rend())
//	{
//		while (sug != sugend.rend())
//		{
//			int num;
//			num = *sug + next-'0';
//			if (num > 9)
//			{
//				next = 1;
//				num = num % 10;
//			}
//			else
//			{
//				next = 0;
//			}
//			cout << "=>" << num << endl;
//			result.push_back(num);
//			sug++;
//		}
//	}
//	if (next == 1)
//		cout << "=>"<<next << endl;
//		result.push_back(next);
//	reverse(result.begin(), result.end());
//	cout << addend << endl;
//	cout << sugend << endl;
//	cout << result << endl;
//	system("pause");
//	return 0;
//}

#if 0
//两个超级大的字符串数字相加
#include <algorithm>
int main()
{
	string addend, sugend,result;
	cin >> addend;
	cin >> sugend;
	int carry = 0;
	int add = addend.size()-1;
	int sug = sugend.size()-1;
	while (add >= 0 || sug >= 0)
	{
		if (add >= 0)
			carry += addend[add] - '0';
		if (sug >= 0)
			carry += sugend[sug] - '0';
		result += (char)(carry % 10 +'0');
		carry /= 10;
		add--;
		sug--;
	}
	if (carry == 1)
		result += '1';
	reverse(result.begin(), result.end());
	cout << result << endl;
	system("pause");
	return 0;
}
#endif

//class A{
//public:
//	A(){ p(); }
//	virtual void p(){ printf("A"); }
//	virtual ~A(){ p(); }
//};
//class B:public A
//{
//public:
//	B(){ p(); }
//	void p(){ printf("B"); }
//	~B(){ p(); }
//
//private:
//
//};
//int main()
//{
//	/*A*a = new B();
//	delete a;*/
//
//	system("pause");
//	return 0;
//}

//void c(int *a, int n)
//{
//	while (n)
//	{
//		*a++;
//		a++;
//		n--;
//	}
//	
//}
//int main()
//{
//	int a[] = { 1, 2, 3 };
//	int n = 2;
//	c(a, n);
//	return 0;
//}


////统计每个月兔子的总数
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	int month;
//	while (cin >> month)
//	{
//		int count = 0;
//		int a = 0;
//		int b = 1;
//		for (int i = 1; i <= month; i++)
//		{
//			if (i == 2 || i == 1)
//				count = 1;
//			if (i>2)
//			{
//				count = a + b;
//			}
//			a = b;
//			b = count;
//		}
//		cout << count << endl;
//	}
//	system("pause");
//	return 0;
//}

////通配符匹配
//bool  IsWildcard(string a, string b)
//{
//	int pos1;  //记录？下标
//	int pos2;  //记录*下标
//	string str;
//	pos1 = a.find('?');
//	pos2 = a.find('*');
//	//通配符使用错误
//
//	//字母数字不匹配
//}
//
//int main()
//{
//	string str1,str2;
//	cin >> str1;
//	cin >> str2;
//	cout << IsWildcard(str1, str2) << endl;
//	return 0;
//}

class bitMap
{
public:
	bitMap(size_t bitcount)
		:_bit((bitcount>>5)+1)
		, _bitCount(bitcount)
	{}
	//置1
	void Set(size_t which)
	{
		while (which > _bitCount)
			return;
		size_t index = which >> 5;
		size_t pos = which % 32;

		_bit[index] |= (1 << pos);
	}
	//置0
	void ReSet(size_t which)
	{
		while (which > _bitCount)
			return;
		size_t index = which >> 5;
		size_t pos = which % 5;

		_bit[index] |= ~(1 << pos);
	}
	bool Test(size_t which)
	{
		while (which > _bitCount)
			return false;
		size_t index = which >> 5;
		size_t pos = which % 5;
		return _bit[index] & (1 << pos);
	}
private:
	vector<int> _bit;
	size_t _bitCount;
};

int main()
{
	bitMap map(10);
	map.Set(2);
	map.Set(5);
	map.Set(7);
	map.ReSet(5);
	cout << map.Test(5) << endl;
	system("pause");
	return 0;
}