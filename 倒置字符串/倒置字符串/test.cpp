//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//int main()
//{
//    string s;
//    while(getline(cin,s)){
//        reverse(s.begin(),s.end());	//全部逆置
//        int i=0;	//需要逆置的字母最后一个下标位置
//        int j=i;	//需要逆置的字母的第一个下标位置
//        while(i<s.size())
//        {
//            while(i<s.size()&&s[i]==' ')	//遇到空格跳到下一格
//            {
//                i++;
//            }
//            j=i;	更新j
//            while(i<s.size()&&s[i]!=' ')
//            {
//                i++;
//            }
//            reverse(s.begin()+j,s.begin()+i);
//            j=i;
//        }
//        cout<<s<<endl;
//    }
//    return 0;
//}


#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s1;
	string s2;

	cin >> s1;

	while (cin >> s2&&getchar() != '\n')
	{
		s1 = s2 + " " + s1;
	}

	cout << s2 << " " << s1 << endl;
	system("pause");
	return 0;
}