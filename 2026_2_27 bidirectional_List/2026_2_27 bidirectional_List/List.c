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
	printf("\n");
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

void ListDestory(LTNode* pHead)
{
	pHead->next = NULL;
	pHead->prev = NULL;
	free(pHead);
	pHead = NULL;
}

// 双向链表头插
void ListPushFront(LTNode* pHead, LTDataType x)
{
	assert(pHead);
	LTNode* next = pHead->next;
	LTNode* newnode = CreateLTNode(x);

	newnode->next = next;
	next->prev = newnode;

	pHead->next = newnode;
	newnode->prev = pHead;
}

// 双向链表头删
void ListPopFront(LTNode* pHead)
{
	assert(pHead);

	struct ListNode* cur = pHead->next;
	struct ListNode* next = cur->next;

	pHead->next = next;
	next->prev = pHead;

	free(cur);
	
}


// 双向链表查找
LTNode* ListFind(LTNode* pHead, LTDataType x)
{
	struct ListNode* cur = pHead->next;
	while (cur != pHead)
	{	
		if (cur->val == x)
			return cur;
		cur = cur->next;
	}
	return -1;//没找到
}

// 双向链表在pos的前面进行插入
void ListInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	
	LTNode* cur = CreateLTNode(x);
	LTNode* prev1 = pos->prev;
	
	prev1->next = cur;
	cur->prev = prev1;

	cur->next = pos;
	pos->prev = cur;
}

// 双向链表删除pos位置的节点
void ListErase(LTNode* pos)
{
	assert(pos);
	struct ListNode* next = pos->next;
	struct ListNode* prev = pos->prev;

	next->prev = prev;
	prev->next = next;
}