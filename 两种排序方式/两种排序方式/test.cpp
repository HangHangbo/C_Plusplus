#include <iostream>
#include <vector>
#include <string>
using namespace std;
//比较长度是否合法
bool isLengths(vector<string> s)
{
	for (int i = 0; i < s.size() - 1; i++)
	{
		if (s[i].size()>s[i + 1].size())
			return false;
	}
	return true;
}
bool isNumber(vector<string> s)
{
	for (int i = 0; i < s.size() - 1; i++)
	{
		if (s[i]>s[i + 1])
			return false;
	}
	return true;
}

int main()
{

	int n;
	cin >> n;

	vector<string> s(n);
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		s[i] = str;
	}
	if (n == 1)
	{
		cout << "both" << endl;
	}
	if (isNumber(s) && isLengths(s))
	{
		cout << "both" << endl;
	}
	else if (isNumber(s) && !isLengths(s))
	{
		cout << "lexicographically" << endl;
	}
	else if (isLengths(s) && !isNumber(s))
	{
		cout << "lengths" << endl;
	}
	else
	{
		cout << "none" << endl;
	}
	system("pause");
	return 0;
}