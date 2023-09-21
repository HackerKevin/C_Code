#define _CRT_SECURE_NO_WARNINGS	1
#include "SList.h"
void SLTPrint(SLTNode* phead)//phead�����������������һ���ڵ�ĵ�ַ
{
	SLTNode* cur = phead;
	while (cur != NULL)//cur��Ϊ�գ�˵���ڵ㻹û�н�����������ӡ
	{
		printf("%d->", cur->data);//��ӡ��ǰ�ڵ������
		cur = cur->next;//��ȡ��һ���ڵ�ĵ�ַ
	}
	printf("NULL\n");
}

SLTNode* BuyLTNode(SLTDataType x)//����x��������ǰ�ڵ�����ݸ�ֵ
{
	//����һ���ڵ�
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)//�������ʧ�ܣ�������ʾ
	{
		perror("malloc fail");
		return;
	}
	//�ڵ㿪�ٺ�
	newnode->data = x;//��������
	newnode->next = NULL;//Ĭ�ϵ�ǰΪ���һ���ڵ㣬������һ���ڵ�ĵ�ַΪ��
	return newnode;//���ص�ǰ�ڵ�ĵ�ַ
}

void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuyLTNode(x);
	//�ڵ㿪�ٺ�
	newnode->data = x;//��������
	newnode->next = NULL;//Ĭ�ϵ�ǰΪ���һ���ڵ㣬������һ���ڵ�ĵ�ַΪ��

	newnode->next = *pphead;//����һ�ο��ٵĽڵ�ĵ�ַ����next
	*pphead = newnode;//���տ��ٵĽڵ�ĵ�ַ����phead
}

//void SLPushBack(SLTNode** phead, SLTDataType x)//����汾
//{
//	SLTNode** tail = phead;
//	while (tail != NULL)                             //���tail����NULL��˵����û�е������β��
//	{
//		tail = (*tail)->next;
//	}
//	SLTNode* newnode = BuyLTNode(x);
//	tail = newnode;                                 //���տ��ٵĽڵ�ĵ�ַ������ʱָ��β����tail
//}

void SLPushBack(SLTNode** pphead, SLTDataType x)//pphead��һ������ָ��
{
	SLTNode* newnode = BuyLTNode(x);
	if (*pphead == NULL)
	{
		(*pphead) = newnode;
	}
	else
	{
		SLTNode* tail = *pphead;//��pphead�����ã��õ�plist��ʱָ��Ľڵ�ĵ�ַ
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
//		pretail = tail;//pretailָ��Ľڵ�ʼ����tailǰ��
//		tail = tail->next;
//	}
//	free(tail);
//	pretail->next = NULL;
//}

void SLPopBack(SLTNode** pphead)
{
	if (*pphead == NULL)//û�нڵ�ʱ
	{
		return;
	}
	if ((*pphead)->next == NULL)//ֻ��һ���ڵ�ʱ
	{
		free(*pphead);
		*pphead = NULL;
	}
	else//�ж���ڵ�ʱ
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
	if (*pphead == NULL)//û�нڵ�ʱ
	{
		return;
	}
	else//�нڵ�ʱ
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
		//�����������ȼ���"SLPushFront(pphead,x);"
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
	if (pos == *pphead)//�������ڵ�Ϊ��һ���ڵ㣬ֱ��ʹ��ͷ��ɾ��
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