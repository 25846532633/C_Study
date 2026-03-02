#include "Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = NULL;
	pq->ptail = NULL;
	pq->size = 0;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);
	//把每个节点都释放
	QNode* cur = pq->phead;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);

	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc failed");
		return -1;
	}

	if (pq->ptail == NULL) 
	{
		pq->phead = pq->ptail = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
	newnode->val = x;
	newnode->next = NULL;

	pq->size++;
}


void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->phead);
	
	QNode* cur = pq->phead;
	QNode* next = pq->phead->next;
	pq->phead = next;
	free(cur);
	cur = NULL;

	if (pq->phead == NULL)
		pq->ptail = NULL;
	pq->size--;
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->phead);

	return pq->phead->val;
}


QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->ptail);

	return pq->ptail->val;
}

int QueueSize(Queue* pq)
{
	assert(pq);

	return pq->size;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->phead == NULL;
}