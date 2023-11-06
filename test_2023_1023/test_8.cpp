#define _CRT_SECURE_NO_WARNINGS	1
#include <iostream>
#include<string>
using namespace std;

int main()
{
    int n = 0, x = 0, y = 0, z = 0; 
    cin >> n;
    string str;
    for (int k = 0; k <= n; k++)
    {
        getline(cin, str);
            for (int m = 0; m < str.size(); m++)
            {
                if (65 <= (int)str[m] && (int)str[m] <= 122)
                {
                    x++;//字母
                    continue;
                }

                if (48 <= (int)str[m] && (int)str[m] <= 57)
                {
                    y++;//数字
                    continue;
                }

                if ((int)str[m] == 32)
                {
                    continue;
                }

                else
                {
                    z++;//其他
                    continue;
                }

            }
        
    }
    

    cout << "英文字母：" << x << endl;
    cout << "数字：" << y << endl;
    cout << "其他字符: " << z << endl;
    return 0;
}