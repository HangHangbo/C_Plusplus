#include <iostream>

using namespace std;

class LCA {
public:
	int getLCA(int a, int b) {
		// write code here
		if (a ==b)
			return a;
		int num = 0;
		int c = b;
		while (a)
		{
			b = c;
			while (b)
			{
				b = b / 2;
				if (a == b)
				{
					num = a;
					break;
				}
			}
			if (a == b)
				break;
			a = a / 2;
		}
			return num;
	}
};
int main()
{
	LCA s;
	int num=s.getLCA(8, 9);
	return 0;
}