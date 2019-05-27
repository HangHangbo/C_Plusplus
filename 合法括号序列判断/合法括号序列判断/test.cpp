#include <iostream>
#include <string>
#include <stack>

using namespace std;
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// write code here
		if (n % 2 != 0)
			return false;
		stack<char> s;
		for (auto e : A)
		{
			if (e == '(')
				s.push(e);
			else if (e == ')')
			{
				if (s.empty())
					return false;
				else
				{
					s.pop();
				}
			}
			else
				return false;
		}
		return s.empty();
	}
};
int main()
{
	Parenthesis a;
	string s;
	cin >> s;
	int n;
	cin >> n;
	int i=a.chkParenthesis(s, n);
	return 0;
}