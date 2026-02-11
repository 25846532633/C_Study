#include "SList.h"

void SLTPrint(SLNode* phead)
{
	assert(phead);
	SLNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}

SLNode* CreateNode(DataType x)
{
	SLNode* temp = (SLNode*)malloc(sizeof(SLNode));
	if (temp == NULL)
	{
		perror("malloc failed");
		return;
	}
	temp->val = x;
	temp->next = NULL;
	return temp;
}


void SLTPushBack(SLNode** pphead, DataType x)
{
	assert(pphead);
	
	if (*pphead == NULL)
	{
		SLNode* newnode = CreateNode(x);
		*pphead = newnode;
	}
	else
	{
		//创建新节点
		SLNode* newnode = CreateNode(x);

		SLNode* cur = *pphead;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newnode;
	}
}

void SLTPushFront(SLNode** pphead, DataType x)
{
	assert(pphead);
	SLNode* newnode = CreateNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void SLTPopBack(SLNode** pphead)
{
	assert(pphead);
	if((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLNode* cur = *pphead;
		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}


void SLTPopFront(SLNode** pphead)
{
	assert(pphead);
	SLNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}


SLNode* SLTFind(SLNode* phead, DataType x)
{
	assert(phead);
	SLNode* cur = phead;
	while (cur->next != NULL)
	{
		if (cur->val == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}


void SLTInsert(SLNode** pphead, SLNode* pos, DataType x)
{
	assert(pphead);
	assert(pos);
	assert(*pphead);

	if (*pphead == pos)
	{
		SLTPushFront(pphead, x);
	}
	else
	{
		SLNode* cur = *pphead;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		SLNode* newnode = CreateNode(x);
		cur->next = newnode;
		newnode->next = pos;
	}
}

void SLTErase(SLNode** pphead, SLNode* pos)
{
	assert(pphead);
	assert(*pphead);
	assert(pos);

	if (*pphead == pos)
	{
		// 头删
		SLTPopFront(pphead);
	}
	else
	{
		SLNode* cur = *pphead;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		cur->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

void SLTInsertAfter(SLNode* pos, DataType x)
{
	assert(pos);
	SLNode* newnode = CreateNode(x);
	
	newnode->next = pos->next;
	pos->next = newnode;
}

void SLTEraseAfter(SLNode* pos)
{
	assert(pos);
	assert(pos->next);

	SLNode* next = pos->next;
	pos->next = next->next;
	free(next);
	next = NULL;
}
