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
//bool  IsWildcard(const char *cur, const char* ret)
//{
//	//检查两个指针是否都走完
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

//两个字符串ad求最长公共字符串
//int main()
//{
//	string a, b;
//	while (cin >> a >> b)
//	{
//		string result;
//		if (a.size() > b.size())
//			swap(a, b);
//		for (int i = 0; i < a.size(); i++)
//		{
//			for (int j = i; j < a.size(); j++)
//			{
//				string tmp = a.substr(i, j - i + 1);
//				if (b.find(tmp) + 1)
//				{
//					if (tmp.size()>result.size())
//						result = tmp;
//				}
//				else
//					break;
//			}
//		}
//		cout << result << endl;
//	}
//	system("pause");
//	return 0;
//}


////求两个字符串中最长公共字符串
//int main()
//{
//	string a, b;
//	while (cin >> a >> b)
//	{
//		string result;
//		if (a.size() > b.size())
//			swap(a, b);
//		for (int i = 0; i < a.size(); i++)
//		{
//			for (int j = i; j < a.size(); j++)
//			{
//				string tmp = a.substr(i, j - i + 1);
//				if (b.find(tmp) + 1)
//				{
//					if (tmp.size()>result.size())
//						result = tmp;
//				}
//				else
//					break;
//			}
//		}
//		cout << result.size() << endl;
//	}
//	system("pause");
//	return 0;
//}


//
//int main()
//{
//	int n,T,k;
//	cin >> T;
//	while (T--)
//	{
//		cin >> n >> k;
//		int num=2*n;
//		vector<int> poker(num);
//		for (int i = 0; i<num; i++)
//			cin >> poker[i];
//		while (k--){
//			vector<int> result(poker.begin(),poker.end());
//			int a = n;
//			int b = 0;
//			int c = 0;
//			int d = n;
//			while (d--)
//			{
//				poker[c++] = result[b++];
//				poker[c++] = result[a++];
//			}
//		}
//		for (int i = 0; i < num - 1; i++)
//		{
//			cout << poker[i] << " ";
//		}
//		cout << poker[num-1] << endl;
//	}
//		system("pause");
//	return 0;
//}


//int main()
//{
//	int T, n, k;
//	cin >> T;
//	while (T--)
//	{
//		cin >> n >> k;
//		int num = 2 * n;
//		vector<int> table(num);
//		for (int i = 0; i < num; ++i)
//			cin >> table[i];
//		while (k--)
//		{
//			vector<int> n1(table.begin(), table.end());
//			for (int i = 0; i < n; ++i)
//			{
//				table[2 * i] = n1[i];
//				table[2 * i + 1] = n1[i + n];
//			}
//		}
//		for (int i = 0; i < num - 1; ++i)
//			cout << table[i] << " ";
//		cout << table[num - 1] << endl;
//	}
//	system("pause");
//	return 0;
//}

//
//int Getprime(int a, int b)
//{
//	int prime;
//	if (a>b)
//		swap(a, b);
//	for (int i = 1; i<=a; i++)
//	{
//		if (a%i == 0 && b%i == 0)
//			prime = i;
//	}
//	return prime;
//}
//int main()
//{
//	int n, a;
//	while (cin >> n >> a)
//	{
//		vector<int> mon(n);
//		for (int i = 0; i < n; i++)
//		{
//			int num;
//			cin >> num;
//			mon[i] = num;
//		}
//		int c = a;
//		for (const auto e : mon)
//		{
//			if (c >= e)
//				c += e;
//			else
//				c += Getprime(c, e);
//		}
//		cout << c << endl;
//	}
//	system("pause");
//	return 0;
//}

//int main()
//{
//	string str;
//	while (cin >> str)
//	{
//		int i;
//		for (i = 0; i<str.size(); i++)
//		{
//			if (str.find(str[i]) == str.rfind(str[i]))
//			{
//				cout << str[i] << endl;
//				break;
//			}
//		}
//		if (i == str.size())
//			cout << -1 << endl;
//
//	}
//	return 0;
//}

//#include <stack>
//int main()
//{
//	string str1, str2;
//	while (cin >> str1 >> str2)
//	{
//		stack<int> s1, s2;
//		auto it1 = str1.begin();
//		auto it2 = str2.begin();
//		s1.push(*it1);
//		s2.push(*it2);
//		while (it1 != str2.end() || it2 != str2.end())
//		{
//
//		}
//	}
//		
//	return 0;
//}
//
//int Getsecond(vector<int> s){
//	//获取矩阵平方的左上角
//
//}
//
//void Getsult(int result,string *RealResult){
//	//对输出结果进行判断病修改
//}
//int main(){
//	int n;
//	while (cin >> n){
//		vector<int> arr;
//		for (int i = 0; i < n; i++){
//			int num = 0;
//			cin >> num;
//			arr.push_back(num);
//		}
//		int first = arr[0];
//		int second =Getsecond(arr);
//		int result = first;
//		string RealRes = 0;
//		if (n == 1){
//			Getsult(result,&RealRes);
//		}
//		else if (n == 2){
//			Getsult(second, &RealRes);
//		}
//		else
//		{
//			for (int i = 0; i < n; i++){
//				result = first + second;
//				first = second;
//				second = result;
//			}
//			Getsult(result, &RealRes);
//		}
//		cout << RealRes << endl;
//	}
//	system("system");
//	return 0;
//}

//int a[10005] = { 0, 1, 2, 3, 5 };
//void data_init()
//{
//	int i;
//	for (i = 3; i<10005; i++)
//	{
//		a[i] = a[i - 1] + a[i - 2];
//		if (a[i] >= 10000) a[i] %= 10000;
//	}
//}
//
////6
////18 15 21 13 25 27
//int main()
//{
//	int n, t;
//	data_init();
//	while (cin>>n)
//	{
//		while (n--)
//		{
//			cin >> t;
//			printf("%04d", a[t]);
//		}
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}
//

//
//int getroot(int origin) {
//	if (origin < 10) {
//		return origin;
//	}
//	int sum = 0;
//	while (origin > 0) {
//		sum += origin % 10;
//		origin /= 10;
//	}
//	if (sum >= 10) {
//		sum = getroot(sum);
//	}
//	return sum;
//}
//int main(){
//	string s;
//	while (cin >> s){
//		int num=0;
//		for (auto e : s){
//			num += e - '0';
//		}
//		int a = getroot(num);
//		cout << a << endl;
//	}
//	system("pause");
//	return 0;
//}


int main(){
	double cat = 0;
	double blow = 0;
	while (std::cin >> cat >> blow){
		if (cat*3.14<blow)
			std::cout << "Yes" << std::endl;
		else
			std::cout << "No" << std::endl;
	}
	system("pause");
	return 0;
}