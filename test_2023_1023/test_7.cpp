#define _CRT_SECURE_NO_WARNINGS	1
#include <iostream>
#include<string>
#define m 80
using namespace std;

int main() {
    int count = 0;
    string str;
    cin >> str;
    for (int j = 0; j < str.size(); j++) {
        switch (int(str[j])) {
        case 65:
        case 69:
        case 73:
        case 79:
        case 85:
        case 97:
        case 101:
        case 105:
        case 111:
        case 117:
            count++;
            break;
        }
    }
    cout << "Count=" << count << endl;

    return 0;
}


