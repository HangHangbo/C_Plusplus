#include <iostream>

using namespace std;
class UnusualAdd {
public:
	void GetBinArr(int a,int *arr)
	{
		for (int i = 0; i < 32; i++)
		{
			if (a & 1 == 1)
				arr[i] = 1;
			else
				arr[i] = 0;
			a = a >> 1;
		}
	}
	int Add(int *a, int*b)
	{
		int x=0;
		int flag = 0;
		int c[32] = { 0 };
		for (int i = 0; i < 32; i++)
		{
			if (flag == 0)
			{
				if ((a[i] == 1 && b[i] != 1) || (a[i] != 1 && b[i] == 1))
				{
					c[i] = 1;
					flag = 0;
				}
				else if (a[i] == 1 && b[i] == 1)
				{
					c[i] = 0;
					flag = 1;
				}
				else if (a[i] != 1 && b[i]!=1)
				{
					c[i] = 0;
					flag = 0;
				}
			}
			else if (flag == 1)
			{
				if ((a[i] == 1 && b[i] != 1) || (a[i] != 1 && b[i] == 1))
				{
					c[i] = 0;
					flag = 1;
				}
				else if (a[i] == 1 && b[i] == 1)
				{
					c[i] = 1;
					flag = 1;
				}
				else if (a[i] != 1 && b[i] != 1)
				{
					c[i] = 1;
					flag = 0;

				}
			}
			c[i] = c[i] << i;
		}
		for (int i = 0; i < 32; i++)
		{
			x = x | c[i];
		}
		return x;
	}
	int addAB(int A, int B) {
		//if (A == 0 && B != 0)
		//	return B;
		//else if (A != 0 && B == 0)
		//	return A;
		//else if (A == 0 && B == 0)
		//	return 0;
		//// write code here
		//int a[32] = { 0 };
		//int b[32] = { 0 };
		//GetBinArr(A,a);
		//GetBinArr(B,b);
		//return Add(a, b);
		while (A)
		{
			int tmp = B;
			B = A^B;
			A = A&tmp;
			A <<= 1;
		}
		return B;
	}
};
int main()
{
	int a, b;
	cin >> a >> b;
	UnusualAdd s;
	cout<<s.addAB(a, b)<<endl;
	system("pause");
	return 0;
}