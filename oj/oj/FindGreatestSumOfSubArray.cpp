//HZż������Щרҵ������������Щ�Ǽ����רҵ��ͬѧ��
//��������鿪����, ���ַ�����:�ڹ��ϵ�һάģʽʶ����, ������Ҫ��������������������, ������ȫΪ������ʱ��, ����ܺý����
//����, ��������а�������, �Ƿ�Ӧ�ð���ĳ������, �������Աߵ��������ֲ����أ�
//���� : {6, -3, -2, 7, -15, 1, 2, 2}, ����������������Ϊ8(�ӵ�0����ʼ, ����3��Ϊֹ)��
//��һ�����飬��������������������еĺͣ���᲻�ᱻ������ס��(�������ĳ���������1)
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
//������������������֮ǰ�Ľ�������»��ۣ��ڼ䱣�����ֵ
class Solution{
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		if (array.empty())
			return 0;

		int cSum = 0;
		int result = array[0]; // result�洢���ͣ����ܳ�ʼΪ0�����ڸ���
		for (size_t i = 0; i<array.size(); ++i)
		{
			if (cSum < 0) // ��ǰ��<0��������Ҫ
				cSum = array[i];
			else
				cSum += array[i];

			if (cSum > result) // �洢�����
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