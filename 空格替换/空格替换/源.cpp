#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
	void replaceSpace(char *str, int length) {
	
		string s(str);
		int i = 0;
		while ((i = s.find(' ', i)) > -1)  //��0��ʼ�ң��ҵ����¼��pos��ѭ��������posλ�ÿ�ʼ�ң�һֱ�ҵ��꣬
		{
			s.erase(i, 1);
			s.insert(i, "%20");
			//s.replace(i,1,"%20");
		}
		auto it = s.c_str();  //��ȡָ��s��ָ��
		strcpy(str, it);
		
	
	}
};
int main()
{
	Solution s;
	char *str = "We Are Happy";
	int length = strlen(str);
	s.replaceSpace(str, length);
	cout << str << endl;
	system("pause");
	return 0;
}