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
				j = nums[sz - 1 - i];
				nums[sz - 1 - i] = nums[sz - i - 2];
				nums[sz - 2 - i] = j;
			}
		}
	}
};

int main()
{
	return 0;
}