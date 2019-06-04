#include <iostream>
#include <vector>
using namespace std;

bool isLuck(vector<int> arr)
{
	int a,b;
	for (auto e : arr)
	{
		a += e;
		b *= e;
	}
	if (a > b)
		return true;
	else
		return false;
}

int main()
{
	int n;
	int m;
	cin >> n;
	vector<int> arr;
	while (n--)
	{
		if (n > 1){
			cin >> m;
			arr.push_back(m);
		}
		
	}
	int count = 0;

	system("pause");
	return 0;
}