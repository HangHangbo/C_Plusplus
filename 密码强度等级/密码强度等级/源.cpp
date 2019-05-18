#include<iostream>
#include<string>
using namespace std;
void GetPwdSecuritLeve(string pPasswordStr)
{
	int count = 0;   //总评分
	int a = 0;  //小写字母个数
	int b = 0;    //大写字符个数
	int c = 0;    //数字个数
	int d = 0;    //符号个数
	int sz = pPasswordStr.size();
	for (int i = 0; i<sz; i++)
	{
		char x = pPasswordStr[i];
		if (x >= 'a'&&x <= 'z')
			a++;
		else if (x >= 'A'&&x <= 'Z')
			b++;
		else if (x >= '0'&&x <= '9')
			c++;
		else if ((x >= 0x21 && x <= 0x2F) || (x >= 0x3A && x <= 0x40) || (x >= 0x5B && x <= 0x60) || (x >= 0x7B && x <= 0x7E))
			d++;
	}
	//密码长度
	if (sz <= 4)
		count += 5;
	else if (sz <= 7)
		count += 10;
	else
		count += 25;
	//字母
	if (a>0 || b>0)
		count += 10;
	if (a>0 && b>0)
		count += 15;
	//符号
	if (c == 1)
		count += 10;
	if (c>1)
		count += 25;
	//奖励
	if ((a>0 || b>0) && c>0)
		count += 2;
	if ((a>0 || b>0) && c>0 && d>0)
		count += 3;
	if (a>0 && b>0 && c>0 && d>0)
		count += 5;
	if (count >= 90)
		cout << "VERY_WEAK" << endl;
	else if (count >= 80)
		cout << "WEAK" << endl;
	else if (count >= 70)
		cout << "AVERGE" << endl;
	else if (count >= 60)
		cout << "STRONG" << endl;
	else if (count >= 50)
		cout << "VERY_STRONG" << endl;
	else if (count >= 25)
		cout << "SECURE" << endl;
	else if (count >= 0)
		cout << "VERY_SECURE" << endl;
}
int main()
{
	string s;
	while (cin >> s)
	{
		GetPwdSecuritLeve(s);
	}
	system("pause");
	return 0;
}