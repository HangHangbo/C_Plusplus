//
////��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
////��������һ������Ϊ9������{ 1, 2, 3, 2, 2, 2, 5, 4, 2 }��
////��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��
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