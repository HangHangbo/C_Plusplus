#include <iostream>
using namespace std;

int Sum(int n, int m, int &count)
{
	
	if (n == 0||m==0)
	{
		return 1;
	}
		return Sum(n - 1, m,count) + Sum(n, m - 1,count);

}
int main()
{
	int n, m;
	while (cin >> n >> m){
		int count = 0;
		count = Sum(n, m, count);
		cout << count << endl;
	}
	return 0;
}