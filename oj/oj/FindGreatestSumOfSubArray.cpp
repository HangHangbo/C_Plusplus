//HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。
//今天测试组开完会后, 他又发话了:在古老的一维模式识别中, 常常需要计算连续子向量的最大和, 当向量全为正数的时候, 问题很好解决。
//但是, 如果向量中包含负数, 是否应该包含某个负数, 并期望旁边的正数会弥补它呢？
//例如 : {6, -3, -2, 7, -15, 1, 2, 2}, 连续子向量的最大和为8(从第0个开始, 到第3个为止)。
//给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)
#include<iostream>
#include<vector>
using namespace std;

//class Solution {
//public:
//	int max(int a, int b)
//	{
//		if (a >= b)
//			return a;
//		else
//			return b;
//	}
//	int FindGreatestSumOfSubArray(vector<int> array) {
//		if (array.empty() == 1)
//			return 0;
//		if (array.size() == 1)
//			return array[0];
//		int sz = array.size();
//		int max_count = array[0];
//		for (int i = 0;i<sz;i++){
//			int count = array[i];
//			max_count = max(count, max_count);
//			for (int j = i+1; j < sz; j++){
//				count += array[j];
//				max_count = max(count, max_count);
//			}
//		}
//		return max_count;
//	}
//	};
//遍历，遇到负和抛弃之前的结果，重新积累，期间保留最大值
class Solution{
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		if (array.empty())
			return 0;

		int cSum = 0;
		int result = array[0]; // result存储最大和，不能初始为0，存在负数
		for (size_t i = 0; i<array.size(); ++i)
		{
			if (cSum < 0) // 当前和<0，抛弃不要
				cSum = array[i];
			else
				cSum += array[i];

			if (cSum > result) // 存储最大结果
				result = cSum;
		}
		return result;
	}
};
//-2,-8,-1,-5,-9
//2,8,1,5,9
int main()
{
	Solution s;
	vector<int> v;
	v.push_back(-2);
	v.push_back(-8);
	v.push_back(-1);
	v.push_back(-5);
	v.push_back(-9);
	/*v.push_back(2);
	v.push_back(8);
	v.push_back(1);
	v.push_back(5);
	v.push_back(9);*/
	int ret = s.FindGreatestSumOfSubArray(v);
	cout << ret << endl;
	system("pause");
	return 0;
}