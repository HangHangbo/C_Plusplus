#include <iostream>
#include <vector>

using namespace std;

int GetPrime(int M, vector<int> &arr)
{
	for (int i = 2; i < M; i++)
	{
		if (M%i == 0)
			arr.push_back(i);
	}
}
int main()
{
	int N, M;
	while (cin >> N >> M)
	{
		vector<int> arr;
		
	}
	return 0;
}