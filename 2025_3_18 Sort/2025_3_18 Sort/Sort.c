#include "Sort.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++) 
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int temp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > temp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}

		}
		a[end + 1] = temp;

	}
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		int flag = 0;
		for (int j = 1; j < n - i; j++)
		{
			if (a[j - 1] > a[j])
			{
				flag = 1;
				Swap(&a[j - 1], &a[j]);
			}
		}
		if (flag == 0)
			break;
	}
}

void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap/3+1; //每一次的gap都进行缩减
		for (int i = 0; i < n - gap; i++)
		{

			int end = i;
			int temp = a[end + gap];

			while (end >= 0)
			{
				if (temp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = temp;
		}
	}
}

//选择排序：每次都选出最大和最小的数
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int min = begin,max = begin;
		for (int i = begin+1; i <= end; i++)
		{
			if (a[i] < a[min])
				min = i;
			if (a[i] > a[max])
				max = i;

		}
		//分别放置在当前区间的最开头和最末尾
		Swap(&a[begin], &a[min]);
		if (max == begin) //避免max的位置在开头
		{
			max = min;
		}
		Swap(&a[end], &a[max]);

		++begin;
		--end;

	}
}

void AdjustDown(int* a, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child + 1] > a[child])
			child = child + 1;
		
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

//堆排序
//升序：建大堆
//降序：建小堆
void HeapSort(int* a, int n)
{
	//从有子节点的树开始建起
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}


	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

int GetMidi(int* a, int begin, int end)
{
	int midi = (begin + end) / 2;
	// begin end midi三个数选中位数
	if (a[begin] < a[midi])
	{
		if (a[midi] < a[end])
			return midi;
		else if (a[begin] > a[end])
			return begin;
		else
			return end;
	}
	else //a[begin] > a[midi]
	{
		if (a[begin] < a[end])
			return begin;
		else if (a[midi] > a[end])
			return midi;
		else
			return end;
	}
}


void QuickSort(int* a, int begin, int end)
{
	//说明排序已完成
	if (begin >= end)
		return;

	//寻找中间数，把中间数放在开头
	int midi = GetMidi(a, begin, end);
	Swap(&a[midi], &a[begin]);

	int left = begin, right = end;
	int key = begin;

	while (left < right)
	{
		//往右边找，一直找到比key小的数
		while(left < right && a[right] >= a[key])
		{
			--right;
		}
		//往左边找，一直找到比key大的数
		while (left < right && a[left] <= a[key])
		{
			++left;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[left], &a[key]);
	key = left;


	QuickSort(a, begin, key - 1);
	QuickSort(a, key + 1, end);
}