#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


typedef int DataType;

typedef struct SeqList
{
	DataType* a;
	int size;
	int capacity;
}SL;

//初始化和销毁
void SLInit(SL* ps);
void SLDestroy(SL* ps);

//打印和扩容
void SLPrint(SL* psl);
void SLCheckCapacity(SL* psl);

//头尾删除
void SLPushBack(SL* ps, DataType x);
void SLPushFront(SL* ps, DataType x);
void SLPopBack(SL* ps);
void SLPopFront(SL* ps);

// 任意下标位置的插入删除
void SLInsert(SL* ps, int pos, DataType x);
void SLErase(SL* ps, int pos);

// 找到返回下标
// 没有找到返回-1
int SLFind(SL* ps, DataType x);