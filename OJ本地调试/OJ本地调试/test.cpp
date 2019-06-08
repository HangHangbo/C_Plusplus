#include <iostream>
#include <string>

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

class A{
public:
	A(){ p(); }
	virtual void p(){ printf("A"); }
	virtual ~A(){ p(); }
};
class B:public A
{
public:
	B(){ p(); }
	void p(){ printf("B"); }
	~B(){ p(); }

private:

};
int main()
{
	A*a = new B();
	delete a;
	system("pause");
	return 0;
}