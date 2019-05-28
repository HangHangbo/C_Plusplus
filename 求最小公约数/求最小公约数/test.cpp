#include <iostream>

using namespace std;
int main()
{
	int A, B=0;
	cin >> A >> B;
	int factor, max_factor = 1;
	int multiple, min_multiple = 0;
	for (int i = 1; i <= A&&i <= B; i++)
	{
		if (A%i == 0 && B%i == 0)
		{
			factor = i;
		}
		if (factor >= max_factor)
			max_factor = factor;
	}
	multiple = A*B;
	min_multiple = multiple / max_factor;
	cout << min_multiple << endl;
	system("pause");
	return 0;
}