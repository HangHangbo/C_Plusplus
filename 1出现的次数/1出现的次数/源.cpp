#include<iostream>

using namespace std;
//class Solution {
//public:
//	int Fun(int n)
//	{
//		int sum = 0;
//		while (n)
//		{
//			if (n % 10 == 1)
//			{
//				sum++;
//			}
//			n = n / 10;
//			
//		}
//		return sum;
//	}
//	int NumberOf1Between1AndN_Solution(int n)
//	{
//		int sum = 0;
//		for (int i = 1; i <= n; i++)
//		{
//			sum+=Fun(i);
//		}
//		return sum;
//	}
//};
//int main()
//{
//	Solution s;
//	cout<<s.NumberOf1Between1AndN_Solution(13) << endl;
//	system("pause");
//	return 0;
//}

#include <stdio.h>
int main()
{
	char c[2][5] = { "6934", "8254" }, *p[2];
	int i, j, s = 0;
	for (i = 0; i < 2; i++)
	{
		p[i] = c[i];
	}
	
	for (i = 0; i<2; i ++)
	for (j = 0; p[i][j]>0 && p[i][j] <= '9'; j += 2)
		s = 10 * s + p[i][j] - '0';
	printf("%d\n", s);
	system("pause");
	return 0;
}