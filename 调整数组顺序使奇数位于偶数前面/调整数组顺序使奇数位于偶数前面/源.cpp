#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		vector<int> odd;
		vector<int> even;
		for (auto e : array)
		{
			if (e % 2 == 1)
				odd.push_back(e);
			else
				even.push_back(e);
		}
		for (auto w : even)
		{
			odd.push_back(w);
		}
		swap(array, odd);
	}
};

int main()
{
	Solution s;
	vector<int> d;
	d.push_back(1);
	d.push_back(2);
	d.push_back(1);
	d.push_back(8);
	s.reOrderArray(d);
	return 0;
}