#include<iostream>
using namespace std;
#include<string>




////求1+2+3+4+...+n不使用for while if else switch case 等关键字和判断语句

//class Solution {
//public:
//	class Sum{
//	public:
//		Sum()
//		{
//			_sum += _i;
//			++_i;
//		}
//	};
//	int Sum_Solution(int n) {
//		_sum = 0;
//		_i = 1;
//		
//		Sum arr[5];
//		return _sum;
//	}
//private:
//	static int _sum;
//	static int _i;
//};
//
//int Solution::_sum = 0;
//int Solution::_i = 1;
////int main()
//{
//	Solution s;
//	cout << s.Sum_Solution(0) << endl;
//	system("pause");
//	return 0;
//}

//日期计算OJ

/*
int main()
{
	int days[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
	int year, month, day;
	cin >> year >> month >> day;
	int value = days[month - 1] + day;
	if (month>2){
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
			value += 1;
		}
		}
		cout << value << endl;
		system("pause");
		return 0;
	}*/

//int main()
//{/*
//	char a[] = "烫烫烫";
//	char b[5];
//	b[0] = -52;
//	b[1] = -52;
//	b[2] = -52;
//	b[3] = -52;
//	cout << b << endl;*/
//	vector<int>v;
//
//	system("pause");
//	return 0;
//}

//
////字符串转为整型输出
//class Solution {
//public:
//	int StrToInt(string str) {
//		//判断字符串是否为空，为空返回0
//		if (str.empty())
//			return 0;
//		//字符转数字  -'0'
//		
//		string::iterator it = str.begin();   //定义it迭代器定义访问字符串 
//		int value = 0;                      //存放整型
//		int flag = 1;
//		while (it != str.end()){
//			value *= 10;
//			if (*it >= '0' && *it<'9'){
//				value += *it - '0';
//			}
//			else if (*it == '-' || *it == '+'){  //判断正负
//				if (*it == '-'){
//					flag = -1;
//				}
//			}
//			else{
//				return 0;
//			}
//			++it;
//		}
//		return value*flag;
//	}
//
//
//};
 
//给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
//
//注意：
//
//num1 和num2 的长度都小于 5100.
//num1 和num2 都只包含数字 0 - 9.
//num1 和num2 都不包含任何前导零。
//你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。


class Solution {
public:
	string addStrings(string num1, string num2) {
		int len1 = num1.length()-1;
		int len2 = num2.length()-1;
		string num3;  
		int carray = 0;
		int sum = 0;
		while (len1 >= 0 || len2 >= 0) {
			int a = num1[len1] - '0';
			int b = num2[len2] - '0';
			 sum = 0;
				sum+= carray;
			if (len1 >= 0){
				sum += a;
			}
			if (len1 >= 0){
				sum += b;
			}
			if (sum > 9){
				carray = 1;
				sum -= 10;
			}
			else
			{
				carray = 0;
			}
			num3 += sum + '0';


			//int sum = a + b + carray;
			//carray = sum >= 10 ? 1 : 0;
			//sum = sum - 10;   //sum的范围为0~18 %运算比较耗时 使用 -更方便
			//char c = '0' + sum; //将当前为转为字符型
			//num3 += c;         //逆行存储
			////int sum;
			////num3.insert(0, 1, sum + '0');  //头插
			len1--;
			len2--;
		}
		if (carray == 1){
			num3.insert(0, 1, '1');
		}
	/*	if (len1 == 0) {
			for (int i = len2; i > 0; i--) {
				int b = num2[i - 1] - '0';
				int sum = b + carray;
				carray = sum >= 10 ? 1 : 0;
				sum = sum % 10;
				char c = '0' + sum;
				num3 += c;
			}
			if (carray == 1) num3 += '1';
		}
		else if (len2 == 0) {
			for (int i = len1; i > 0; i--) {
				int b = num1[i - 1] - '0';
				int sum = b + carray;
				carray = sum >= 10 ? 1 : 0;
				sum = sum % 10;
				char c = '0' + sum;
				num3 += c;
			}
			if (carray == 1) num3 += '1';
		}*/
		//反转
		/*int len3 = num3.length();
		for (int i = 0; i <= (len3 - 1) / 2; i++) {
			char c = num3[i];
			num3[i] = num3[len3 - 1 - i];
			num3[len3 - 1 - i] = c;
		}*/
		reverse(num3.begin(),num3.end());
		return num3;
	}
};

////翻转字符串
//
//string reverseString(string s)
//{
//	size_t start = 0;
//	size_t end = s.size() - 1;
//	while (start < end){
//		swap(s[start], s[end]);
//		start++;
//		end--;
//	}
//	return s;
//}


////字符串中的一个唯一的字符.1
//
//class Solution {
//public:
//	int firstUniqChar(string s) {
//		int count[26] = { 0 };
//		int size = s.size();
//		for (auto& e : s){
//			count[e-'a']++;
//		}
//		for (int i = 0; i < s.size(); i++){
//			if (count[s[i]-'a'] == 1)
//				return i;
//		}
//		return -1;
//	}
//};


//字符串中的一个唯一的字符.2
//
//#include<iostream>
//using namespace std;
//#include<string>
//int main()
//{	string s;
//	while (getline(cin,s))
//	{
//		int hashtable[256] = { 0 };
//		bool flag = false;
//		for (auto& e : s)
//		{
//			hashtable[e]++;
//		}
//
//		for (int i = 0; i < s.size(); i++)
//		{
//			if (hashtable[s[i]] == 1){
//				cout << s[i] << endl;
//				flag = true;
//				break;
//			}
//		}
//		if (flag == false)
//			cout << "-1" << endl;
//	}
//	return 0;
//}



////输出最后一个单词的长度
//
//int main()
//{
//	string s;
//	while (cin >> s){
//		size_t pos = s.rfind(' ');
//		if (pos == string::npos){
//			cout << s.size() << endl;
//		}
//		else{
//			cout << s.size() - pos - 1 << endl;
//		}
//		}
//	return 0;
//}

////给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
////说明：本题中，我们将空字符串定义为有效的回文串。
//class Solution {
//public:
//	bool Isnumberorletter(char x){
//		
//		return (x > '0' && x<'9') || (x>'a' && x<'z') || (x>'A'&&x < 'Z');
//			;
//	}
//	bool isPalindrome(string s) {
//		if (s.empty()){
//			return true;
//		}
//		int begin = 0;
//		int end = s.size() - 1;
//		//将小写转为大写
//		/*for (auto &e: s){
//			if (e>= 'a')
//			e-=32;
//		}*/
//		while (begin < end){
//			while (begin != end){                 //从前向后找第一个字符
//				if (Isnumberorletter(s[begin])){
//					break;
//					++begin;
//				}
//				while (end != begin){             //从后向前找第一个字符
//					if (Isnumberorletter(s[end]))
//						break;
//					--end;
//				}
//				if (begin < end)
//				{
//					// 检测begin和end位置字符是否相等 或者是否不区分大小的相等
//					//大小写字母码值相差32   先加上32 后再减去 ‘a’ 数字就会变为负数  %32 后大小写相同
//				
//				if((s[begin]+32-'a')%32!=(s[end]+32-'a')%32)
//					
//
//			//小写换打写后直接比较
//			/*	if (s[begin] != s[end])*/
//
//
//					return false;
//					++begin;
//					--end;
//				}
//
//				return true;
//			}
//		}
//	}
//};

int main()
{
	Solution solu;
	string s;
	string c;
	while (cin>>s>>c){
		cout << solu.addStrings(s,c);
	}

	system("pause");
	return 0;
}