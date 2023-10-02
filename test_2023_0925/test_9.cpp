#define _CRT_SECURE_NO_WARNINGS	1
//auto¿ÌΩ‚
#include <iostream>
using namespace std;
void TestFor1()
{
    int array[] = { 1, 2, 3, 4, 5 };
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
        array[i] *= 2;
    for (int* p = array; p < array + sizeof(array) / sizeof(array[0]); ++p)
        cout << *p << " ";
}
void TestFor2()
{
    int array[] = { 1, 2, 3, 4, 5 };
    for (auto& e : array)
        e *= 2;
    for (auto e : array)
        cout << e << " ";
}
void TestFor3(int array[])
{
    for (auto& e : array)
        cout << e << endl;
}
int main()
{
    TestFor3();
    return 0;
}




