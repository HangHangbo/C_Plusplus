#include<iostream>
using namespace std;

class Solution {
public:
	int jumpFloorII(int number) {
		if (number == 0 || number == 1)
		{
			return number;
		}
		int count = 0;
		count = 2 * jumpFloorII(number - 1);
		return count;
	}
	int jumpFloor(int number) {
		////µÝ¹é
		//if (number == 1 || number == 2)
		//	return number;
		//return (jumpFloor(number-1)+jumpFloor(number-2));

		//·ÇµÝ¹é
		if (number <= 2)
			return number;
		int lastOne = 2;
		int lastTwo = 1;
		int result = 0;
		for (int i = 3; i <= number; i++)
		{
			result = lastOne + lastTwo;
			lastTwo = lastOne;
			lastOne = result;
		}
		return result;
	}
};
int main()
{
	Solution s;
	cout<<s.jumpFloor(5)<<endl;
	system("pause");
	return 0;
}