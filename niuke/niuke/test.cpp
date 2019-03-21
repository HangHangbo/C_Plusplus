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


//class Solution {
//public:
//	string addStrings(string num1, string num2) {
//		
//
//	}
//};

//翻转字符串

string reverseString(string s)
{
	size_t start = 0;
	size_t end = s.size() - 1;
	while (start < end){
		swap(s[start], s[end]);
		start++;
		end--;
	}
	return s;
}


//字符串中的一个唯一的字符.1

class Solution {
public:
	int firstUniqChar(string s) {
		int count[26] = { 0 };
		int size = s.size();
		for (auto& e : s){
			count[e-'a']++;
		}
		for (int i = 0; i < s.size(); i++){
			if (count[s[i]-'a'] == 1)
				return i;
		}
		return -1;
	}
};


//字符串中的一个唯一的字符.2





//输出最后一个单词的长度

int main()
{
	string s;
	while (cin >> s){
		size_t pos = s.rfind(' ');
		if (pos == string::npos){
			cout << s.size() << endl;
		}
		else{
			cout << s.size() - pos - 1 << endl;
		}
		}
	return 0;
}