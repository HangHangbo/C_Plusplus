#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	string v;
	getline(cin, s);
	getline(cin, v);
		for (int i = 0; i < v.size(); i++)
		{
			for (int j = 0; j < s.size(); j++)
			{
				if (s[j] == v[i])
				{
					s.erase(j, 1);
				}
			}
		}
		for (auto e : s)
		{
			cout << e;
		}
	
	cout << endl;
	system("pause");
	return 0;
}