#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <functional>

using namespace std;
//class Solution {
//public:
//	vector<string> topKFrequent(vector<string>& words, int k) {
//		map<string, int> countmap;
//		for (const auto e : words)	//按照字母顺序排序，并记录每个单词出现的次数
//		{
//			++countmap[e];
//		}
//		multimap<int, string,greater<int>> n;	//出现次数为key，单词为value
//		//按照出现次数排序，调用仿函数greater使排序顺序由大到小
//		for (const auto e : countmap)
//		{
//			n.insert(make_pair(e.second, e.first));
//		}
//		vector<string> s;
//		//将n中的前k个单词写入vector中
//		for (auto e : n)
//		{
//			if (k-->0)
//			{
//				s.push_back(e.second);
//			}
//			else
//			{
//				break;
//			}
//		}
//		return s;
//	}
//};
//
//int main()
//{
//	Solution s;
//	vector<string> words;
//	vector<string> c;
//	words.push_back("i");
//	words.push_back("i");
//	words.push_back("i");
//	words.push_back("ret");
//	words.push_back("ert");
//	words.push_back("ert");
//	words.push_back("sdfs");
//	words.push_back("fsdfs");
//	words.push_back("fsdfsdfs");
//	c=s.topKFrequent(words, 1);
//	for (const auto e : c)
//	{
//		cout << e << endl;
//	}
//	system("pause");
//	return 0;
//}

//二叉搜索树
//定义节点
template<class T>
struct BSTNode
{
	BSTNode(const T& data = T())
	: _pLeft(nullptr)
	, _pRight(nullptr)
	, _data(data)
	{}
	BSTNode<T>* _pLeft;
	BSTNode<T>* _pRight;
	T _data;
};