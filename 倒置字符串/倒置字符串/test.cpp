//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//int main()
//{
//    string s;
//    while(getline(cin,s)){
//        reverse(s.begin(),s.end());	//ȫ������
//        int i=0;	//��Ҫ���õ���ĸ���һ���±�λ��
//        int j=i;	//��Ҫ���õ���ĸ�ĵ�һ���±�λ��
//        while(i<s.size())
//        {
//            while(i<s.size()&&s[i]==' ')	//�����ո�������һ��
//            {
//                i++;
//            }
//            j=i;	����j
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