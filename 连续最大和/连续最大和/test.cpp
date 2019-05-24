#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	vector<int> s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		s.push_back(num);
	}
	int max_sum = s[0];
	for (int i = 0; i < s.size();i++)
	{
		int j = i;
		int sum=0;
		while (j<s.size())
		{
			sum += s[j++];
			if (sum > max_sum)
				max_sum = sum;
		}
		
	}
	cout << max_sum << endl;
	system("pause");
	return 0;
}