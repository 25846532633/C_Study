#include"SeqList.h"
//初始化
void SLInit(SL* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SLDestroy(SL* ps)
{
	assert(ps);

	free(ps->a);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SLPrint(SL* ps)
{
	assert(ps && ps->a);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");//注意最后要加换行符
}

void SLCheckCapacity(SL* ps)
{
	assert(ps);

	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		int* temp = (int*)realloc(ps->a, sizeof(DataType) * newcapacity);
		if (temp == NULL)
		{
			perror("realloc failed");
			return;
		}
		ps->a = temp;
		ps->capacity = newcapacity;
		printf("扩容成功\n");
	}
}

void SLPushBack(SL* ps, DataType x)
{
	assert(ps);
	//要记得先检查容量
	SLCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

void SLPushFront(SL* ps, DataType x)
{
	assert(ps);
	SLCheckCapacity(ps);

	int start = 0;
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}

void SLPopBack(SL* ps)
{
	assert(ps->size > 0);
	ps->size--;
}

void SLPopFront(SL* ps)
{
	assert(ps->size > 0);

	int start = 0;
	int end = ps->size - 1;
	while (start < end)
	{
		ps->a[start] = ps->a[start + 1];
		start++;
	}
	ps->size--;
}

void SLInsert(SL* ps, int pos, DataType x)
{
	assert(ps);

	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[end + 1] = x;
	ps->size++;
}

void SLErase(SL* ps, int pos)
{
	assert(ps);
	
	int end = ps->size - 1;
	while (pos < end)
	{
		ps->a[pos] = ps->a[pos+1];
		pos++;
	}
	ps->size--;
}


int SLFind(SL* ps, DataType x)
{
	assert(ps);

	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}