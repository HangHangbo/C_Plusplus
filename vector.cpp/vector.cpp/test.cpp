#include<iostream>
using namespace std;
#include<vector>


//int main()
//{
//	vector<int> v1;
//	v1.push_back(1);
//	v1.push_back(2);
//
//	//auto it = v1.begin();
//	//
//	//v1.insert(it,10);
//	//*it = 10;  //���ݺ�Ұָ��
//	//������insert����ȡinsert�ӿڵķ���ֵ����ֹ������ʧЧ
//	auto it = v1.begin();
//
//	it=v1.insert(it, 10);
//	*it = 10;  //���ݺ�Ұָ��
//	v1.push_back(3);
//	v1.push_back(4);
//	//auto it = v1.begin();
//	//while (it != v1.end())
//	//{
//	//	if (*it % 2 == 0)
//	//		v1.erase(it);   //����Խ��
//	//	it++;
//	//}
//	//������erase����ȡerase�ӿڵķ���ֵ����ֹ������ʧЧ
//	/*while (it != v1.end())
//	{
//		if (*it % 2 == 0)
//			it=v1.erase(it);
//		else
//		it++;
//	}*/
//
//	return 0;
//}
//
//

int main()
{
	vector<int> v1(50, 1);
	cout << v1.capacity() << endl;
	//�ֶ��ͷ�vector�ռ�

	{  //������ v2Ϊ�ֲ�����
		vector<int>v2;
		v2.swap(v1); 
	}//�����ŵ����������ͷſռ�
	cout << v1.capacity() << endl;
	system("pause");
	return 0;
}