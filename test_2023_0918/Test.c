#define _CRT_SECURE_NO_WARNINGS	1
#include "SList.h"
void TestSList1()
{
	SLTNode* plist = NULL;
	//此时还没有任何节点开辟，因此plist为空
	SLTPushFront(&plist, 1);
	SLTPushFront(&plist, 2);
	SLTPushFront(&plist, 3);
	SLTPushFront(&plist, 4);
	SLPushBack(plist, 5);
	SLTPrint(plist);
}
void TestSList2()
{
	SLTNode* plist = NULL;
	SLPushBack(&plist, 1);
	SLPushBack(&plist, 2);
	SLPushBack(&plist, 3);
	SLPushBack(&plist, 4);
	SLTPrint(plist);
}
void TestSList3()
{
	SLTNode* plist = NULL;
	SLPushBack(&plist, 1);
	SLPushBack(&plist, 2);
	SLPushBack(&plist, 3);
	SLPushBack(&plist, 4);
	SLTPrint(plist);
	SLPopBack(&plist);
	SLTPrint(plist);
}
void TestSList4()
{
	SLTNode* plist = NULL;
	SLPushBack(&plist, 1);
	SLPushBack(&plist, 2);
	SLPushBack(&plist, 3);
	SLPushBack(&plist, 4);
	SLTPrint(plist);
	SLPopBack(&plist);
	SLPopBack(&plist);
	SLPopBack(&plist);
	SLTPrint(plist);
	SLPopBack(&plist);
	SLTPrint(plist);
}
void TestSList5()
{
	SLTNode* plist = NULL;
	SLPushBack(&plist, 1);
	SLPushBack(&plist, 2);
	SLPushBack(&plist, 3);
	SLPushBack(&plist, 4);
	SLTPrint(plist);
	SLPopBack(&plist);
	SLPopBack(&plist);
	SLPopBack(&plist);
	SLTPrint(plist);
	SLPopBack(&plist);
	SLTPrint(plist);
	SLPopBack(&plist);
	SLTPrint(plist);
}
void TestSList6()
{
	SLTNode* plist = NULL;
	SLPushBack(&plist, 1);
	SLPushBack(&plist, 2);
	SLPushBack(&plist, 3);
	SLPushBack(&plist, 4);
	SLTPrint(plist);
	SLTPopFront(&plist);
	SLTPrint(plist); 
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPrint(plist);
	SLTPopFront(&plist);
	SLTPrint(plist);
}
void TestSList7()
{
	SLTNode* plist = NULL;
	SLPushBack(&plist, 1);
	SLPushBack(&plist, 2);
	SLPushBack(&plist, 3);
	SLPushBack(&plist, 4);
	SLTPrint(plist);
	SLTNode* pur = STFind(plist, 1);
	printf("%d\n", pur->data);
	 pur = STFind(plist, 2);
	printf("%d\n", pur->data);
	pur = STFind(plist, 3);
	printf("%d\n", pur->data);
	pur = STFind(plist, 4);
	printf("%d\n", pur->data);
	pur = STFind(plist, 5);
	printf("%d\n", pur->data);
}
void TestSList8()
{
	SLTNode* plist = NULL;
	SLPushBack(&plist, 1);
	SLPushBack(&plist, 2);
	SLPushBack(&plist, 3);
	SLPushBack(&plist, 4);
	SLTPrint(plist);
	SLTNode* pur = STFind(plist, 1);
	pur->data = 10;
	SLTPrint(plist);
}
void TestSList9()
{
	SLTNode* plist = NULL;
	SLPushBack(&plist, 1);
	SLPushBack(&plist, 2);
	SLPushBack(&plist, 3);
	SLPushBack(&plist, 4);
	SLTPrint(plist);
	SLTNode* pur = STFind(plist, 3);
	SLInsert(&plist, pur, 10);
	SLTPrint(plist);
	pur = STFind(plist, 1);
	SLInsert(&plist, pur, 10);
	SLTPrint(plist);
}
void TestSList10()
{
	SLTNode* plist = NULL;
	SLPushBack(&plist, 1);
	SLPushBack(&plist, 2);
	SLPushBack(&plist, 3);
	SLPushBack(&plist, 4);
	SLTPrint(plist);
	SLTNode* pur = STFind(plist, 3);
	SLInsertAfter(pur, 10);
	SLTPrint(plist);
	pur = STFind(plist, 4);
	SLInsertAfter(pur, 10);
	SLTPrint(plist);
}
void TestSList11()
{
	SLTNode* plist = NULL;
	SLPushBack(&plist, 1);
	SLPushBack(&plist, 2);
	SLPushBack(&plist, 3);
	SLPushBack(&plist, 4);
	SLTPrint(plist);
	SLTNode* pur = STFind(plist, 3);
	SLErase(&plist, pur);
	SLTPrint(plist);
	pur= STFind(plist, 1);
	SLErase(&plist, pur);
	SLTPrint(plist);
}
void TestSList12()
{
	SLTNode* plist = NULL;
	SLPushBack(&plist, 1);
	SLPushBack(&plist, 2);
	SLPushBack(&plist, 3);
	SLPushBack(&plist, 4);
	SLTPrint(plist);
	SLTNode* pur = STFind(plist, 3);
	SLEraseAfter(&plist, pur);
	SLTPrint(plist);
	pur = STFind(plist, 1);
	SLEraseAfter(&plist, pur);
	SLTPrint(plist);
}
int main()
{
	TestSList12();
	return 0;
}