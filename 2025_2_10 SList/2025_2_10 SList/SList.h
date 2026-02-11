#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


typedef int DataType;

typedef struct SListNode
{
	int val;
	struct SListNode* next;
}SLNode;


void SLTPrint(SLNode* phead);
void SLTPushBack(SLNode** pphead, DataType x);
void SLTPushFront(SLNode** pphead, DataType x);

void SLTPopBack(SLNode** pphead);
void SLTPopFront(SLNode** pphead);

SLNode* SLTFind(SLNode* phead, DataType x);
void SLTInsert(SLNode** pphead, SLNode* pos, DataType x);

// 删除pos位置
void SLTErase(SLNode** pphead, SLNode* pos);

// 后面插入 后面删除
void SLTInsertAfter(SLNode* pos, DataType x);
void SLTEraseAfter(SLNode* pos);