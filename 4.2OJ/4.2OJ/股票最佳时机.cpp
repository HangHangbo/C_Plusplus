//#include<iostream>
//using namespace std;
//#include<vector>
//
//class Solution {
//public:
//	int maxProfit(vector<int>& prices) {
//		int maxpro = 0;
//		int pro = 0;
//		for (int i = 1; i<prices.size(); i++)
//		{
//			pro = prices[i] - prices[i - 1];
//			if (pro>0)
//				maxpro += pro;
//		}
//		return maxpro;
//	}
//};
////int main()
//{
//	Solution s;
//	vector<int>v(7);
//	v.push_back(1);
//	v.push_back(5);
//	v.push_back(3);
//	v.push_back(6);
//	v.push_back(4);
//	s.maxProfit(v);
//	return 0;
//}