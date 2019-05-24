#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isPlalindrome(string const A)
{
	if (A.size() == 1)
	{
		return true;
	}
	stack<char> s;
	for (auto e : A)
	{
		s.push(e);
	}
	for (auto e : A)
	{
		if (s.top() == e)
		{
			s.pop();
		}
		else
		{
			return false;
		}
	}
	return true;
}
int main()
{
	string A, B;
	cin >> A >> B;

		int count = 0;
		for (int i = 0; i <= A.size(); i++)
		{
			A.insert(i, B);
			if (isPlalindrome(A))
			{
				count++;
			}
			A.erase(i,B.size());
		}
		cout << count << endl;
		system("pause");

	return 0;
}