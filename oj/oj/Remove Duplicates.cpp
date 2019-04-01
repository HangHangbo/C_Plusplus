//#include<iostream>
//#include<vector>
//using namespace std;
//
////给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
////双迭代器法 
//class Solution {
//public:
//	int removeDuplicates(vector<int>& nums) {
//		
//		auto it = nums.begin();
//		while (it != nums.end())
//		{
//			auto vit = it+1;
//			while (vit != nums.end())
//			{
//				if (*it == *vit)
//				{
//					vit = nums.erase(vit);
//					continue;               //跳出本次循环不执行++vit
//				}
//					++vit;
//			}
//			++it;
//		}
//		return nums.size();
//	}
//};
//
//
//
////class Solution {
////public:
////	int removeDuplicates(vector<int>& nums) {
////		if (nums.size() == 0) return 0;
////		int k = 0;
////		for (int i = 1; i<nums.size(); i++){
////			if (nums[i] != nums[k])
////				nums[++k] = nums[i];
////		}
////		return k + 1;
////	}
////};
//
//int main()
//{
//	vector<int> nums(3, 3);
//	nums.push_back(4);
//	
//	Solution s;
//	int ret = s.removeDuplicates(nums);
//	cout << ret << endl;
//	system("pause");
//	return 0;
//}