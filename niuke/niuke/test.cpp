////��1+2+3+4+...+n��ʹ��for while if else switch case �ȹؼ��ֺ��ж����
//#include<iostream>
//using namespace std;
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
#include<iostream>
#include<string>
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
//private:
//
//};
 
class Solution {
public:
	int value(string x)
	{
		if (x.empty()){
			return 0;
			{
				string::iterator it = x.rbegin();
				int a = *it - '0';
				++it;
				while (it != rend){
					a += (*it - '0') * 10;
					++it;
				}
				return a;
			}
			string addStrings(string num1, string num2) {

				int value1 = value(num1);
				int value2 = value(num2);
				return value1 + value2;
			}
		};