#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main()
{
	unordered_map<int, int> map;
	map.insert(make_pair(0, 0));
	map.insert(make_pair(2, 0));
	map.insert(make_pair(3, 0));
	map.insert(make_pair(1, 0));
	map.insert(make_pair(4, 0));
	map[10] = 10;
	auto mit = map.insert(make_pair(100, 0));
	mit.first->second = 100;
	auto it = map.begin();
	//while (it != map.end())
	//{
	//	cout << it->first << "-->" << it->second <<endl;
	//	++it;
	//}

	unordered_set<int> set;
	set.insert(1);
	set.insert(1);
	set.insert(1);
	set.insert(1);
	set.insert(1);
	set.insert(1);
	for (auto e : set)
	{
		cout << e << " ";
	}
	system("pause");
	return 0;
}