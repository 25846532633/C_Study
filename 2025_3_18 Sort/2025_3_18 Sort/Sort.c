#include "Sort.h"
#include "Stack.h"

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
			//当前元素小于下一个位置的元素时，将当前元素后移
			//直到让当前元素不大于此元素
			if (a[end] > temp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else//当当前元素不大于此元素时，就可以弹出
			{
				break;
			}
		}
		//让end指向元素的下一个元素即为此元素
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
	//每次都选出一个最大值交换到最后
	//注：不是一次性选出，而是相邻元素交换得到的
	for (int i = 0; i < n; i++)
	{
		int exchange = 0;//判断本轮是否产生交换
		for (int j = 1; j < n - i; j++)
		{
			if (a[j - 1] > a[j])
			{
				exchange = 1;
				Swap(&a[j - 1], &a[j]);
			}
		}
		if (!exchange)//本轮没产生交换，就直接结束
			break;
	}
}


void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap/3+1; //每一次的gap都进行缩减
		//每一个gap都走一个插入排序
		//i < n - gap:如果=n-gap，就会越界了
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


void SelectSort(int* a, int n)
{
	//分别设置好开头和结尾
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		//刚开始，都把第一个元素设置为最大/最小值
		int max = a[begin], min = a[begin];
		//从当前元素的下一个元素开始，进行挑选
		//记住当前排序的最大和最小元素的下标
		for (int i = begin + 1; i < end; i++)
		{
			if (a[i] > max)
				max = i;
			if (a[i] < min)
				min = begin;
		}
		//分别放置到当前循环的末和尾
		Swap(&a[min], &a[begin]);
		if (max == begin) //避免max的位置在开头
		{
			max = min;
		}
		Swap(&a[max], &a[end]);

		//缩小区间范围
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
			return midi;      // begin < midi < end
		else if (a[begin] > a[end])
			return begin;       // begin < end < midi
		else
			return end;     // end < begin < midi
	}
	else //a[begin] >= a[midi]
	{
		if (a[begin] < a[end])
			return begin;
		else if (a[midi] > a[end])
			return midi;
		else
			return end;
	}
}



// hoare
int PartSort1(int* a, int begin, int end)
{
	//寻找中间数，把中间数放在开头
	int midi = GetMidi(a, begin, end);
	Swap(&a[midi], &a[begin]);

	int left = begin, right = end;
	int key = begin;

	//快速排序：先从右边找，再从左边找，然后重复来
	while (left < right)
	{
		//往右边找，一直找到比key小的数
		while (left < right && a[right] >= a[key])
		{
			--right;
		}
		//往左边找，一直找到比key大的数
		while (left < right && a[left] <= a[key])
		{
			++left;
		}
		//二者找到后交换
		Swap(&a[left], &a[right]);
	}
	//二者相遇后，交换相遇位置的值和key值
	Swap(&a[left], &a[key]);

	return left;
}


int PartSort2(int* a, int begin, int end)
{
	int mid = GetMidi(a, begin, end);
	Swap(&a[mid], &a[begin]);

	int key = a[begin];
	int hole = begin;
	while (begin < end)
	{
		//从右边开始找小
		while (begin < end && a[end] >= key)
		{
			--end;
		}

		a[hole] = a[end];
		hole = end;
		
		while (begin < end && a[begin] <= key)
		{
			++begin;
		}
		a[hole] = a[begin];
		hole = begin;
	}
	a[hole] = key;
	return hole;
}


int PartSort3(int* a, int begin, int end)
{
	int mid = GetMidi(a, begin, end);
	Swap(&a[mid], &a[begin]);
	int key = begin;

	int prev = begin;
	int cur = prev + 1;
	while (cur <= end)
	{
		
		//cur的值小于基准值key，并且与prev不相邻
		if (a[cur] < a[key] )
		{
			prev++;
			if (prev != cur)//prev与cur不重合
			{
				Swap(&a[prev], &a[cur]);
			}
		}
		++cur;
	}

	Swap(&a[prev], &a[key]);
	key = prev;
	return key;

}

void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
			return;

	
	int key = PartSort3(a, begin, end);

	QuickSort(a, begin, key - 1);
	QuickSort(a, key + 1, end);
}


void QuickSortNonR(int* a, int begin, int end)
{
	ST st;
	STInit(&st);
	//先插入最开始的首位：[end,begin]
	STPush(&st, end);
	STPush(&st, begin);

	while (!STEmpty(&st))
	{
		int left = STTop(&st);
		STPop(&st); //弹出begin
		int right = STTop(&st);
		STPop(&st); //弹出end

		//选出基准元素 - 左边比它小，右边比它大
		int key = PartSort3(a, left, right);

		//存在合法范围时，就开始分割
		if (left < key - 1)
		{
			//先插入右区间，再插入左区间（栈是从栈顶弹出的）
			STPush(&st, key - 1);
			STPush(&st, left);
		}
		if (key + 1 < right)
		{
			STPush(&st, right);
			STPush(&st, key + 1);
		}
	}
	STDestroy(&st);
}


void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;

	int mid = (begin + end) / 2;
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);
	
	// [begin, mid][mid+1, end]归并
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin;
	//目的是升序，谁小谁先插入
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	//剩余部分直接插入
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	
	//+begin主要是考虑到可能不同区间的起始位置不同
	memcpy(a + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}


void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
}

void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}

	int gap = 1;
	while (gap < n)
	{
		printf("gap:%2d->", gap);
		for (size_t i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			// [begin1, end1][begin2, end2] 归并
			//printf("[%2d,%2d][%2d, %2d] ", begin1, end1, begin2, end2);


			//边界情况1：不需要再排了 - 因为都构不成一个区间
			if (begin2 >= n || end1 >= n)
			{
				break;
			}
			//边界情况2：把第二部分的区间调整为n-1即可
			if (end2 >= n)
			{
				end2 = n - 1;
			}

			int j = begin1;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}

			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}

			memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));
		}
		printf("\n");
		gap *= 2;
	}
}

// 计数排序
// 时间：O(N+range)
// 空间：O(range)
void CountSort(int* a, int n)
{
	//本次排序为改编版
	//1.选出最大和最小的数
	int min = a[0], max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];

		if (a[i] > max)
			max = a[i];
	}
	//2.得到当前序列的值的区间范围，通过相对位置放置到对应的桶
	int range = max - min + 1;
	int* count = (int*)calloc(range, sizeof(int));
	if (count == NULL)
	{
		printf("calloc fail\n");
		return;
	}

	//3.统计次数
	for (int i = 0; i < n; i++)
	{
		//a[i]-min - 采用相对位置，放到特定位置中
		count[a[i] - min]++;
	}

	//4.排序
	int i = 0;
	for (int j = 0; j < range; j++)
	{
		//打印每个桶对应的数据
		//j+min - 得到原本的值
		while (count[j]--)
		{
			a[i++] = j + min;
		}
	}
}