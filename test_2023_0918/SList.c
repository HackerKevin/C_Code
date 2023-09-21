#define _CRT_SECURE_NO_WARNINGS	1
#include "SList.h"
void SLTPrint(SLTNode* phead)//phead参数用来接收链表第一个节点的地址
{
	SLTNode* cur = phead;
	while (cur != NULL)//cur不为空，说明节点还没有结束，继续打印
	{
		printf("%d->", cur->data);//打印当前节点的数据
		cur = cur->next;//获取下一个节点的地址
	}
	printf("NULL\n");
}

SLTNode* BuyLTNode(SLTDataType x)//参数x用来给当前节点的数据赋值
{
	//开辟一个节点
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)//如果开辟失败，进行提示
	{
		perror("malloc fail");
		return;
	}
	//节点开辟后
	newnode->data = x;//存入数据
	newnode->next = NULL;//默认当前为最后一个节点，所以下一个节点的地址为空
	return newnode;//返回当前节点的地址
}

void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuyLTNode(x);
	//节点开辟后
	newnode->data = x;//存入数据
	newnode->next = NULL;//默认当前为最后一个节点，所以下一个节点的地址为空

	newnode->next = *pphead;//将上一次开辟的节点的地址赋给next
	*pphead = newnode;//将刚开辟的节点的地址赋给phead
}

//void SLPushBack(SLTNode** phead, SLTDataType x)//错误版本
//{
//	SLTNode** tail = phead;
//	while (tail != NULL)                             //如果tail不是NULL，说明还没有到链表的尾部
//	{
//		tail = (*tail)->next;
//	}
//	SLTNode* newnode = BuyLTNode(x);
//	tail = newnode;                                 //将刚开辟的节点的地址赋给此时指向尾部的tail
//}

void SLPushBack(SLTNode** pphead, SLTDataType x)//pphead是一个二级指针
{
	SLTNode* newnode = BuyLTNode(x);
	if (*pphead == NULL)
	{
		(*pphead) = newnode;
	}
	else
	{
		SLTNode* tail = *pphead;//对pphead解引用，得到plist此时指向的节点的地址
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}


//void SLPopBack(SLTNode** pphead)
//{
//	SLTNode* tail = *pphead;
//	SLTNode* pretail = NULL;
//	while (tail->next)
//	{
//		pretail = tail;//pretail指向的节点始终在tail前面
//		tail = tail->next;
//	}
//	free(tail);
//	pretail->next = NULL;
//}

void SLPopBack(SLTNode** pphead)
{
	if (*pphead == NULL)//没有节点时
	{
		return;
	}
	if ((*pphead)->next == NULL)//只有一个节点时
	{
		free(*pphead);
		*pphead = NULL;
	}
	else//有多个节点时
	{
		SLTNode* tail = *pphead;
		while (tail->next->next)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}
void SLTPopFront(SLTNode** pphead)
{
	if (*pphead == NULL)//没有节点时
	{
		return;
	}
	else//有节点时
	{
		SLTNode* head = *pphead;
		*pphead = (*pphead)->next;
		free(head);
	}
}

//SLTNode* STFind(SLTNode* phead, SLTDataType x)
//{
//	SLTNode* cur = phead;
//	while (cur->next)
//	{
//		if (cur->data == x)
//		{
//			return cur;
//		}
//		cur = cur->next;
//	}
//	return NULL;
//}

SLTNode* STFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void SLInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead && pos);
	SLTNode* prepos = *pphead;
	SLTNode* newnode = BuyLTNode(x);
	if (prepos == pos)
	{
		newnode->next = pos;
		*pphead = newnode;
		//上面两句代码等价于"SLPushFront(pphead,x);"
	}
	else
	{
		while (prepos->next != pos)
		{
			prepos = prepos->next;
		}
		prepos->next = newnode;
		newnode->next = pos;
	}
}

void SLInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = BuyLTNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SLErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead && pos);
	if (pos == *pphead)//如果任意节点为第一个节点，直接使用头部删除
	{
		SLTPopFront(pphead);
	}
	else
	{
		SLTNode* prepos = *pphead;
		while (prepos->next != pos)
		{
			prepos = prepos->next;
		}
		prepos->next = pos->next;
		free(pos);
	}
}

//void SLEraseAfter(SLTNode** pphead, SLTNode* pos)
//{
//	assert(pos && pos->next);
//	SLTNode* aftpos = *pphead;
//	while (aftpos != pos->next)
//	{
//		aftpos = aftpos->next;
//	}
//	pos->next = NULL;
//	free(aftpos);
//}

//void SLEraseAfter(SLTNode** pphead, SLTNode* pos)
//{
//	assert(pos && pos->next);
//	SLTNode* aftpos = *pphead;
//	while (aftpos != pos->next)
//	{
//		aftpos = aftpos->next;
//	}
//	pos->next = aftpos->next;
//	free(aftpos);
//}

void SLEraseAfter(SLTNode** pphead, SLTNode* pos)
{
	assert(pos && pos->next);;
	SLTNode* aftpos = pos->next;
	pos->next = aftpos->next;
	free(aftpos);
}