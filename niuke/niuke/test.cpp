#include<iostream>
using namespace std;
#include<string>
#include<vector>



////��1+2+3+4+...+n��ʹ��for while if else switch case �ȹؼ��ֺ��ж����

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

//���ڼ���OJ

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
//	char a[] = "������";
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
////�ַ���תΪ�������
//class Solution {
//public:
//	int StrToInt(string str) {
//		//�ж��ַ����Ƿ�Ϊ�գ�Ϊ�շ���0
//		if (str.empty())
//			return 0;
//		//�ַ�ת����  -'0'
//		
//		string::iterator it = str.begin();   //����it��������������ַ��� 
//		int value = 0;                      //�������
//		int flag = 1;
//		while (it != str.end()){
//			value *= 10;
//			if (*it >= '0' && *it<'9'){
//				value += *it - '0';
//			}
//			else if (*it == '-' || *it == '+'){  //�ж�����
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
 
//���������ַ�����ʽ�ķǸ����� num1 ��num2 ���������ǵĺ͡�
//
//ע�⣺
//
//num1 ��num2 �ĳ��ȶ�С�� 5100.
//num1 ��num2 ��ֻ�������� 0 - 9.
//num1 ��num2 ���������κ�ǰ���㡣
//�㲻��ʹ���κ΃Ƚ� BigInteger �⣬ Ҳ����ֱ�ӽ�������ַ���ת��Ϊ������ʽ��

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
//			//sum = sum - 10;   //sum�ķ�ΧΪ0~18 %����ȽϺ�ʱ ʹ�� -������
//			//char c = '0' + sum; //����ǰΪתΪ�ַ���
//			//num3 += c;         //���д洢
//			////int sum;
//			////num3.insert(0, 1, sum + '0');  //ͷ��
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
		//��ת
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

////��ת�ַ���
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


////�ַ����е�һ��Ψһ���ַ�.1
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


//�ַ����е�һ��Ψһ���ַ�.2
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



////������һ�����ʵĳ���
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

////����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��
////˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���
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
//		//��СдתΪ��д
//		/*for (auto &e: s){
//			if (e>= 'a')
//			e-=32;
//		}*/
//		while (begin < end){
//			while (begin != end){                 //��ǰ����ҵ�һ���ַ�
//				if (Isnumberorletter(s[begin])){
//					break;
//					++begin;
//				}
//				while (end != begin){             //�Ӻ���ǰ�ҵ�һ���ַ�
//					if (Isnumberorletter(s[end]))
//						break;
//					--end;
//				}
//				if (begin < end)
//				{
//					// ���begin��endλ���ַ��Ƿ���� �����Ƿ����ִ�С�����
//					//��Сд��ĸ��ֵ���32   �ȼ���32 ���ټ�ȥ ��a�� ���־ͻ��Ϊ����  %32 ���Сд��ͬ
//				
//				if((s[begin]+32-'a')%32!=(s[end]+32-'a')%32)
//					
//
//			//Сд����д��ֱ�ӱȽ�
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


//����һ������������ 2-9 ���ַ����������������ܱ�ʾ����ĸ��ϡ�

//�������ֵ���ĸ��ӳ�����£���绰������ͬ����ע�� 1 ����Ӧ�κ���ĸ��

//�ݹ�˼��
//
//class Solution {
//	string mapLetter[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
//public:
//	void combination(string& digits, int depth, const string& comStr, vector<string>& strVec)
//	{
//		//�ж��Ƿ��������һ��
//		if (digits.size() == depth)
//		{
//			strVec.push_back(comStr);
//			return;
//		}
//		//��ȡ��ǰ������ӳ��
//		int mapNum = digits[depth] - '0';
//		string letters = mapLetter[mapNum];
//		//��ǰ����������ÿһ��ӳ����ĸ����:'a''b''c'......
//		for (auto& e : letters)
//		{
//			combination(digits, depth + 1, comStr + e, strVec);
//		}
//	}
//	vector<string> letterCombinations(string digits) 
//	{
//		vector<string> strVec;
//		size_t depth = 0;
//		if (digits.empty())  //�Ƿ�ӳ����ɣ�����strVec
//			return strVec;
//		string comStr;
//		combination(digits, depth, comStr, strVec);  //digits ���������  depth  ͳ�Ƶݹ����   comStr  ��¼ӳ����   strVec ���ߵ����һ�����ڷ���ӳ����
//  		return strVec;
//	}
//};


//����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ����������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ��
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

//����һ���������� nums������ǡ��������Ԫ��ֻ����һ�Σ���������Ԫ�ؾ��������Ρ� �ҳ�ֻ����һ�ε�������Ԫ�ء�
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

//�������

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> Matrix;
		//����numRows��
		//
		Matra

	}
};