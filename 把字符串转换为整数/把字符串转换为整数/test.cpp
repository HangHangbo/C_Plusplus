#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int StrToInt(string str) {
		int result = 0;
		int flag;
		if (str[0] == '-')
			flag = -1;
		else if(str[0] == '+')
			flag = 1;
		else if (str[0] <= '9'&&str[0] >= '0')
		{
			result =(str[0] - '0');
		}
		else{
			return 0;
		}
		for (size_t i = 1; i<str.size(); i++)
		{
			if (str[i] <= '9'&&str[i] >= '0')
			{
				result = result * 10 + (str[i] - '0');
			}
			else{
				return 0;
			}
		}
		return result*flag;
	}
};

//int main()
//{
//	Solution s;
//	string s1;
//	cin >> s1;
//	int n=s.StrToInt(s1);
//	return 0;
//}
int main()
{
	int a = 4;
	int b = 5;
	b = a--;
	return 0;
}