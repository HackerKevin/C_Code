#define _CRT_SECURE_NO_WARNINGS	1
#include "Stack.h"
#include "Queue.h"
bool isValid(char* s) {
    ST st;
    STInit(&st);
    while (*s)
    {
        if (*s == '(' || *s == '[' || *s == '{')
        {
            STPush(&st, *s);//是左括号就入栈
        }
        else//与栈顶的元素进行比较
        {
            if (STEmpty(&st))
            {
                STDestroy(&st);
                return false;
            }
            char top = STTop(&st);
            STPop(&st);
            if ((*s == ']' && top != '[')
                || (*s == ')' && top != '(')
                || (*s == '}' && top != '{'))
            {
                STDestroy(&st);
                return false;//不匹配就返回false
            }
        }
        ++s;
    }
    bool ret = STEmpty(&st);
    STDestroy(&st);
    return ret;
}

void TestQueue()
{

}

int main()
{
	ST st;
	STInit(&st);
	/*STPush(&st, '[');*/
	/*STPush(&st, 2);
	STPush(&st, 3);
	STPush(&st, 4);*/
    if (isValid("()[]{}"))
        printf("true\n");
    else
        printf("false\n");

	//while (!STEmpty(&st))
	//{
	//	printf("%d ", STTop(&st));
	//	STPop(&st);
	//}
	//STDestroy(&st);
	return 0;
}