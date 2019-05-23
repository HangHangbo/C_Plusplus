#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int num[4] = { 0 };
	for (int i = 0; i < 4; i++)
	{
		cin >> num[i];
	}
	int A, B, C;
	A = (num[0] + num[2]) / 2;
	B = (num[1] + num[3]) / 2;
	C = B - num[1];
	if ((num[0]==A-B) && (num[1]==B-C) && (num[2]==A+B)&&(num[3]==B+C))
	{
		cout << A << ' ' << B << ' ' << C << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	system("pause");
	return 0;
}