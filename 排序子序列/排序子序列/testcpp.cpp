#include <iostream>
#include <vector>
using namespace std;

//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		vector<int> s(n);
//		for (int i = 0; i < n; i++)
//		{
//			cin >> s[i];
//		}
//		int count = 1;
//		if (n == 1)
//		{
//			cout << count << endl;
//		}
//		int ret = 0;	 //ÏàµÈ
//		if (s[0] > s[1])
//			ret = -1;	//½µÐò
//		else if (s[0] < s[1])
//			ret = 1;	//ÉýÐò
//
//		for (int i = 1; i < n; i++)
//		{
//			if (ret == 1)
//			{
//				if (s[i - 1] > s[i])
//				{
//					count++;
//					ret = -1;
//				}
//				else if (s[i - 1] == s[i])
//				{
//					ret = 0;
//				}
//			}
//			else if (ret == -1)
//			{
//				if (s[i - 1] < s[i])
//				{
//					count++;
//					ret = 1;
//				}
//			}
//			else if (ret == 0)
//			{
//				if (s[i - 1] < s[i])
//					ret = 1;
//				else if (s[i - 1]>s[i])
//					ret = -1;
//				else if (s[i - 1] == s[i])
//					ret = 0;
//			}
//		}
//		cout << count;
//	}
//	system("pause");
//	return 0;
//}


int main()
{
	int n;
	cin >> n;

		vector<int> s(n);
		for (int i = 0; i < n; i++)
		{
			cin >> s[i];
		}
		int count = 0;
		int ret = 0;
		while (ret < n-1)
		{
			if (s[ret] < s[ret + 1])
			{
				while (s[ret] <= s[ret + 1])
				{
					ret++;
				}
				ret++;
				count++;
			}
			else if (s[ret] == s[ret + 1])
				ret++;
			else
			{
				while (s[ret] >= s[ret + 1])
				{
					ret++;
				}
				ret++;
				count++;
			}
		}
		cout << count<<endl;
	system("pause");
	return 0;
}