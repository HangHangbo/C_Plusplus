//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
////
////
////
////
////
//////#include <iostream>
//////
//////using namespace std;
//////
//////int main()
//////{
//////	char *p;
//////	char str[] = "asdfghjkl";
//////	p = str;
//////	p += 5;
//////	return 0;
//////}
//////
////////杨辉三角变形
//////#include <iostream>
//////
//////using namespace std;
//////int main()
//////{
//////	int num = 0;
//////	while (cin >> num)
//////	{
//////		if (num == 1 || num == 2)
//////			cout << -1 << endl;
//////		else if (num % 2 == 1)
//////			cout << 2 << endl;
//////		else if (num % 4 == 0)
//////			cout << 3 << endl;
//////		else if (num % 4 == 2)
//////			cout << 4 << endl;
//////	}
//////	return 0;
//////}
////
//////超长正整数相加
////
//////int main()
//////{
//////	string addend,sugend;
//////	cin >> addend;
//////	cin >> sugend;
//////	string result;
//////	int next = 0;
//////	auto add = addend.rbegin();
//////	auto sug = sugend.rbegin();
//////	while (add != addend.rend())
//////	{
//////		int num;
//////		if (sug != sugend.rend())
//////			num = *add + *sug + next-'0';
//////		else
//////			num = *add + next-'0';
//////		if (num > 9)
//////		{
//////			next = 1;
//////			num = num % 10;
//////		}
//////		else
//////		{
//////			next = 0;
//////		}
//////		cout << "=>"<<num << endl;
//////		result.push_back(num);
//////		if (sug != sugend.rend())
//////		{
//////			add++;
//////			sug++;
//////		}
//////		else
//////		{
//////			add++;
//////		}
//////	}
//////	if (sug != sugend.rend())
//////	{
//////		while (sug != sugend.rend())
//////		{
//////			int num;
//////			num = *sug + next-'0';
//////			if (num > 9)
//////			{
//////				next = 1;
//////				num = num % 10;
//////			}
//////			else
//////			{
//////				next = 0;
//////			}
//////			cout << "=>" << num << endl;
//////			result.push_back(num);
//////			sug++;
//////		}
//////	}
//////	if (next == 1)
//////		cout << "=>"<<next << endl;
//////		result.push_back(next);
//////	reverse(result.begin(), result.end());
//////	cout << addend << endl;
//////	cout << sugend << endl;
//////	cout << result << endl;
//////	system("pause");
//////	return 0;
//////}
////
////#if 0
//////两个超级大的字符串数字相加
////#include <algorithm>
////int main()
////{
////	string addend, sugend,result;
////	cin >> addend;
////	cin >> sugend;
////	int carry = 0;
////	int add = addend.size()-1;
////	int sug = sugend.size()-1;
////	while (add >= 0 || sug >= 0)
////	{
////		if (add >= 0)
////			carry += addend[add] - '0';
////		if (sug >= 0)
////			carry += sugend[sug] - '0';
////		result += (char)(carry % 10 +'0');
////		carry /= 10;
////		add--;
////		sug--;
////	}
////	if (carry == 1)
////		result += '1';
////	reverse(result.begin(), result.end());
////	cout << result << endl;
////	system("pause");
////	return 0;
////}
////#endif
////
//////class A{
//////public:
//////	A(){ p(); }
//////	virtual void p(){ printf("A"); }
//////	virtual ~A(){ p(); }
//////};
//////class B:public A
//////{
//////public:
//////	B(){ p(); }
//////	void p(){ printf("B"); }
//////	~B(){ p(); }
//////
//////private:
//////
//////};
//////int main()
//////{
//////	/*A*a = new B();
//////	delete a;*/
//////
//////	system("pause");
//////	return 0;
//////}
////
//////void c(int *a, int n)
//////{
//////	while (n)
//////	{
//////		*a++;
//////		a++;
//////		n--;
//////	}
//////	
//////}
//////int main()
//////{
//////	int a[] = { 1, 2, 3 };
//////	int n = 2;
//////	c(a, n);
//////	return 0;
//////}
////
////
////////统计每个月兔子的总数
//////#include <iostream>
//////
//////using namespace std;
//////
//////int main()
//////{
//////	int month;
//////	while (cin >> month)
//////	{
//////		int count = 0;
//////		int a = 0;
//////		int b = 1;
//////		for (int i = 1; i <= month; i++)
//////		{
//////			if (i == 2 || i == 1)
//////				count = 1;
//////			if (i>2)
//////			{
//////				count = a + b;
//////			}
//////			a = b;
//////			b = count;
//////		}
//////		cout << count << endl;
//////	}
//////	system("pause");
//////	return 0;
//////}
////
////////通配符匹配
//////bool  IsWildcard(const char *cur, const char* ret)
//////{
//////	//检查两个指针是否都走完
//////	if (*cur == '\0'&&*ret == '\0')
//////		return true;
//////	if (*cur == '\0' || *ret == '\0')
//////		return false;
//////
//////	//
//////	if (*cur == '?')
//////		return IsWildcard(cur + 1, ret + 1);
//////	else if (*cur == '*')
//////		return IsWildcard(cur, ret + 1) || IsWildcard(cur + 1, ret) || IsWildcard(cur + 1, ret + 1);
//////	else if (*cur == *ret)
//////		return IsWildcard(cur + 1, ret + 1);
//////	return true;
//////}
//////
//////int main()
//////{
//////	string str1, str2;
//////	while (cin >> str1 >> str2)
//////	{
//////		bool tmp = IsWildcard(str1.c_str(), str2.c_str());
//////		if (tmp == 1)
//////			cout << "true" << endl;
//////		else
//////			cout << "false" << endl;
//////	}
//////	system("pause");
//////	return 0;
//////}
////
//////int main()
//////{
//////	int empty;
//////	while (cin >> empty)
//////	{
//////		int count = 0;
//////		int num = 0;
//////		while (empty>2)
//////		{
//////			num = empty / 3;
//////			count += num;
//////			empty = empty % 3 + num;
//////		}
//////		if (empty == 2)
//////			cout << count + 1 << endl;
//////		else
//////			cout << count << endl;
//////	}
//////	system("pause");
//////	return 0;
//////}
////
//////string getstring(const char *a,const char *b)
//////{
//////	string str;
//////	while (*a == *b)
//////	{
//////		str.push_back(*a);
//////	}
//////	return str;
//////}
//////int main()
//////{
//////	string str1, str2, result, max_result;
//////	cin >> str1 >> str2;
//////	const char *p1 = str1.c_str();
//////	
//////	while (p1)
//////	{
//////		const char *p2 = str2.c_str();
//////		while (p2)
//////		{
//////			if (*p1 == *p2)
//////				result = getstring(p1, p2);
//////			if (max_result.size()<result.size())
//////				max_result = result;
//////			p2++;
//////		}
//////		p1++;
//////	}
//////	cout << max_result << endl;
//////	system("pause");
//////	return 0;
//////}
////
//////两个字符串ad求最长公共字符串
//////int main()
//////{
//////	string a, b;
//////	while (cin >> a >> b)
//////	{
//////		string result;
//////		if (a.size() > b.size())
//////			swap(a, b);
//////		for (int i = 0; i < a.size(); i++)
//////		{
//////			for (int j = i; j < a.size(); j++)
//////			{
//////				string tmp = a.substr(i, j - i + 1);
//////				if (b.find(tmp) + 1)
//////				{
//////					if (tmp.size()>result.size())
//////						result = tmp;
//////				}
//////				else
//////					break;
//////			}
//////		}
//////		cout << result << endl;
//////	}
//////	system("pause");
//////	return 0;
//////}
////
////
////////求两个字符串中最长公共字符串
//////int main()
//////{
//////	string a, b;
//////	while (cin >> a >> b)
//////	{
//////		string result;
//////		if (a.size() > b.size())
//////			swap(a, b);
//////		for (int i = 0; i < a.size(); i++)
//////		{
//////			for (int j = i; j < a.size(); j++)
//////			{
//////				string tmp = a.substr(i, j - i + 1);
//////				if (b.find(tmp) + 1)
//////				{
//////					if (tmp.size()>result.size())
//////						result = tmp;
//////				}
//////				else
//////					break;
//////			}
//////		}
//////		cout << result.size() << endl;
//////	}
//////	system("pause");
//////	return 0;
//////}
////
////
//////
//////int main()
//////{
//////	int n,T,k;
//////	cin >> T;
//////	while (T--)
//////	{
//////		cin >> n >> k;
//////		int num=2*n;
//////		vector<int> poker(num);
//////		for (int i = 0; i<num; i++)
//////			cin >> poker[i];
//////		while (k--){
//////			vector<int> result(poker.begin(),poker.end());
//////			int a = n;
//////			int b = 0;
//////			int c = 0;
//////			int d = n;
//////			while (d--)
//////			{
//////				poker[c++] = result[b++];
//////				poker[c++] = result[a++];
//////			}
//////		}
//////		for (int i = 0; i < num - 1; i++)
//////		{
//////			cout << poker[i] << " ";
//////		}
//////		cout << poker[num-1] << endl;
//////	}
//////		system("pause");
//////	return 0;
//////}
////
////
//////int main()
//////{
//////	int T, n, k;
//////	cin >> T;
//////	while (T--)
//////	{
//////		cin >> n >> k;
//////		int num = 2 * n;
//////		vector<int> table(num);
//////		for (int i = 0; i < num; ++i)
//////			cin >> table[i];
//////		while (k--)
//////		{
//////			vector<int> n1(table.begin(), table.end());
//////			for (int i = 0; i < n; ++i)
//////			{
//////				table[2 * i] = n1[i];
//////				table[2 * i + 1] = n1[i + n];
//////			}
//////		}
//////		for (int i = 0; i < num - 1; ++i)
//////			cout << table[i] << " ";
//////		cout << table[num - 1] << endl;
//////	}
//////	system("pause");
//////	return 0;
//////}
////
//////
//////int Getprime(int a, int b)
//////{
//////	int prime;
//////	if (a>b)
//////		swap(a, b);
//////	for (int i = 1; i<=a; i++)
//////	{
//////		if (a%i == 0 && b%i == 0)
//////			prime = i;
//////	}
//////	return prime;
//////}
//////int main()
//////{
//////	int n, a;
//////	while (cin >> n >> a)
//////	{
//////		vector<int> mon(n);
//////		for (int i = 0; i < n; i++)
//////		{
//////			int num;
//////			cin >> num;
//////			mon[i] = num;
//////		}
//////		int c = a;
//////		for (const auto e : mon)
//////		{
//////			if (c >= e)
//////				c += e;
//////			else
//////				c += Getprime(c, e);
//////		}
//////		cout << c << endl;
//////	}
//////	system("pause");
//////	return 0;
//////}
////
//////int main()
//////{
//////	string str;
//////	while (cin >> str)
//////	{
//////		int i;
//////		for (i = 0; i<str.size(); i++)
//////		{
//////			if (str.find(str[i]) == str.rfind(str[i]))
//////			{
//////				cout << str[i] << endl;
//////				break;
//////			}
//////		}
//////		if (i == str.size())
//////			cout << -1 << endl;
//////
//////	}
//////	return 0;
//////}
////
//////#include <stack>
//////int main()
//////{
//////	string str1, str2;
//////	while (cin >> str1 >> str2)
//////	{
//////		stack<int> s1, s2;
//////		auto it1 = str1.begin();
//////		auto it2 = str2.begin();
//////		s1.push(*it1);
//////		s2.push(*it2);
//////		while (it1 != str2.end() || it2 != str2.end())
//////		{
//////
//////		}
//////	}
//////		
//////	return 0;
//////}
//////
//////int Getsecond(vector<int> s){
//////	//获取矩阵平方的左上角
//////
//////}
//////
//////void Getsult(int result,string *RealResult){
//////	//对输出结果进行判断病修改
//////}
//////int main(){
//////	int n;
//////	while (cin >> n){
//////		vector<int> arr;
//////		for (int i = 0; i < n; i++){
//////			int num = 0;
//////			cin >> num;
//////			arr.push_back(num);
//////		}
//////		int first = arr[0];
//////		int second =Getsecond(arr);
//////		int result = first;
//////		string RealRes = 0;
//////		if (n == 1){
//////			Getsult(result,&RealRes);
//////		}
//////		else if (n == 2){
//////			Getsult(second, &RealRes);
//////		}
//////		else
//////		{
//////			for (int i = 0; i < n; i++){
//////				result = first + second;
//////				first = second;
//////				second = result;
//////			}
//////			Getsult(result, &RealRes);
//////		}
//////		cout << RealRes << endl;
//////	}
//////	system("system");
//////	return 0;
//////}
////
//////int a[10005] = { 0, 1, 2, 3, 5 };
//////void data_init()
//////{
//////	int i;
//////	for (i = 3; i<10005; i++)
//////	{
//////		a[i] = a[i - 1] + a[i - 2];
//////		if (a[i] >= 10000) a[i] %= 10000;
//////	}
//////}
//////
////////6
////////18 15 21 13 25 27
//////int main()
//////{
//////	int n, t;
//////	data_init();
//////	while (cin>>n)
//////	{
//////		while (n--)
//////		{
//////			cin >> t;
//////			printf("%04d", a[t]);
//////		}
//////		printf("\n");
//////	}
//////	system("pause");
//////	return 0;
//////}
//////
////
//////
//////int getroot(int origin) {
//////	if (origin < 10) {
//////		return origin;
//////	}
//////	int sum = 0;
//////	while (origin > 0) {
//////		sum += origin % 10;
//////		origin /= 10;
//////	}
//////	if (sum >= 10) {
//////		sum = getroot(sum);
//////	}
//////	return sum;
//////}
//////int main(){
//////	string s;
//////	while (cin >> s){
//////		int num=0;
//////		for (auto e : s){
//////			num += e - '0';
//////		}
//////		int a = getroot(num);
//////		cout << a << endl;
//////	}
//////	system("pause");
//////	return 0;
//////}
////
////
//////int main(){
//////	double long cat = 0;
//////	double long blow = 0;
//////	while (std::cin >> cat >> blow){
//////		if (cat*3.14<blow)
//////			std::cout << "Yes" << std::endl;
//////		else
//////			std::cout << "No" << std::endl;
//////	}
//////	system("pause");
//////	return 0;
//////}
//////#include <stack>
//////#include <algorithm>
//////class Solution {
//////public:
////	/**
////	*  奇数位上都是奇数或者偶数位上都是偶数
////	*  输入：数组arr，长度大于2
////	*  len：arr的长度
////	*  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
////	*/
////
////
////	//void oddInOddEvenInEven(vector<int>& arr, int len) {
////	//	reverse(arr.begin(), arr.end());
////	//	stack<int> odd_s;
////	//	stack<int> even_s;
////	//	for (auto e : arr){
////	//		if (e % 2 == 1){
////	//			//奇数
////	//			odd_s.push(e);
////	//		}
////	//		else{
////	//			//偶数
////	//			even_s.push(e);
////	//		}
////	//	}
////	//		int i = 0;
////	//		while (!odd_s.empty() && !even_s.empty()){
////	//			int odd = odd_s.top();
////	//			arr[i + 1] = odd;
////	//			int even = even_s.top();
////	//			arr[i] = even;
////	//			odd_s.pop(), even_s.pop();
////	//			i += 2;
////	//		}
////	//		if (!odd_s.empty()){
////	//			for (int j = i; j < len; j++){
////	//				arr[j] = odd_s.top();
////	//				odd_s.pop();
////	//			}
////	//		}
////	//		else if (!even_s.empty()){
////	//			for (int j = i; j < len; j++){
////	//				arr[j] = even_s.top();
////	//				even_s.pop();
////	//			}
////	//		}	
////	//}
////
//////};
//////int main(){
//////	Solution s;
//////	vector<int> arr;
//////	arr.push_back(1);
//////	arr.push_back(2);
//////	arr.push_back(3);
//////	arr.push_back(4);
//////	s.oddInOddEvenInEven(arr, 4);
//////	return 0;
//////}
//////
//////#include <math.h>
//////using namespace std;
//////int main()
//////{
//////	int n = 0;
//////	while (cin >> n){
//////		if (n == 0)
//////			break;
//////		
//////			double long int a = pow(5, n) - 4;
//////			double long int b = pow(4, n) + n - 4;
//////			cout << a << " " << b << endl;
//////	}
//////	system("pause");
//////	return 0;
//////}
////
////class Solution {
////public:
////	/**
////	*	正数数组中的最小不可组成和
////	*	输入：正数数组arr
////	*	返回：正数数组中的最小不可组成和
////	*/
////	void isSubSet(vector<int>arr, vector<int> tag, int n, int len,int &num,vector<int> &count)
////	{
////		if (n == len)
////		{
////			int sum = 0;
////			for (int i = 0; i < len; i++){
////				if (tag[i] == 1)
////					sum += arr[i];
////			}
////			count.push_back(sum);
////		}
////		tag[n] = 0;
////		isSubSet(arr, tag, n + 1, len,num,count);
////		tag[n] = 1;
////		isSubSet(arr, tag, n + 1, len,num,count);
////	}
////
////	int getFirstUnFormedNum(vector<int> arr, int len) {
////		int min = arr[0];
////		int max=0;
////		for (auto e : arr){
////			max += e;
////			if (min > e)
////				min = e;
////		}
////		int num = min;
////		vector<int> tag(len);
////		
////		while (num<=max){
////			vector<int> count;
////			//num 在arr中没有找到相加不等于它的子集
////			isSubSet(arr, tag, 0, len, num,count);
////			num++;
////		}
////		//没找到
////		return max + 1;
////	}
////};
////
////int main(){
////	Solution s;
////	vector<int> arr;
////	arr.push_back(3);
////	arr.push_back(2);
////	arr.push_back(4);
////	int num=s.getFirstUnFormedNum(arr, 3);
////	return 0;
////}
//
////#include <iostream>
////using namespace std;
////
////// 递归
////void allSubSet(int arr[], int tag[], int n,int len)
////{
////	if (n == len)
////	{   
////		int sum=0;
////		for (int i = 0; i < len; i++){
////			if (tag[i] == 1)
////				sum += arr[i];
////		}
////			cout << sum << endl;
////			return;
////	}
////	tag[n] = 0;
////	allSubSet(arr, tag, n + 1,len);
////	tag[n] = 1;
////	allSubSet(arr, tag, n + 1,len);
////}
////
////int main(int argc, const char * argv[]) {
////
////	int a[3] = { 1, 2, 3 };
////	int tag[3];
////	
////	allSubSet(a, tag, 0,3);
////	system("pause");
////	return 0;
////}
//
//#include <set>
//class Solution {
//public:
//	int getFirstUnFormedNum(vector<int>& arr, int len) {
//		set<int> res;
//		for (int i = 0; i<len; i++)
//		{
//			set<int> tmp = res;
//			for (set<int>::iterator iter = res.begin(); iter != res.end(); iter++)
//			{
//				tmp.insert(*iter + arr[i]);
//			}
//			res = tmp;
//			res.insert(arr[i]);
//		}
//
//		set<int>::iterator iter = res.begin();
//		int before = *iter;
//		iter++;
//		for (; iter != res.end(); iter++)
//		{
//			if (*iter - before > 1)
//			{
//				return before + 1;
//			}
//			before = *iter;
//		}
//		return before + 1;
//	}
//};
//
//#include <iostream>
//#include <string>
//using namespace std;
//int main(){
//	string sou;
//	while (getline(cin,sou)){
//		string dec;
//		for (int i = 0; i < sou.size(); i++){
//			if (sou[i] == ' '){
//				dec.push_back(' ');
//				continue;
//			}
//			char num = (sou[i]-5);
//			if (num < 'A')
//				num += 26;
//			dec.push_back(num);
//		}
//		cout << dec<< endl;
//	}
//	return 0;
//}



//复杂度过高
//#include <iostream>
//#include <set>
//
//using namespace std;
//bool isPrime(int num){
//	for (int i = 2; i < num; i++){
//		if (num%i == 0)
//			return false;
//	}
//	return true;
//}
//void getDiv(int num, set<int> &Set){
//	if (num <2){
//		return;
//	}
//	if (num==2||isPrime(num)){
//		Set.insert(num);
//		return;
//	}
//	for (int i = 2; i < num; i++){
//		if (num%i == 0){
//			getDiv(i,Set);
//		}
//	}
//}
//int main(){
//	int num;
//	while (cin >> num){
//		if (num<=3||isPrime(num))  //素数直接输出0
//			cout << 0 << endl;
//		else{                        //非素数
//			set<int> Set;
//			getDiv(num, Set);
//			cout << Set.size() << endl;
//		}
//	}
//	return 0;
//}


//#include <iostream>
//#include <vector>
//using namespace std;
//bool isPrime(int num){
//	for (int i = 2; i < num; i++){
//		if (num%i == 0)
//			return false;
//	}
//	return true;
//}
//void getPrime(int num, vector<int> &arr){
//	for (int i = 2; i < num; i++){
//		if (isPrime(i))
//			arr.push_back(i);
//	}
//}
//int main(){
//	int num;
//	while (cin >> num){
//		vector<int> arr;
//		getPrime(num, arr);
//		int count = 0;
//		for (auto e : arr){
//			if (num%e == 0)
//				count++;
//		}
//		cout<<count<<endl;
//	}
//	return 0;
//}

//#include <iostream>
//#include<math.h>
//using namespace std;
//int main(){
//	int n, k, i;
//	while (cin >> n){
//		k = 0;
//		for (i = 2; i <= sqrt(n); i++){
//			if (n%i == 0){
//				while (n%i == 0){
//					n = n / i;
//				}
//				k++;
//			}
//		}
//		if (n != 1)
//			k++;
//		cout << k << endl;
//	}
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
////马丁
//int Martin(int y,int m,int d){
//	int w = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) % 7;
//	if (w == 1)
//		return d + 14;
//	else if (w == 2)
//		return d + 20;
//	else if (w == 3)
//		return d + 19;
//	else if (w == 4)
//		return d + 18;
//	else if (w == 5)
//		return d + 17;
//	else if (w == 6)
//		return d + 16;
//	else if (w == 7)
//		return d + 15;
//}
////总统
//int President(int y, int m, int d){
//	int w = (d + 2 * m+3*(m + 1) / 5 + y + y / 4 - y / 100 + y / 400+1) % 7;
//	if (w == 1)
//		return d + 14;
//	else if (w == 2)
//		return d + 20;
//	else if (w == 3)
//		return d + 19;
//	else if (w == 4)
//		return d + 18;
//	else if (w == 5)
//		return d + 17;
//	else if (w == 6)
//		return d + 16;
//	else if (w == 7)
//		return d + 15;
//}
//int Memorial(int y, int m, int d){
//	int w = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) % 7;
//	if (w == 1)
//		return d;
//	else if (w == 2)
//		return d - 1;
//	else if (w == 3)
//		return d - 2;
//	else if (w == 4)
//		return d - 3;
//	else if (w == 5)
//		return d - 4;
//	else if (w == 6)
//		return d - 5;
//	else if (w == 7)
//		return d - 6;
//}
//
//int Labour(int y, int m, int d){
//	int w = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) % 7;
//	switch (w){
//	case 1:return d; break;
//	case 2:return d+6; break;
//	case 3:return d+5; break;
//	case 4:return d+4; break;
//	case 5:return d+3; break;
//	case 6:return d+2; break;
//	case 7:return d+1; break;
//	}
//}
//int main(){
//	int year;
//	while (cin >> year){
//		//元旦
//		cout << year << "-" << "01" << "-" << "01"<< endl;
//		//马丁
//		int day=Martin(year-1,13,1);
//		cout << year << "-" << "01"<<"-" << day << endl;
//		//总统节
//		day = President(year-1, 14, 1);
//		cout << year << "-" << "02" << "-" << day << endl;
//		//阵亡将士纪念日
//		day = Memorial(year, 5, 31);
//		cout << year << "-" << "05" << "-" << day << endl;
//		//国庆
//		cout << year << "-" << "07" << "-" << "04" << endl;
//		//劳动节
//		day = Labour(year, 9, 1);
//		if (day > 9)
//			cout << year << "-" << "09" << "-" << day << endl;
//		else{
//			cout << year << "-" << "09" << "-" <<0<< day << endl;
//		}
//	}
//	return 0;
//}

//// write your code here cpp
//#include <iostream>
//#include <vector>
//#include <cmath>
//using namespace std;
//
//int main(){
//	int num;
//	while (cin >> num){
//		vector<int> s;
//		int cur = num;
//		for (int i = 2; i <= sqrt(cur); i++){
//			if (num%i == 0){
//				s.push_back(i);
//				num = num / i;
//				while (num%i == 0){
//					s.push_back(i);
//					num = num / i;
//				}
//			}
//		}
//		if (s.empty()){
//			cout << cur << " " << "=" << " " << num;
//		}
//		else{
//			cout << cur << " " << "=";
//			for (int i = 0; i < s.size() - 1; i++){
//				cout << " " << s[i] << " " << "*";
//			}
//			cout << " " << s[s.size() - 1]<<" ";
//			if (num != 1)
//				cout << "*" << " " << num;
//		}
//		cout << endl;
//	}
//	return 0;
//}


//#include <iostream>
//
//using namespace std;
//struct Data
//{
//	int year;
//	int month;
//	int day;
//};
//bool isLeap(int y){
//	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
//		return true;
//	return false;
//}
//
//int main(){
//	Data begin,end;
//	while (cin >> begin.year >> begin.month >> begin.day >> end.year >> end.month >> end.day){
//		//素数 2 3 5 7 11 每天赚1 否则每天赚2块
//		int sum = 0;
//		while (begin.year != end.year&&begin.month != end.month&&begin.day != end.day){
//
//		}
//	}
//	return 0;
//}
//#include <iostream>
//using namespace std;
//
//int main(){
//	int year1, month1, day1, year2, month2, day2;
//	int d[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	while (cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2)
//	{
//		int sum = 0;
//		int year = year1;
//
//		//时间区间有一整年
//		//先判断是否为闰年
//		for (int i = year1; i <= year2 - 1; ++i){
//			if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) 
//				sum += 580;     //平年
//			else  sum += 579;	//闰年
//		}
//
//		//起始月份的前半部分收益去掉
//		for (int i = 0; i <= month1 - 1; ++i){
//			int temp = 0;
//			if (i == month1 - 1) 
//				temp = day1 - 1;
//			else 
//				temp = d[i];
//			
//			if (i != 1 && i != 2 && i != 4 && i != 6 && i != 10){ 
//				sum -= temp * 2;
//			}
//			else 
//				sum -= temp;
//		}
//
//		//结束月份的后半部分收益去掉
//		for (int i = 0; i <= month2 - 1; ++i){
//			int temp = 0;
//			if (i == month2 - 1) 
//				temp = day2;
//			else 
//				temp = d[i];
//			if (i != 1 && i != 2 && i != 4 && i != 6 && i != 10){ 
//				sum += temp * 2;
//			}
//			else
//				sum += temp;
//		}
//
//		cout << sum << endl;
//
//	}
//
//
//	return 0;
//}

//#include <iostream>
//#include <string>
//
//using namespace std;
//
//
//int main(){
//	string s, t;
//	while (cin >> s >> t){
//		int sum = 0;         //能剪几块布
//		for (int i = 0; i < s.size(); ){
//			int j = i;
//			int o = 0;       //
//			for (auto e : t){
//				if (e == s[j]){
//					j++;
//					o++;
//				}
//				else{
//					j = i + 1;
//					break;
//				}
//				if (o == t.size())
//					sum++;
//			}
//			i = j;
//		}
//		cout << sum << endl;
//	}
//
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int main(){
//	int num;
//	while (cin>>num){
//		cin.get();
//		vector<string> NameList(num);
//		for (int i = 0; i < num; i++){
//			string name;
//			getline(cin, name);
//			NameList[i]=name;
//		}
//		for (int i = 0; i < num;i++){
//			if (string::npos!=NameList[i].find(',',0))
//				cout << '"' << NameList[i]<< '"' ;
//			else
//				cout << NameList[i];
//			if (i < num - 1)
//				cout << ',' << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}
// write your code here cpp
//#include <iostream>
//
//using namespace std;
//int main(){
//	int day;
//	while (cin >> day){
//		double long a = 1;
//		double long b = 2;
//		double long c;
//		if (day == 1){
//			cout << 1 << endl;
//			break;
//		}
//		else if (day == 2){
//			cout << 2 << endl;
//		}
//		else {
//			day -= 2;
//			while (day--){
//				c = a + b;
//				a = b;
//				b = c;
//			}
//			cout << c << endl;
//		}
//
//	}
//	return 0;
//}
//
//
//

//#include <iostream>
//
//
//using namespace std;
//double D( double num){
//	//错排的所有排法
//	if (num == 1)
//		return 0;
//	if (num == 2)
//		return 1;
//	return (num-1)*(D(num - 1) + D(num - 2));
//}
//
//double T( double num){
//	//随机排法
//	if (num == 1)
//		return 1;
//	return num*T(num - 1);
//}
//int main(){
//	register double num;
//	while (cin >> num){
//		 double False = D(num);
//		 double True = T(num);
//		 double count = False / True;
//		printf("%0.2lf%%\n", count*100);
//	}
//
//	return 0;
//}



//#include <iostream>
//#include <iomanip>
//using namespace std;
//
//
//double fac(int x)
//{
//	register double i, f = 1;  //定义寄存器变量  
//	for (int i = 1; i <= x; i++)
//		f *= i;
//	return f;
//}
//
//
//int main()
//{
//	int n;
//	long long a[21] = { 0, 0, 1 };
//	for (int i = 3; i < 21; i++)
//	{
//		a[i] = (i - 1)*(a[i - 1] + a[i - 2]);
//	}
//	while (cin >> n)
//	{
//		double tempAll = fac(n);
//		cout << fixed << setprecision(2) << (double)a[n] / tempAll * 100 << "%" << endl;
//	}
//}

//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//int main(){
//	string first, second;
//	while (getline(cin, first)&&getline(cin,second)){
//		vector<string> Namelist;
//
//		//将first中的每一个名字写入Namelist
//		auto it = first.begin();
//		while (it != first.end()){
//			if (*it == ',' || *it == ' ')
//				it++;
//			else if (*it == '"'){
//				it++;
//				string name;
//				while (*it != '"'){
//					name += *it;
//					it++;
//				}
//				Namelist.push_back(name);
//				it++;
//			}
//			else{
//				string name;
//				while (it != first.end()&&*it != ','){
//					name += *it;
//						it++;
//				}
//				if (it != first.end())
//					it++;
//				Namelist.push_back(name);
//			}
//		}
//		bool have = 0;
//		for (auto e : Namelist){
//			if (e == second){
//				have = 1;
//				break;
//			}
//		}
//		if (have)
//			cout << "Ignore" << endl;
//		else
//		cout << "Important!" << endl;
//	}
//	return 0;
//}
//

//#include <iostream>
//#include <string>
//
//struct Rat{
//	long int car; //进位
//	long int num; //分子
//	long int den; //分母
//	bool flog=1;  //标识为  1 代表非0
//};
//
//void handler(std::string &str,Rat &rat){
//	if (str[0] == 0){
//		//分子为0
//		rat.flog = 0;
//		return;
//	}
//	long int num = (str[0]-'0') % (str[2]-'0');  //分子  num
//	long int car = (str[0]-'0') / (str[2]-'0');	//进位  car
//	rat.num = num;
//	rat.car = car;
//	rat.den = (str[2]-'0');
//}
//int main(){
//	std::string lhs, rhs;
//	while (std::cin >> lhs >> rhs){
//		//  A/B C/D
//		Rat Left, Right;
//		handler(lhs,Left);
//		handler(rhs,Right);
//		//  A/B  E   C/D F
//		while (1);
//		//相加
//		std::string result_Add;
//		
//	}
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <string>
//#include <set>
//#include <map>
//using namespace std;
//map<char, int> Map;
//
//void getNumber(string &num){
//	string str;
//	for (int i = 0; i < num.size();i++){
//		if (num[i] >= '0'&&num[i] <= '9')
//			str.push_back((int)num[i]);
//		else if (num[i] == '-')
//			continue;
//		else{
//			int exp = (int)Map[num[i]];
//			str.push_back(exp);
//		}
//	}
//	num = str;
//}
//
//int main(){
//	for (char i = 'A'; i <= 'Z'; i++){
//		if (i < 'D'){
//			Map.insert(make_pair(i, 2));
//		}
//		else if (i < 'G'){
//			Map.insert(make_pair(i, 3));
//		}
//		else if (i < 'J'){
//			Map.insert(make_pair(i, 4));
//		}
//		else if (i < 'M'){
//			Map.insert(make_pair(i, 5));
//		}
//		else if (i < 'P'){
//			Map.insert(make_pair(i, 6));
//		}
//		else if (i < 'T'){
//			Map.insert(make_pair(i, 7));
//		}
//		else if (i < 'W'){
//			Map.insert(make_pair(i, 8));
//		}
//		else if (i <='Z'){
//			Map.insert(make_pair(i, 9));
//		}
//	}
//	int num;
//	while (cin >> num){
//		vector<string> PhoneNum;
//		string number;
//		for (int i = 0; i<num; i++){
//			cin >> number;
//			getNumber(number);
//			PhoneNum.push_back(number);
//		}
//		//去重
//		auto it1 = PhoneNum.begin();
//		while (it1 != PhoneNum.end()){
//			auto it2 = it1++;
//			while (it2 != PhoneNum.end()){
//				if (*it1 == *it2)
//					it2 = PhoneNum.erase(it2);
//				
//				else
//					it2++;
//			}
//			it1++;
//		}
//		for (auto e : PhoneNum){
//			for (int i = 0; i < 7; i++){
//				if (i == 3)
//					cout << "-";
//				cout << e[i];
//			}
//			cout << endl;
//		}
//	}
//	return 0;
//}
//


//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main(){
//	string str;
//	while (getline(cin, str)){
//		auto it = str.begin();
//		while (it != str.end()){
//			if (*it == '_'){
//				it = str.erase(it);
//				*it -= 32;
//			}
//			it++;
//		}
//		cout << str << endl;
//	}
//	return 0;
//}


//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//int main(){
//	string str;
//	while (getline(cin, str)){
//		vector<string> result;
//		string arr;
//		for (int i = 0; i < str.size();i++){
//			//遇到空格
//			if (str[i] == ' '){
//				if (!arr.empty()&&arr[0]!=' ')
//					result.push_back(arr);
//				arr.clear();
//			}
//			else
//				arr.push_back(str[i]);
//		}
//		result.push_back(arr);
//		reverse(result.begin(), result.end());
//		for (auto e : result){
//			cout << e << ' ';
//		}
//		cout << endl;
//	}
//	return 0;
//}


// write your code here cpp
//#include <iostream>
//#include <map>
//#include <string>
//int main(){
//	std::string A, B;
//	while (std::cin >> A >> B){
//		bool f = 1;
//		if (B.empty() || (A.empty() && B.empty())){
//			std::cout << "Yes" << std::endl;
//			continue;
//		}
//		if (A.empty()){
//			std::cout << "No" << std::endl;
//			continue;
//		}
//
//		std::map<char, int> box;
//		for (int i = 0; i < A.size(); i++){
//			box[A[i]]++;
//		}
//		for (int i = 0; i < B.size(); i++){
//			auto it = box.find(B[i]);
//			if (it != box.end()){
//				it->second--;
//			}
//			else{
//				std::cout << "NO" << std::endl;
//				f = 0;
//				break;
//			}
//		}
//		if (f == 0)
//			continue;
//		for (auto e : box){
//			if (e.second < 0){
//				std::cout << "No" << std::endl;
//				f = 0;
//				break;
//			}
//		}
//		if (f == 0)
//			continue;
//		std::cout << "Yes" << std::endl;
//	}
//	return 0;
//}



//#include <iostream>
//#include <string>
//#include <vector>
//
//int isBroStr(const char *str1,const char *str2)
//{
//	int a[26 * 2] = { 0 };
//	int i, strLen;
//	if (!str1 && !str2)
//		return 1;
//	else if (!str1 || !str2)
//		return 0;
//	else
//	{
//		if (strlen(str1) != strlen(str2))
//			return 0;
//		strLen = strlen(str1);
//		for (i = 0; i < strLen; i++)
//		{
//			++a[str1[i] - 'A'];
//			--a[str2[i] - 'A'];
//		}
//		for (i = 0; i < 26 * 2; i++)
//		if (a[i])
//			return 0;
//		return 1;
//	}
//}
//
//void GetBroWord(std::vector<std::string> dict, std::string key, std::vector<std::string>& res){
//	for (auto D : dict){
//		if (D.size() != key.size())
//			continue;
//		if (D == key)
//			continue;
//		const char *s = D.c_str();
//		const char *c = key.c_str();
//		if (isBroStr(s, c))
//			res.push_back(D);
//	}
//
//}
//
//int main(){
//	int n;
//	while (std::cin >> n){
//		//给字典中添加单词
//		std::vector<std::string> dict;
//		for (int i = 0; i < n; i++){
//			std::string word;
//			std::cin >> word;
//			//if (dict.empty())
//			dict.push_back(word);
//			/*else{
//				auto it = dict.begin();
//				while (it != dict.end())
//				{
//					if (word < *it){
//						dict.insert(it, 1, word);
//						break;
//					}
//					
//				}
//			}*/
//		}
//		//开始搜索
//		std::string key;
//		int num;
//		std::cin >> key >> num;
//		std::vector<std::string> result;
//		GetBroWord(dict, key, result);
//		std::cout << result.size() << " " << result[num - 1] << std::endl;
//	}
//
//	return 0;
//}
//#include <iostream>
//#include <map>
//#include <vector>
//
//class Solution {
//public:
//	int MoreThanHalfNum_Solution(std::vector<int> numbers) {
//		std::map<int,int> Map;
//		int sz = numbers.size();
//		for (int i = 0; i<numbers.size(); i++){
//			Map[numbers[i]]++;
//		}
//		for (auto e : Map){
//			if (e.second >= (sz / 2))
//				return e.first;
//		}
//		return 0;
//	}
//};
//
//int main(){
//	std::vector<int> numbers = {1,2,3,2,2,2,5,4,2};
//	Solution s;
//	
//	std::cout<<s.MoreThanHalfNum_Solution(numbers)<<std::endl;
//	system("pause");
//	return 0;
//}
//
//#include <iostream>
//#include <map>
//#include <string>
//
//
//void getStr(std::string &req){
//	std::string str;
//	auto it = req.rbegin();
//
//	while (it != req.rend() && (str.size() < 17)){
//		if (*it == '\\')
//			break;
//		str += *it;
//		it++;
//	}
//	reverse(str.begin(), str.end());
//	req = str;
//}
//
//int main(){
//	std::map<int, std::string> Map;
//	std::map<int, int> Fal;
//	std::string req;
//	int num;
//	while (std::cin >> req >> num){
//		getStr(req);
//		if (Map.empty()){
//			Map.insert(make_pair(num,req));
//			Fal[num]++;
//			continue;
//		}
//		bool f = 0;
//		for (auto e : Map){
//			if (e.first == num&&e.second == req){
//				f = 1;
//				break;
//			}
//		}
//		if (f)
//			continue;
//		Map.insert(make_pair(num, req));
//		Fal[num]++;
//		if (Map.size() == 8){
//			for (auto e : Map){
//				std::cout << e.second << " " << e.first << " " << Fal[e.first] << std::endl;
//			}
//		}
//	}
//	return 0;
//}

//using namespace std;
//class Solution {
//public:
//	int uniquePaths(int m, int n) {
//		if (m == 0 || n == 0)
//			return 1;
//		else
//			return uniquePaths(m - 2, n-1) + uniquePaths(m-1, n - 2);
//	}
//};
//
//int main(){
//	Solution s;
//	cout << s.uniquePaths(2,3) << endl;;
//	system("pause");
//	return 0;
//}



//class Solution {
//public:
//	bool wordBreak(string s, unordered_set<string> &dict) {
//		if (s.empty()){
//			return false;
//		}
//		if (dict.empty())
//			return false;
//		vector<bool> F(s.size() + 1, false);
//		F[0] = true;
//		for (int i = 1; i <= s.size(); i++){
//			for (int j = 0; j<i; j++){
//				if (F[j] && dict.find(s.substr(j, i - j)) != dict.end()){
//					F[i] = true;
//					break;
//				}
//			}
//		}
//		return F[s.size()];
//	}
//};



//#include <iostream>
//#include <vector>
//class MaxGap {
//public:
//	int getmax(std::vector<int> A, int n)
//	{
//		int max = A[n];
//		for (int i = n; i < A.size(); i++){
//			if (max < A[i])
//				max = A[i];
//		}
//		return max;
//	}
//	int findMaxGap(std::vector<int> A, int n) {
//		// write code here
//		int Left_max=0;
//		int result = 0,max_result=0;
//		for (int i = 0; i < n-1; i++){
//			if (Left_max<= A[i])
//				Left_max = A[i];
//			int right_max = getmax(A, i+1);
//			result = abs(Left_max - right_max);
//			if (result>max_result)
//				max_result = result;
//		}
//		return max_result;
//	}
//};
//
//int main(){
//	MaxGap s;
//	std::vector<int> A = { 2, 7, 3, 1, 1 };
//	std::cout<<s.findMaxGap(A, 5)<<std::endl;
//	system("pause");
//	return 0;
//}
//
//#include <iostream>
//#include <vector>
//
//#include <algorithm>
//using namespace std;
//class Solution {
//public:
//	int minimumTotal(vector<vector<int> > &triangle) {
//		if (triangle.empty())
//			return 0;
//		int row = triangle.size();
//		vector<vector<int>> F(triangle);
//		for (int i = 1; i<row; i++){
//			for (int j = 0; j<=i; j++){
//				if (j == 0)
//					F[i][j] = F[i-1][j] + triangle[i][j];
//				else if (j == i)
//					F[i][j] = F[i - 1][j - 1] + triangle[i][j];
//				else
//					F[i][j] = min(F[i-1][j] + triangle[i][j], F[i - 1][j - 1] + triangle[i][j]);
//			}
//		}
//		int min_result = F[row-1][0];
//		for (int j = 1; j < row; ++j){
//			min_result = min(min_result, F[row - 1][j]);
//		}
//		return min_result;
//	}
//};
//
//int main(){
//	vector<vector<int> > triangle(4, vector<int>(4, 0));
//	triangle[0] = {2};
//	triangle[1] = {3,4};
//	triangle[2] = {6,5,7};
//	triangle[3] = {4,1,3,8};
//	Solution s;
//	cout<<s.minimumTotal(triangle)<<endl;
//	system("pause");
//	return 0;
//}



//#include <iostream>
//#include <vector>
//
//#include <algorithm>
//using namespace std;
//
//
////背包问题
//class Solution {
//public:
//	/**
//	* @param m: An integer m denotes the size of a backpack
//	* @param A: Given n items with size A[i]
//	* @param V: Given n items with value V[i]
//	* @return: The maximum value
//	*/
//	int backPackII(int m, vector<int> &A, vector<int> &V) {
//		// write your code here
//		if (A.empty())
//			return 0;
//		vector<vector<int>> F(A.size()+1, vector<int>(m+1, 0));
//
//		for (int i = 1; i < A.size()+1; i++){
//			for (int j = 1; j <= m; j++){
//				if (A[i - 1]>j)
//					F[i][j] = F[i - 1][j];
//				else
//					F[i][j] = max(F[i - 1][j - A[i - 1]] + V[i - 1], F[i - 1][j]);
//			}
//
//		}
//		return F[A.size() + 1][m];
//	}
//};


#include <iostream>

using namespace std;
//void TestFor()
//{
//	int array[] = { 1, 2, 3, 4, 5 };
//	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
//		array[i] *= 2;
//	for (int* p = array; p < array + sizeof(array) / sizeof(array[0]); ++p)
//		std::cout << *p << std::endl;
//}
//
//int main(){
//	TestFor();
//	system("pause");
//	return 0;
//}

void f(int)
{
	cout << "f(int)" << endl;
}
void f(int*)
{
	cout << "f(int*)" << endl;
}
int main()
{
	f(0);
	f(NULL);
	f((int*)NULL);
	system("pause");
	return 0;
}