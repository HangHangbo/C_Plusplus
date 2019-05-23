#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
	int M, N;
	while(cin >> M >> N)
	{
	string s;
	int num = 0;
	char n;
	
	while (M)
	{
		if (M < 0)
		{
			M = -M;
			cout << "-";
		}
		num = M % N;

		if (num <= 9)
		{
			n = num + '0';
		}
		else
		{
			n = num - 10 + 'A';
		}
		M = M / N;
		s.push_back(n);
	}
	reverse(s.begin(), s.end());
	cout << s << endl;
}
	system("pause");
	return 0;
}