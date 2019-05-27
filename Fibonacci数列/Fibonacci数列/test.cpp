#include <iostream>
using namespace std;

int main()
{
	int N=0;
	cin >> N;
	int prev = 0;
	int next = 1;
	int after=prev+next;
	while (N >= next)
	{
		after = prev + next;
		if (N <= after)
			break;
		prev = next;
		next = after;
	}
	int min_count = 0;
	if ((N - next) > (after - N))
	{
		cout << after - N << endl;
	}
	else
	{
		cout << N - next << endl;
	}
	system("pause");
	return 0;
}