#include<iostream>
#include<vector>
using namespace std;


//����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��

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
//�����������飬��дһ���������������ǵĽ�����

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
//����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�

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

//����һ���������飬�ж��Ƿ�����ظ�Ԫ�ء�

//����κ�ֵ�������г����������Σ��������� true�����������ÿ��Ԫ�ض�����ͬ���򷵻� false��
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

//����һ�����飬�������е�Ԫ�������ƶ� k ��λ�ã����� k �ǷǸ�����
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		k = k%nums.size();
		std::reverse(nums.begin(), nums.end());
		std::reverse(nums.begin(), nums.begin() + k);
		std::reverse(nums.begin() + k, nums.end());
	}
};
//������Ʊ�����ʱ�� II

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

//  ������������ɾ���ظ���

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