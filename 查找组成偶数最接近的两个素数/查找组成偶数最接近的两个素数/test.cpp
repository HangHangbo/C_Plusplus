#include <iostream>
using namespace std;

//判断一个数是否为素数
bool isPrime(const int a)
{
	for (int i = 2; i <= a / 2; i++)
	{
		if (a % i == 0)
			return 0;
	}
	return 1;
}

int main()
{
	int b;
	while (cin >> b)
	{

		//非偶数异常输入
		while (b % 2 != 0)
			return 0;

		int j, distance, t = 0;
		int min = 0;
		for (j = 2; j <= b / 2; j++)
		{
			if (isPrime(j) && isPrime(b - j))
			{
				distance = b - j - j;
				if (min == 0 || min > distance)
				{
					min = distance;
					t = j;
				}
			}
		}
		cout << t << endl;
		cout << (b - t) << endl;
	}
	system("pause");
	return 0;
}