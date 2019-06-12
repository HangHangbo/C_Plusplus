#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int num;
	cin >> num;
	string order;
	cin >> order;
	int cur = 1;
	int top = 1, bottom=4;
	if (num <= 4)
	{
		bottom = num;
		for (auto e : order)
		{
			if (e == 'U')
			{
				if (cur == 1)
					cur = num;
				else
					cur--;
			}
			else if (e == 'D')
			{
				if (cur == num)
					cur = 1;
				else
					cur++;
			}
			cout << cur ;
		}
		cout << endl;
		
	}
	else
	{
		for (auto e : order)
		{
			if (e == 'U')
			{
				if (cur == 1)
				{
					cur = num;
					bottom = num;
					top = num - 3;
				}
				else if (cur == top)
				{
					cur--;
					top--;
					bottom--;
				}
				else
				{
					cur--;
				}
			}
			else
			{
				if (cur == num)
				{
					cur = 1;
					top = 1;
					bottom = 4;
				}
				else if (cur == bottom)
				{
					cur++;
					top++;
					bottom++;
				}
				else
				{
					cur++;
				}
			}

			cout << cur << " ";
		}
		cout << endl;
	}
	for (int i = top; i <= bottom; i++)
	{
		cout << i << " ";
	}
	cout << endl;
	cout << cur << endl;
	system("pause");

	return 0;
}