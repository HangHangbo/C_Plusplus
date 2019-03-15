//求1+2+3+4+...+n不使用for while if else switch case 等关键字和判断语句
#include<iostream>
using namespace std;
class Solution {
public:
	class Sum{
	public:
		Sum()
		{
			_sum += _i;
			++_i;
		}
	};
	int Sum_Solution(int n) {
		_sum = 0;
		_i = 1;
		
		Sum arr[5];
		return _sum;
	}
private:
	static int _sum;
	static int _i;
};

int Solution::_sum = 0;
int Solution::_i = 1;
//int main()
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
