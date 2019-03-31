//#include<iostream>
//using namespace std;
//#include<vector>
//
//
////int main()
////{
////	vector<int> v1;
////	v1.push_back(1);
////	v1.push_back(2);
////
////	//auto it = v1.begin();
////	//
////	//v1.insert(it,10);
////	//*it = 10;  //增容后野指针
////	//调用完insert，获取insert接口的返回值，防止迭代器失效
////	auto it = v1.begin();
////
////	it=v1.insert(it, 10);
////	*it = 10;  //增容后野指针
////	v1.push_back(3);
////	v1.push_back(4);
////	//auto it = v1.begin();
////	//while (it != v1.end())
////	//{
////	//	if (*it % 2 == 0)
////	//		v1.erase(it);   //访问越界
////	//	it++;
////	//}
////	//调用完erase，获取erase接口的返回值，防止迭代器失效
////	/*while (it != v1.end())
////	{
////		if (*it % 2 == 0)
////			it=v1.erase(it);
////		else
////		it++;
////	}*/
////
////	return 0;
////}
////
////
//
//int main()
//{
//	vector<int> v1(50, 1);
//	cout << v1.capacity() << endl;
//	//手动释放vector空间
//
//	{  //加括号 v2为局部变量
//		vector<int>v2;
//		v2.swap(v1); 
//	}//出括号调析构函数释放空间
//	cout << v1.capacity() << endl;
//	system("pause");
//	return 0;
//}