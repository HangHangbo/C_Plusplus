#include<iostream>
using namespace std;
class Solution {
public:
	//�ݹ�д��

	//int Fibonacci(int n) {
	//	if (n <= 0)
	//	{
	//		return 0;
	//	}
	//	if (n == 1)
	//	{
	//		return 1;
	//	}
	//	return (Fibonacci(n - 1) + Fibonacci(n - 2));
	//}

	//�ǵݹ�д��
	int Fibonacci(int n){
		if (n <= 0)
			return 0;
		if (n == 1)
			return 1;
		int n1 = 0;
		int n2 = 1;
		int n3 = 0;
		while (n > 1)
		{
			n3 = n1 + n2;
			n1 = n2;
			n2 = n3;
			
			n--;
		}
		return n3;
	}
};
int main()
{
	Solution s;
	cout << s.Fibonacci(8) << endl;
	system("pause");
	return 0;
}