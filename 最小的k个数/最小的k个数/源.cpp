#include<iostream>
#include<vector>
#include <algorithm>    // std::sort

using namespace std;
class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		int size = input.size();
		vector<int> s;
		if (k <= 0||k>size)
			return s;
		sort(input.begin(), input.end());
		int i = 0;
		while (k--)
		{
			s.push_back(input[i++]);
		}
		return s;
	}
};

int main()
{
	Solution s;
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	vector<int> e;
	e=s.GetLeastNumbers_Solution(v,4);
	return 0;
}