#include "Hash.h"
#include <iostream>


void testHash()
{
	HashTable<int, int> ht;
	ht.Insert(make_pair(0, 0));
	ht.Insert(make_pair(1, 1));
	ht.Insert(make_pair(2, 2));
	ht.Insert(make_pair(3, 3));
	ht.Insert(make_pair(4, 4));
	ht.Insert(make_pair(5, 5));
	ht.Insert(make_pair(6, 6));
}


int main()
{
	testHash();
	return 0;
}