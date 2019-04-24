#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
	void replaceSpace(char *str, int length) {
	
		string s(str);
		int i = 0;
		while ((i = s.find(' ', i)) > -1)  //从0开始找，找到后记录下pos，循环继续从pos位置开始找，一直找到完，
		{
			s.erase(i, 1);
			s.insert(i, "%20");
			//s.replace(i,1,"%20");
		}
		auto it = s.c_str();  //获取指向s的指针
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