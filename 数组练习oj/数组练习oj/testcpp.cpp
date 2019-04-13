#include<iostream>
#include<vector>
using namespace std;


//给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int cur = 0;
		int next = 0;

		while (next < nums.size()){
			if (nums[next] != 0){
				nums[cur] = nums[next];
				cur++;
			}
			next++;
		}

		for (int i = cur; i < nums.size(); ++i){
			nums[i] = 0;
		}
	}
};
//给定两个数组，编写一个函数来计算它们的交集。

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		int a = 0, b = 0;
		vector<int> s;
		while (a<nums1.size() && b<nums2.size())
		{
			if (nums1[a] == nums2[b])
			{
				s.push_back(nums1[a]);
				a++;
				b++;
			}
			else if (nums1[a]>nums2[b])
			{
				++b;
			}
			else
				++a;
		}
		return s;
	}
};
//给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int num = 0;
		auto it = nums.begin();
		while (it != nums.end())
		{
			num = num^*it;
			++it;
		}
		return num;
	}
};

//给定一个整数数组，判断是否存在重复元素。

//如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		if (nums.size()<2)
			return false;
		sort(nums.begin(), nums.end());
		for (int i = 1; i<nums.size(); ++i)
		{
			if (nums[i] == nums[i - 1])
				return true;
		}
		return false;
	}
};

//给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		k = k%nums.size();
		std::reverse(nums.begin(), nums.end());
		std::reverse(nums.begin(), nums.begin() + k);
		std::reverse(nums.begin() + k, nums.end());
	}
};
//买卖股票的最佳时机 II

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int maxpro = 0;
		int pro = 0;
		for (int i = 1; i<prices.size(); i++)
		{
			pro = prices[i] - prices[i - 1];
			if (pro>0)
				maxpro += pro;
		}
		return maxpro;
	}
};

//  从排序数组中删除重复项

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {

		auto it = nums.begin();
		while (it != nums.end())
		{
			auto vit = it + 1;
			while (vit != nums.end())
			{
				if (*it == *vit)
				{
					vit = nums.erase(vit);
					continue;
				}
				++vit;
			}
			++it;
		}
		return nums.size();
	}
};