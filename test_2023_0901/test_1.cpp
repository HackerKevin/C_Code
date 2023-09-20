#define _CRT_SECURE_NO_WARNINGS	1
#include <iostream>
using namespace std;
template <typename T> T Max(T a, T b)
{
    return (a > b) ? a : b;
}
int main()
{
    int a = 3, b = 5;
    char c = '3', d = '5';
    double x = 3.5, y = 5.5;
    char s[10] = "ABCD", t[10] = "abcd";

    cout << Max(a, b) << endl;
    cout << Max(c, d) << endl;
    cout << Max(x, y) << endl;
    cout << Max(s, t) << endl;
    return 0;
}
