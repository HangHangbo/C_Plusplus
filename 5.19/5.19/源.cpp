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
//		for (const auto e : words)	//������ĸ˳�����򣬲���¼ÿ�����ʳ��ֵĴ���
//		{
//			++countmap[e];
//		}
//		multimap<int, string,greater<int>> n;	//���ִ���Ϊkey������Ϊvalue
//		//���ճ��ִ������򣬵��÷º���greaterʹ����˳���ɴ�С
//		for (const auto e : countmap)
//		{
//			n.insert(make_pair(e.second, e.first));
//		}
//		vector<string> s;
//		//��n�е�ǰk������д��vector��
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

//����������
//����ڵ�
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