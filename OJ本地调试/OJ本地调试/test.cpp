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
////������Ǳ���
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

//�������������

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
//������������ַ����������
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


////ͳ��ÿ�������ӵ�����
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

////ͨ���ƥ��
//bool  IsWildcard(const char *cur, const char* ret)
//{
//	//�������ָ���Ƿ�����
//	if (*cur == '\0'&&*ret == '\0')
//		return true;
//	if (*cur == '\0' || *ret == '\0')
//		return false;
//
//	//
//	if (*cur == '?')
//		return IsWildcard(cur + 1, ret + 1);
//	else if (*cur == '*')
//		return IsWildcard(cur, ret + 1) || IsWildcard(cur + 1, ret) || IsWildcard(cur + 1, ret + 1);
//	else if (*cur == *ret)
//		return IsWildcard(cur + 1, ret + 1);
//	return true;
//}
//
//int main()
//{
//	string str1, str2;
//	while (cin >> str1 >> str2)
//	{
//		bool tmp = IsWildcard(str1.c_str(), str2.c_str());
//		if (tmp == 1)
//			cout << "true" << endl;
//		else
//			cout << "false" << endl;
//	}
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int empty;
//	while (cin >> empty)
//	{
//		int count = 0;
//		int num = 0;
//		while (empty>2)
//		{
//			num = empty / 3;
//			count += num;
//			empty = empty % 3 + num;
//		}
//		if (empty == 2)
//			cout << count + 1 << endl;
//		else
//			cout << count << endl;
//	}
//	system("pause");
//	return 0;
//}

//string getstring(const char *a,const char *b)
//{
//	string str;
//	while (*a == *b)
//	{
//		str.push_back(*a);
//	}
//	return str;
//}
//int main()
//{
//	string str1, str2, result, max_result;
//	cin >> str1 >> str2;
//	const char *p1 = str1.c_str();
//	
//	while (p1)
//	{
//		const char *p2 = str2.c_str();
//		while (p2)
//		{
//			if (*p1 == *p2)
//				result = getstring(p1, p2);
//			if (max_result.size()<result.size())
//				max_result = result;
//			p2++;
//		}
//		p1++;
//	}
//	cout << max_result << endl;
//	system("pause");
//	return 0;
//}

//�����ַ���ad��������ַ���
int main()
{
	string a, b;
	while (cin >> a >> b)
	{
		string result;
		if (a.size() > b.size())
			swap(a, b);
		for (int i = 0; i < a.size(); i++)
		{
			for (int j = i; j < a.size(); j++)
			{
				string tmp = a.substr(i, j - i + 1);
				if (b.find(tmp) + 1)
				{
					if (tmp.size()>result.size())
						result = tmp;
				}
				else
					break;
			}
		}
		cout << result << endl;
	}
	system("pause");
	return 0;
}