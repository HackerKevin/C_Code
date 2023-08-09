#define _CRT_SECURE_NO_WARNINGS	1
//理解指针的解引用
#include <stdio.h>
int main()
{
    int n = 0x11223344;
    char* pc = (char*)&n;
    *pc = 0;
    return 0;
}