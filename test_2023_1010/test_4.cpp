#define _CRT_SECURE_NO_WARNINGS	1
//new和malloc的区别（2）
#include <iostream>
using namespace std;
class Stack
{
public:
	Stack()
	{
		cout << "Stack()" << endl;
		_a = new int[4];
		_top = 0;
		_capacity = 4;
	}
	~Stack()
	{
		cout << "~Stack():" << this << endl;
		delete[] _a;
		_top = _capacity = 0;
	}
private:
	int* _a;
	int _top;
	int _capacity;
};
int main()
{
	/*cout << "----------" << endl;
	A* p1 = (A*)malloc(sizeof(A));
	cout << "----------" << endl;
	A* p2 = new A(1);
	cout << "----------" << endl;
	free(p1);
	cout << "----------" << endl;
	delete p2;
	cout << "----------" << endl;
	A* p3 = (A*)malloc(sizeof(A) * 10);
	cout << "----------" << endl;
	A* p4 = new A[10];
	cout << "----------" << endl;
	free(p3);
	cout << "----------" << endl;
	delete[] p4;*/

	/*A* p8 = new A;
	free(p8);*/

	Stack* pst = new Stack;
	free(pst);
	return 0;
}