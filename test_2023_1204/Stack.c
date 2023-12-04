#define _CRT_SECURE_NO_WARNINGS	1
#include "Stack.h"

void STInit(ST* pst)//��ʼ��
{
	assert(pst);
	pst->a = NULL;
	pst->top = 0;
	//�����д���top����ջ��Ԫ�ص���һ��
	//Ҫ��top�պ�ָ��ջ��Ԫ�أ�Ҫ��ʼ��Ϊ-1
	//0��-1�Ĳ�ͬ�����ò��롢�пյȲ�����������������ͬ
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
	if (pst->top == pst->capacity)//�ж��Ƿ���Ҫ����
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
	assert(!STEmpty(pst));//���Ϊ�վͲ��ܷ���
	return pst->a[pst->top - 1];
}
bool STEmpty(ST* pst)
{
	assert(pst);
	return pst->top == 0;//Ϊ0˵��Ϊ��
}
int STSize(ST* pst)
{
	assert(pst);
	return pst->top;
}