#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType val;
}LTNode;

//初始化链表
LTNode* LTInit();
// 双向链表销毁
void ListDestory(LTNode* pHead);
// 双向链表打印
void LTPrint(LTNode* phead);
// 双向链表尾插
void LTPushBack(LTNode* phead, LTDataType x);
// 双向链表尾删
void LTPopBack(LTNode* phead);
// 双向链表头插
void ListPushFront(LTNode* pHead, LTDataType x);
// 双向链表头删
void ListPopFront(LTNode* pHead);
// 双向链表查找
LTNode* ListFind(LTNode* pHead, LTDataType x);
// 双向链表在pos的前面进行插入
void ListInsert(LTNode* pos, LTDataType x);
// 双向链表删除pos位置的节点
void ListErase(LTNode* pos);