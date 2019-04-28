#include<iostream>

using namespace std;

class Solution {
public:
	int rectCover(int number) {
		if (number<1)
			return 0;
		if (number * 2 == 2)
			return 1;
		else if (number * 2 == 4)
			return 2;
		else{
			return rectCover(number - 1) + rectCover(number - 2);
		}
	}
};
int main()
{
	Solution s;
	cout << s.rectCover(4) << endl;
	system("pause");
	return 0;
}