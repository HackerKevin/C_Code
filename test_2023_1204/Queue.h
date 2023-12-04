#pragma once
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

typedef int QDataType;
typedef struct QueueNode//�ڵ�Ľṹ
{
	struct QueueNode* next;
	QDataType data;
}QNode;
 
struct Queue//��ʶ��������
{
	QNode* phead;
	QNode* ptail;
	int size;
};

void QueueInit();