#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//int main()
//{
//	int a[1000] = { 0 };//������0��Ȼ������n�����Ӧλ�ü�1������������
//	int n, num = 0;  //�ҵ����ڵ���һ��������Ǹ�
//	while (cin >> n){
//		a[n]++;
//		num++;
//	}
//	for (int i = 0; i<num; i++){
//		if (a[i] >= num / 2)
//			cout << i << endl;
//	}
//	system("pause");
//	return 0;
//}

int main()
{
	vector<int> s;
	int n;
	while (cin >> n)
	{
		s.push_back(n);
	}
	sort(s.begin(), s.end());
	int sz = s.size() / 2;
	cout << s[sz] << endl;
	return 0;
}