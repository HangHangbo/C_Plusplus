//#include<iostream>
//#include<vector>
//using namespace std;
//
////����һ���������飬����Ҫ��ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ������Ƴ���������³��ȡ�
////˫�������� 
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
//					continue;               //��������ѭ����ִ��++vit
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