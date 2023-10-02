#define _CRT_SECURE_NO_WARNINGS	1
//cin&cout
#include <iostream>
using namespace std;
int main()
{
    int a;
    double b;
    char c;

    // 可以自动识别变量的类型
    cin >> a;
    cin >> b >> c;

    cout << a << endl;
    cout << b << " " << c << endl;
    return 0;
}

