//扑克比大小
#include <iostream>
#include <string>
using namespace std;
string poker = "345678910JQKA2";
#define printa {cout<<a<<endl; system("pause");return 0;}
#define printb {cout<<b<<endl; system("pause");return 0;}

int count(const string &a)
{
	int num = 0;
	auto it = a.begin();
	while (it != a.end())
	{
		if (*it == ' ')
			num++;
		++it;
	}
	return num;
}

int main()
{
	string str;
	getline(cin, str);
	string a;
	string b;
	int len = str.find('-');
	a = str.substr(0, len);
	b = str.substr(len + 1);
	string Max = "joker JOKER";
	if (a == Max)
	{
		printa;
	}
	else if (b == Max)
	{
		printb;
	}
	//获取空格个数
	int count_a = count(a);
	int count_b = count(b);
	//相同牌型
	if (count_a == count_b)
	{
		string begin_a, begin_b;
		int pos_a = a.find(' ');
		begin_a = a.substr(0, pos_a);
		int pos_b = b.find(' ');
		begin_b = b.substr(0, pos_b);
		if (poker.find(begin_a) > poker.find(begin_b))
		{
			printa;
		}
		else
		{
			printb;
		}
	}
	//有一手牌是炸弹
	if (count_a == 3 && count_b != 3)
	{
		printa;
	}
	else if (count_b == 3 && count_a != 3)
	{
		printb;
	}
	cout << "ERROR" << endl;


	system("pause");
	return 0;
}