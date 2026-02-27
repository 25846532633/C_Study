#include "List.h"

LTNode* CreateLTNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("malloc failed");
		return -1;
	}
	newnode->val = x;
	newnode->next = NULL;
	newnode->prev = NULL;
}

LTNode* LTInit()
{
	LTNode* phead = CreateLTNode(-1);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

void LTPrint(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d<=>", cur->val);
		cur = cur->next;
	}
}

void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* tail = phead->prev;
	LTNode* newnode = CreateLTNode(x);

	tail->next = newnode;
	newnode->next = phead;
	newnode->prev = tail;
	phead->prev = newnode;
}

void LTPopBack(LTNode* phead)
{
	assert(phead);

	LTNode* tail = phead->prev;
	
	phead->prev = tail->prev;
	tail->prev->next = phead;

	free(tail);
	
}