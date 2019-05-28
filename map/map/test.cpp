#include <iostream>
#include <set>
#include <functional>
#include <map>
#include <string>
using namespace std;

//kv��ֵ��
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
	//map ��key�ǿ����ظ���
	map.insert(make_pair(1,0));	*/	//map��ÿ�β���һ����ֵ��
	map<string, string> dictMap;
	dictMap.insert(make_pair("�й�", "China"));
	dictMap.insert(make_pair("�Ƽ�", "Tech"));
	//operator[]
	//(*((this->insert(make_pair(k,mapped_type()))).first)).second
	dictMap["����"] = "Xian";			//�����ھʹ���
	dictMap["�й�"] = "zhongguo";	//�Ѵ��ڣ��ͽ����޸�
	auto dit = dictMap.begin();
	//at ͨ��key������value��û�����key�����쳣
	cout << dictMap.at("����") << endl;
	while (dit != dictMap.end())
	{
		cout << dit->first << " " << dit->second << endl;
		++dit;
	}
}
void testMap1()
{
	//�ײ㰴�մ�С�����˳���key�������򣬿��Լ���º���greater��int����testMap�ײ㰴�մӴ�С����
	map<int, string,greater<int>> testMap;
	testMap[2] = "��";
	testMap[4] = "��";
	testMap[1] = "��";
	testMap[6] = "��";
	testMap[3] = "��";
	testMap[7] = "��";
	auto dit = testMap.begin();
	while (dit != testMap.end())
	{
		cout << dit->first << "->" << dit->second << endl;
		++dit;
	}
	//find ���ҽӿ�
	//����ҵ��˷��ض�Ӧkey�ĵ�����
	//���û�ҵ�����end
	int key;
	cin >> key;
	if (testMap.find(key) != testMap.end())
	{
		cout << testMap[key] << endl;
	}
}

void test_multimap()
{
	//multimap key �����ظ�����֧��operator[]
	multimap<int, string,greater<int>> testMap;
	testMap.insert(make_pair(1, "�й�"));
	testMap.insert(make_pair(2, "�й�1"));
	testMap.insert(make_pair(3, "�й�2"));
	testMap.insert(make_pair(4, "�й�3"));
	testMap.insert(make_pair(5, "�й�4"));
	testMap.insert(make_pair(6, "�й�5"));
	testMap.insert(make_pair(7, "�й�6"));
	//count ��������ͳ����ͬkey ��������
	//cout << testMap.count(1) << endl;
	for (auto e : testMap)
	{
		cout << e.first << "->" << e.second << endl;
	}
	//lower_bound(key) ���� <=key ��һ��λ�õ�����
	auto mit = testMap.lower_bound(2);
	cout << mit->first << "--->" << mit->second << endl;
	//upper_bound(key) ���� >key ��һ��λ�õ�����
	mit = testMap.upper_bound(2);
	cout << mit->first << "--->" << mit->second << endl;
}
void testSet()
{
	//set ���Բ����ظ���ֵ ����ֻ����һ��
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
	//multiset ���Բ����ظ���ֵ ����ȫ������
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