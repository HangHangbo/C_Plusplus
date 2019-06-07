//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;


////int main()
////{
////	int num[4] = { 0 };
////	for (int i = 0; i < 4; i++)
////	{
////		cin >> num[i];
////	}
////	int A, B, C;
////	A = (num[0] + num[2]) / 2;
////	B = (num[1] + num[3]) / 2;
////	C = B - num[1];
////	if ((num[0]==A-B) && (num[1]==B-C) && (num[2]==A+B)&&(num[3]==B+C))
////	{
////		cout << A << ' ' << B << ' ' << C << endl;
////	}
////	else
////	{
////		cout << "No" << endl;
////	}
////	system("pause");
////	return 0;
////}
////class A
////{
////	friend long fun(A s)
////	{
////		if (s.x < 3){
////			return 1;
////		}
////		return s.x + fun(A(s.x - 1));
////	}
////public:
////	A(long a)
////	{
////		x = a--;
////		cout << x << endl;
////	}
////private:
////	long x;
////};
////int main()
////{
////	int sum = 0;
////	for (int i = 0; i < 5; i++)
////	{
////		sum += fun(A(i));
////	}
////	cout << sum;
////	system("pause");
////	return 0;
////}
////int main()
////{
////	int i = 3;
////	int a = i++;
////	return 0;
////}
////int main()
////{
////	int i = 10;
////	int j = 1;
////	const int *p1;//(1)
////	int const *p2 = &i; //(2)
////	p2 = &j;//(3)
////	int *const p3 = &i;//(4)
////	*p3 = 20;//(5)
////	*p2 = 30;//(6)
////	p3 = &j;//(7)
////	return 0;
////}
//
//
//
////class A
////{
////public:
////	A() :m_iVal(0)
////	{ 
////		test();
////	}	// 0
////	virtual void func() { 
////		std::cout << m_iVal; 
////	}
////	void test(){ func(); }
////public:
////	int m_iVal;
////};
////class B : public A
////{
////public:
////	B(){ 
////		test();
////	}
////	virtual void func()
////	{
////		++m_iVal;
////		std::cout << m_iVal;     //1
////	}
////};
////int main(int argc, char* argv[])
////{
////	A*p = new B;
////	p->test();
////	return 0;
////}
////typedef void (*fF)();
//
////int main()
////{
////	
////	unsigned int n = 197;
////	n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
////	n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
////	n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
////	n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
////	n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
////	system("pause");
////	return 0;
////}
////int BitCount4(unsigned int n)
////{
////	n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
////	n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
////	n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
////	n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
////	n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
////
////	return n;
////}
//int main()
//{
//	char arr[] = "ABC";
//	char arr1[] = { 'A', 'B', 'C' };
//	int a[100][100] = {0};
//	for (int i = 0; i < 100; j++)
//	{
//		for (int j = 0; j < 100; j++)
//			a[i][j] += a[j][i];
//	}
//	return 0;
//}

#if 0

//一个整数二进制由多少个1
#include <iostream>
using namespace std;
int main()
{
	int n = 0;
	int count = 0;
	while (cin >> n)
	{
		while (n)
		{
			int num = n & 1;
			if (num == 1)
			{
				count++;
			}
			n = n >> 1;
		}
		cout << count << endl;
	}
	system("pause");
	return 0;
}

#endif


#if 0

class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		// write code here
		int sumL = 0, sumR = 0, min = 0;
		vector<int> arrL, arrR;
		for (int i = 0; i < n; i++)
		{
			if (left[i] == 0 || right[i] == 0)
			{
				min += left[i] + right[i];
				continue;
			}
			sumL += left[i];
			arrL.push_back(left[i]);
			sumR += right[i];
			arrR.push_back(right[i]);
		}
		if (sumL < sumR)
		{
			sort(arrL.begin(), arrL.end());
			for (int i = 1; i < arrL.size(); i++)
				min += arrL[i];
		}
		else
		{
			sort(arrR.begin(), arrR.end());
			for (int i = 1; i < arrR.size(); i++)
				min += arrR[i];
		}
		return min + 2;
	}
};


//class Gloves {
//public:
//	int findMinimum(int n, vector<int> left, vector<int> right) {
//		int MIN = 0, lsum = 0, rsum = 0;
//		vector<int> tlef, trig;
//		for (int i = 0; i < n; i++)
//		{
//			if (left[i] == 0 || right[i] == 0)
//			{
//				MIN += right[i] + left[i];
//				continue;
//			}
//			lsum += left[i], tlef.push_back(left[i]);
//			rsum += right[i], trig.push_back(right[i]);
//		}
//		if (lsum < rsum)
//		{
//			sort(tlef.begin(), tlef.end());
//			for (int i = tlef.size() - 1; i > 0; i--) MIN += tlef[i];
//		}
//		else
//		{
//			sort(trig.begin(), trig.end());
//			for (int i = trig.size() - 1; i > 0; i--) MIN += trig[i];
//		}
//		return MIN + 2;
//	}
//};

int main()
{
	int n = 4;
	vector<int> left;
	left.push_back(0);
	left.push_back(7);
	left.push_back(1);
	left.push_back(6);


	vector<int> right;
	right.push_back(1);
	right.push_back(5);
	right.push_back(0);
	right.push_back(6);
	
	Gloves s;
	int m = s.findMinimum(n, left, right);
	return 0;
}
#endif
//
//void pint(char *str)
//{
//	if (*str){
//		pint(str++);
//		printf("%c", *str);
//	}
//}
//
//int main()
//{
//	char str[] = "asdfgh";
//	pint(str);
//	system("pause");
//	return 0;
//}

//
//#include <iostream>
//using namespace std;
//bool count(int num)
//{
//	if (num <= 1)
//		return false;
//	int sum=0;
//	for (int i = 1; i<num; ++i)
//	{
//		if (num%i == 0)
//			sum += i;
//	}
//	if (num != sum)
//		return false;
//	else
//		return true;
//}
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		int g_count = 0;
//		for (int i = 0; i <= n; i++)
//		{
//			g_count += count(i);
//		}
//		cout << g_count << endl;
//	}
//	system("pause");
//	return 0;
//}


//扑克比大小
#include <iostream>
#include <string>
using namespace std;
string poker = "345678910JQKA2";
#define printa {cout<<a<<endl; system("pause");return 0;}
#define printb {cout<<b<<endl; system("pause");return 0;}

int count(const string &a)
{
	int num = 0;
	auto it = a.begin();
	while (it != a.end())
	{
		if (*it == ' ')
			num++;
		++it;
	}
	return num;
}

int main()
{
	string str;
	getline(cin, str);
		string a;
		string b;
		int len=str.find('-');
		a = str.substr(0, len);
		b = str.substr(len+1);
		string Max = "joker JOKER";
		if (a == Max)
		{
			printa;
		}
		else if (b == Max)
		{
			printb;
		}
		//获取空格个数
		int count_a = count(a);
		int count_b = count(b);
		//相同牌型
		if (count_a == count_b)
		{
			string begin_a, begin_b;
			int pos_a = a.find(' ');
			begin_a = a.substr(0, pos_a);
			int pos_b = b.find(' ');
			begin_b = b.substr(0, pos_b);
			if (poker.find(begin_a) > poker.find(begin_b))
			{
				printa;
			}
			else
			{
				printb;
			}
		}
		//有一手牌是炸弹
		if (count_a == 3 && count_b != 3)
		{
			printa;
		}
		else if (count_b == 3 && count_a != 3)
		{
			printb;
		}
		cout << "ERROR" << endl;


	system("pause");
	return 0;
}