#include<iostream>
#include<vector>
#include<stack>

using namespace std;

//class Solution {
//public:
//	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
//		if (pushV.size() == 0 || popV.size() == 0)
//			return true;
//		auto it = popV.rbegin();
//		for (auto e : pushV)
//		{
//			if (e != *it)
//			{
//				return false;
//			}
//			else if (e == *it)
//			{
//				it--;
//			}
//		}
//		return true;
//	}
//};

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		size_t psz = pushV.size();
		size_t popsz = popV.size();
		if (psz != popsz)
			return false;
		stack<int> s;
		size_t pushIndex = 0;
		size_t popIndex = 0;
		while (pushIndex<psz)
		{
			s.push(pushV[pushIndex++]);
			while (!s.empty() && s.top() == popV[popIndex])
			{
				s.pop();
				popIndex++;
			}
		}
		return s.empty();
	}

};

int main()
{
	vector<int> s1;
	vector<int> s2;
	s1.push_back(1);
	s1.push_back(2);
	s1.push_back(3);
	s1.push_back(4);
	s1.push_back(5);
	s2.push_back(4);
	s2.push_back(5);
	s2.push_back(3);
	s2.push_back(2);
	s2.push_back(1);
	Solution s;
	cout << s.IsPopOrder(s1,s2) << endl;
	system("pause");
	return 0;
}