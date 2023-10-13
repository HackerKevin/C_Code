#define _CRT_SECURE_NO_WARNINGS	1
#include<iostream>
#include<iomanip>
using namespace
std;
const double EPS = 1E-6;
int main() {
	int i, n;
	double e, item;
	e = 1;
	n = 1;
	item = 1;
	do {
		for (i = n; i <= n; i++)
			item *= i;
		e += 1 / item;
		n++;
	} while ((1 / item) >= EPS);
	cout << "e = " << fixed << setprecision(6) << e << endl;
	return 0;
}