#include <iostream>
#include "bitSet.h"

int main(){
	bitSet s(100000);
	s.Set(1111);
	s.Set(111);
	s.Set(11);
	s.Set(1);
	s.Set(2);
	s.Set(3);
	cout << s.Test(2) << endl;
	s.ReSet(2);
	cout << s.Test(2) << endl;
	cout << s.Test(3) << endl;
	system("pause");
	return 0;
}