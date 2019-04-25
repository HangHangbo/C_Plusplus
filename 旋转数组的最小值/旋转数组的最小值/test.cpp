#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() == 0)
			return 0;
		//暴力查找最小值 时间复杂度为O（n）
		/*int min = rotateArray[0];
		for (auto e : rotateArray)
		{
			if (e < min)
				swap(e, min);
		}
		return min;*/

		//数组为非减序，切经过旋转，则数组为两段非减序数组，找到分界值
		//二分查找 时间复杂度为O(nlogn)
		int left = 0;
		int right = rotateArray.size() - 1;
		int mid=0;
		while (rotateArray[left] >=rotateArray[right])
		{
			if (right - left == 1)
			{
				mid = right;
				break;
			}
			mid = left + (right - left) / 2;
			if (rotateArray[left] == rotateArray[right] && rotateArray[mid] == rotateArray[left])
			{
				return min(rotateArray, left, right);
			}
			if (rotateArray[left] <= rotateArray[mid])
			{
				left = mid;
			}
			else{
				right = mid;
			}
		}
		return rotateArray[mid];
	}
	int min(vector<int> &rotateArray, int left, int right)
	{
		int min = 0;
		for (int i = left+1; i < right; i++)
		{
			if (rotateArray[i] < rotateArray[min])
			{
				min = i;
			}
		}
		return rotateArray[min];
	}
};
int main()
{
	Solution x;
	vector<int> s;
	s.push_back(3);
	s.push_back(4);
	s.push_back(5);
	s.push_back(1);
	s.push_back(2);
	int min=x.minNumberInRotateArray(s);
	cout << min << endl;
	system("pause");
	return 0;
}