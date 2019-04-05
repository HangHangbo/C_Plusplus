#include<iostream>
using namespace std;
#include<vector>


class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int sz = nums.size();
		int j;
		while (k--)
		{
			for (int i = 0; i<sz; i++)
			{
				swap(nums[sz - 1 - i], nums[sz - 2 - i]);
			}
		}
	}
};

int main()
{
	return 0;
}