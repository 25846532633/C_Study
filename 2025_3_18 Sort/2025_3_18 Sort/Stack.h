#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>


typedef char STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;		// 标识栈顶位置的
	int capacity;
}ST;

void STInit(ST* pst);
void STDestroy(ST* pst);

// 栈顶插入删除
void STPush(ST* pst, STDataType x);
void STPop(ST* pst);
STDataType STTop(ST* pst);

bool STEmpty(ST* pst);
int STSize(ST* pst);