#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
	//暴力遍历查找
		for (auto p = begin(array); p != end(array); p++)
		{
			for (auto q = begin(*p); q != end(*p); q++)
			{
				if (*q == target)
				{
					return true;
				}

			}
		}
		return false;
	}
};
//int row = 0;     //行
//int column = 0;  //列
//auto it = *array.begin();
//auto vit = array.begin();
//while (it != *array.end()){ column++; }
//while (vit != array.end()){ row++; }
//for (auto p = array; p != array + row; p++)
//{
//	for (auto)
//}

int main()
{
	Solution s;
	vector<vector<int>> a{{0,1,2,3,4,5},{1,2,3,4,5,6},{2,3,4,5,6,7},{3,4,5,6,7,8},{4,5,6,7,8,9},{5,6,7,8,9,10},{6,7,8,9,10,11}};

	cout<<s.Find(5, a)<<endl;
	system("pause");
	return 0;
}