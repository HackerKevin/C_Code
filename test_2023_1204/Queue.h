#pragma once
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

typedef int QDataType;
typedef struct QueueNode//节点的结构
{
	struct QueueNode* next;
	QDataType data;
}QNode;
 
struct Queue//标识整个队列
{
	QNode* phead;
	QNode* ptail;
	int size;
};

void QueueInit();