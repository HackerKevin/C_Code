#define _CRT_SECURE_NO_WARNINGS	1
//ºÚÉ«ÐÇÆÚÎå
#include <iostream>
#include <iomanip>
using namespace std;

int main(void) {
    int y = 1900, m = 1, d = 1;
    int yy, mm = 12, dd = 31;
    cin >> yy;
    yy = 1900 + yy - 1;

    int w[7] = { 0,0,0,0,0,0,0 };
    int M[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    for (int i = 0;; i = (i + 1) % 7) 
    {
        if (d == 13) 
            w[i]++;
        if (y == yy && m == mm && d == dd) break;
        d++;
        if (d > M[m] + (m == 2 && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))))
            m++, d = 1;
        if (m > 12) y++, m = 1;
    }
    for (int i = 0; i < 7; i++) cout << w[i] << " ";
    return 0;
}
