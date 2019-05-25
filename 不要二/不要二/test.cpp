#include <iostream>
#include <vector>
using namespace std;
int grid[1000][1000] = {0};
int main()
{
	int W, H;
	cin >> W >> H;
	int count = 0;
	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < H; j++)
		{
			if (grid[i][j] == 0)
			{
				count++;
				if (i + 2 < W)
					grid[i + 2][j] = -1;
				if (j + 2 < H)
					grid[i][j + 2] = -1;
			}
		}
	}
	cout << count << endl;
	system("pasuse");
	return 0;
}