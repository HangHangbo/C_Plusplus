#include<iostream>
using namespace std;

class Solution {
public:
	int  NumberOf1(int n) {
		int count = 0;
		for (int i = 0; i<32; i++)
		{
			if ((n >> i & 1) == 1)
				count++;
		}
		return count;
	}
};
int main()
{
	Solution s;
	cout << s.NumberOf1(3) << endl;
	system("pause");
	return 0;
}