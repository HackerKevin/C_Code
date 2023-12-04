#define _CRT_SECURE_NO_WARNINGS	1
#include "Stack.h"

void STInit(ST* pst)//初始化
{
	assert(pst);
	pst->a = NULL;
	pst->top = 0;
	//上面的写法里，top就在栈顶元素的上一个
	//要让top刚好指向栈顶元素，要初始化为-1
	//0和-1的不同，会让插入、判空等操作的条件都有所不同
	//pst->top = -1;
	pst->capacity = 0;
	

}
void STDestroy(ST* pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->top = 0;
	pst->capacity = 0;
}
void STPush(ST* pst, STDataType x)
{
	if (pst->top == pst->capacity)//判断是否需要扩容
	{
		
		int newCapacity = (pst->capacity) == 0 ? 4 : (pst->capacity * 2);
		STDataType* tmp = (STDataType*)realloc(pst->a, newCapacity * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		pst->a = tmp;
		pst->capacity = newCapacity;
	}
	pst->a[pst->top] = x;
	pst->top++;
}
void STPop(ST* pst)
{
	assert(pst);
	assert(!STEmpty(pst));
	pst->top--;
}
STDataType STTop(ST* pst)
{
	assert(pst);
	assert(!STEmpty(pst));//如果为空就不能访问
	return pst->a[pst->top - 1];
}
bool STEmpty(ST* pst)
{
	assert(pst);
	return pst->top == 0;//为0说明为空
}
int STSize(ST* pst)
{
	assert(pst);
	return pst->top;
}