//
////数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
////例如输入一个长度为9的数组{ 1, 2, 3, 2, 2, 2, 5, 4, 2 }。
////由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//
//class Solution {
//public:
//	int MoreThanHalfNum_Solution(vector<int> numbers) {
//		if (numbers.size() == 0)
//			return 0;
//		if (numbers.size() == 1)
//			return numbers[0];
//		int sz = numbers.size();
//		for (int i = 0; i < sz / 2 + 1; i++)
//		{
//			int count = 1;
//			for (int j = 0; j < sz; j++){
//
//				if (i == j)
//				{
//					continue;
//				}
//				if (numbers[i] == numbers[j])
//				{
//					count++;
//				}
//
//				if (count>sz / 2)
//					return numbers[i];
//			}
//		}
//		return 0;
//	}
//};
////1,2,3,2,2,2,5,4,2
////1,2,3,2,4,2,5,2,3
//int main()
//{
//	vector<int>v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(2);
//	v.push_back(2);
//	v.push_back(2);
//	v.push_back(5);
//	v.push_back(4);
//	v.push_back(2);
//	Solution s;
//	int ret = s.MoreThanHalfNum_Solution(v);
//	cout << ret << endl;
//	system("pause");
//	return 0;
//}