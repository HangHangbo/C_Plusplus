#include<iostream>
using namespace std;
#include<string>
#include<vector>



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

//
//class Solution {
//public:
//	string addStrings(string num1, string num2) {
//		int len1 = num1.length()-1;
//		int len2 = num2.length()-1;
//		string num3;  
//		int carray = 0;
//		int sum = 0;
//		while (len1 >= 0 || len2 >= 0) {
//			int a = num1[len1] - '0';
//			int b = num2[len2] - '0';
//			 sum = 0;
//				sum+= carray;
//			if (len1 >= 0){
//				sum += a;
//			}
//			if (len1 >= 0){
//				sum += b;
//			}
//			if (sum > 9){
//				carray = 1;
//				sum -= 10;
//			}
//			else
//			{
//				carray = 0;
//			}
//			num3 += sum + '0';
//
//
//			//int sum = a + b + carray;
//			//carray = sum >= 10 ? 1 : 0;
//			//sum = sum - 10;   //sum的范围为0~18 %运算比较耗时 使用 -更方便
//			//char c = '0' + sum; //将当前为转为字符型
//			//num3 += c;         //逆行存储
//			////int sum;
//			////num3.insert(0, 1, sum + '0');  //头插
//			len1--;
//			len2--;
//		}
//		if (carray == 1){
//			num3.insert(0, 1, '1');
//		}
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
//		reverse(num3.begin(),num3.end());
//		return num3;
//	}
//};

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

//int main()
//{
//	Solution solu;
//	string s;
//	string c;
//	while (cin>>s>>c){
//		cout << solu.addStrings(s,c);
//	}
//
//	system("pause");
//	return 0;
//}


//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

//给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

//递归思想
//
//class Solution {
//	string mapLetter[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
//public:
//	void combination(string& digits, int depth, const string& comStr, vector<string>& strVec)
//	{
//		//判断是否走完最后一层
//		if (digits.size() == depth)
//		{
//			strVec.push_back(comStr);
//			return;
//		}
//		//获取当前层数的映射
//		int mapNum = digits[depth] - '0';
//		string letters = mapLetter[mapNum];
//		//当前层数的数字每一个映射字母相结合:'a''b''c'......
//		for (auto& e : letters)
//		{
//			combination(digits, depth + 1, comStr + e, strVec);
//		}
//	}
//	vector<string> letterCombinations(string digits) 
//	{
//		vector<string> strVec;
//		size_t depth = 0;
//		if (digits.empty())  //是否映射完成，返回strVec
//			return strVec;
//		string comStr;
//		combination(digits, depth, comStr, strVec);  //digits 输入的数字  depth  统计递归深度   comStr  记录映射结果   strVec 当走到最后一层用于返回映射结果
//  		return strVec;
//	}
//};


//给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int result = 0;
		for (int i = 0; i<32; i++){
			int mask = 1 << i;
			int count = 0;
			for (int j = 0; j<nums.size(); j++){
				if ((mask&nums[j]) != 0)
					count++;
			}
			if (count % 3 == 1)
				result = mask | result;
		}
		return result;

	}
};

//给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int a = 0, b = 0, c = 0;
		for (auto& x : nums)
			a ^= x;
		a = a&~(a - 1);
		for (auto& x : nums)
		if (x&a) b ^= x;
		else c ^= x;
		return{ b, c };

	}
};

//杨辉三角

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> Matrix;
		//分配numRows行
		//
		Matra

	}
};