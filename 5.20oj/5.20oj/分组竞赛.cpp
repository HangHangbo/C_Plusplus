#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	vector<long> s(3*n);
	for (int i = 0; i < n * 3; i++)
	{
		cin >> s[i];
	}
	sort(s.begin(), s.end());
	long sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += s[3*n-2*i];
	}
	cout << sum << endl;
	system("pause");
	return 0;
}