#include<iostream>
using namespace std;
#include<vector>


class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int sz = nums.size();
		for (int i = 0; i<sz - k; i++)
		{
			nums.push_back(nums[i]);
		}
		nums = 
	}
};