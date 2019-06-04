#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string str;
	while (getline(cin,str))
	{
		vector<string> s;
		int begin = 0;
		int last = 0;
		while (-1 != last){
			last = str.find(' ', begin);
			string word = str.substr(begin, last - begin);
			s.push_back(word);
			begin = last + 1;
		}
		cout << s.size() << endl;
		for (const auto e : s)
		{
			cout << e << endl;
		}
	}
	system("pause");
	return 0;
}