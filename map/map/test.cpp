#include <iostream>
#include <set>
#include <functional>
#include <map>
#include <string>
using namespace std;

//kv键值对
template <class T1,class T2>
struct Pair
{
	Pair(T1 k = T1(), T2 v = T2())
	:first(k)
	, second(v)
	{ }
	T1 first; //key
	T2 second; //value

};

void testMAP()
{
	/*map<int, int> map;
	//map 的key是可以重复的
	map.insert(make_pair(1,0));	*/	//map里每次插入一个键值对
	map<string, string> dictMap;
	dictMap.insert(make_pair("中国", "China"));
	dictMap.insert(make_pair("科技", "Tech"));
	//operator[]
	//(*((this->insert(make_pair(k,mapped_type()))).first)).second
	dictMap["西安"] = "Xian";			//不存在就创建
	dictMap["中国"] = "zhongguo";	//已存在，就进行修改
	auto dit = dictMap.begin();
	//at 通过key，返回value，没有这个key就抛异常
	cout << dictMap.at("西安") << endl;
	while (dit != dictMap.end())
	{
		cout << dit->first << " " << dit->second << endl;
		++dit;
	}
}
void testMap1()
{
	//底层按照从小到大的顺序对key进行排序，可以加入仿函数greater《int》让testMap底层按照从大到小排序
	map<int, string,greater<int>> testMap;
	testMap[2] = "红";
	testMap[4] = "橙";
	testMap[1] = "黄";
	testMap[6] = "绿";
	testMap[3] = "青";
	testMap[7] = "蓝";
	auto dit = testMap.begin();
	while (dit != testMap.end())
	{
		cout << dit->first << "->" << dit->second << endl;
		++dit;
	}
	//find 查找接口
	//如果找到了返回对应key的迭代器
	//如果没找到返回end
	int key;
	cin >> key;
	if (testMap.find(key) != testMap.end())
	{
		cout << testMap[key] << endl;
	}
}

void test_multimap()
{
	//multimap key 可以重复，则不支持operator[]
	multimap<int, string,greater<int>> testMap;
	testMap.insert(make_pair(1, "中国"));
	testMap.insert(make_pair(2, "中国1"));
	testMap.insert(make_pair(3, "中国2"));
	testMap.insert(make_pair(4, "中国3"));
	testMap.insert(make_pair(5, "中国4"));
	testMap.insert(make_pair(6, "中国5"));
	testMap.insert(make_pair(7, "中国6"));
	//count 函数可以统计相同key 键的总数
	//cout << testMap.count(1) << endl;
	for (auto e : testMap)
	{
		cout << e.first << "->" << e.second << endl;
	}
	//lower_bound(key) 返回 <=key 第一个位置迭代器
	auto mit = testMap.lower_bound(2);
	cout << mit->first << "--->" << mit->second << endl;
	//upper_bound(key) 返回 >key 第一个位置迭代器
	mit = testMap.upper_bound(2);
	cout << mit->first << "--->" << mit->second << endl;
}
void testSet()
{
	//set 可以插入重复的值 但是只保留一份
	set<int> testSet;
	testSet.insert(1);
	testSet.insert(2);
	testSet.insert(3);
	testSet.insert(6);
	testSet.insert(2);
	testSet.insert(1);
	testSet.insert(2);
	for (const auto& e : testSet)
	{
		cout << e << endl;
	}
}
void testmultiSet()
{
	//multiset 可以插入重复的值 并且全部保留
	multiset<int> testSet;
	testSet.insert(1);
	testSet.insert(2);
	testSet.insert(3);
	testSet.insert(6);
	testSet.insert(2);
	testSet.insert(1);
	testSet.insert(2);
	for (const auto& e : testSet)
	{
		cout << e << endl;
	}
}
int main()
{
	testmultiSet();
	system("pause");
	return 0;
}