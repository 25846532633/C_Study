#include "Stack.h"

void STInit(ST* pst)
{
	assert(pst);

	pst->a = NULL;
	pst->top = 0;
	pst->capacity = 0;
}

void STDestroy(ST* pst)
{
	free(pst->a);
	pst->a = NULL;
	pst->top = 0;
	pst->capacity = 0;
}

void STPush(ST* pst, STDataType x)
{
	assert(pst);
	//ÈÝÁ¿²»×ãÒªÀ©ÈÝ
	if (pst->top == pst->capacity)
	{
		int newcapacity = pst->capacity == 0 ? 4 : 2 * pst->capacity;
		ST* temp = (ST*)realloc(pst->a, sizeof(ST) * newcapacity);
		if (temp == NULL)
		{
			perror("realloc failed");
			return -1;
		}
		pst->a = temp;
		pst->capacity = newcapacity;
	}
	pst->a[pst->top] = x;
	pst->top++;
}


void STPop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);
	pst->top--;
}

STDataType STTop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);

	STDataType a = pst->a[pst->top - 1];
	return a;
}

bool STEmpty(ST* pst)
{
	if (pst->top == 0)
		return true;
	return false;
}



int STSize(ST* pst)
{
	return pst->top;
}