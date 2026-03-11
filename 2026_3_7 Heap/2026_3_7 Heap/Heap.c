#include "Heap.h"

void HeapInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->size = php->capacity = 0;
}

void HeapDestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->size = php->capacity = 0;
}

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
//向上调整
void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}


void HeapPush(HP* php, HPDataType x)
{
	assert(php);

	if (php->size == php->capacity)
	{
		int newcapacity = php->capacity == 0 ? 4 : 2 * php->capacity;
		HPDataType* tmp = (HPDataType*)realloc(php->a, sizeof(HPDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc failed");
			exit(-1);
		}
		

		php->a = tmp;
		php->capacity = newcapacity;
	}
	php->a[php->size] = x;
	php->size++;

	AdjustUp(php->a, php->size - 1);
}

void AdjustDown(HPDataType* a, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		//要判断一下左右两边那个更小，更小的才上去
		//只是本身默认左边而已
		if (child + 1 < size && a[child] < a[child + 1])
		{
			child = child + 1;
		}
		
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapPop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	//首尾交换
	Swap(&php->a[php->size - 1], &php->a[0]);
	php->size--;

	AdjustDown(php->a, php->size,0);
}

HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	return php->a[0];
}

size_t HeapSize(HP* php)
{
	assert(php);
	return php->size;
}

bool HeapEmpty(HP* php)
{
	assert(php);
	if (php->size == 0)
		return true;
	else
		return false;
}

void HeapSort(int* a, int n)
{
	// 建大堆
	// O(N*logN)
	/*for (int i = 1; i < n; i++)
	{
		AdjustUp(a, i);
	}*/

	// O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);      // 将堆顶（最大元素）放到末尾
		AdjustDown(a, end, 0);      // 重新调整堆结构
		--end;                       // 缩小堆的范围
	}
}