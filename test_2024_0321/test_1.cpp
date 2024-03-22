#define _CRT_SECURE_NO_WARNINGS	1
#include "AVLTree.h"
#include "RBTree.h"
#include "Map.h"
#include "Set.h"

void test_unordered_set()
{
	unordered_set<int> s;
	s.insert(1);
	s.insert(3);
	s.insert(2);
	s.insert(7);
	s.insert(2);
	
	unordered_set<int>::iterator it = s.begin();

	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}
int main()
{
	////Test_AVLTree2();
	////Test_RBTree1();
	//Kevin::Test_Map();
	//Kevin::Test_Map2();
	//Kevin::Test_Set();
	test_unordered_set();
	return 0;
}