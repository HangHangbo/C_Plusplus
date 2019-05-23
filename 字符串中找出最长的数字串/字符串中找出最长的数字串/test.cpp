#include <iostream>
#include <string>

using namespace std;
int main()
{
	string s;
	while (cin >> s)
	{
		int i = 0;
		string max;
		string v;
		int maxsize = 0;
		for (i; i < s.size();i++)
		{
			if (s[i] >= '0'&&s[i] <= '9')
			{
				while (s[i] >= '0'&& s[i] <= '9')
				{
					v += s[i++];
				}
				if (maxsize <= v.size())
				{
					max = v;
					maxsize = v.size();
				}
			}
			v.clear();
		}
		cout << max;
	}
	system("pause");
	return 0;
}