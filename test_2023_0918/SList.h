#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLTDataType;
typedef struct SlistNode
{
	SLTDataType data;
	struct SlistNode* next;
}SLTNode;

void SLTPrint(SLTNode* phead);
void SLTPushFront(SLTNode** pphead, SLTDataType x);
void SLPushBack(SLTNode** pphead, SLTDataType x);
void SLInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);//��pos֮ǰ����
void SLInsertAfter(SLTNode* pos, SLTDataType x);//��pos֮�����
void SLErase(SLTNode** pphead, SLTNode* pos);//ɾ��posλ��
void SLEraseAfter(SLTNode** pphead, SLTNode* pos);

void SLTPopFront(SLTNode** phead);
void SLPopBack(SLTNode** pphead);

SLTNode* STFind(SLTNode* phead, SLTDataType x);//���������