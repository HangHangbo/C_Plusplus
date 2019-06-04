#include <iostream>

using namespace std;

int main()
{
	int byte = 0;
	while (cin >> byte)
	{
		int max_count = 0;
		int count = 0;
		while (byte)
		{
			int num = byte & 1;
			if (num == 0)
			{
				if (count >= max_count)
					max_count = count;
				count = 0;
			}
			else
			{
				count++;
			}
			byte = byte >> 1;
		}
		if (count >= max_count)
			max_count = count;
		cout << max_count << endl;
		
	}
	system("pause");
	return 0;
}