#include "Stack.h"
#include "Queue.h"
void test1()
{
	ST s;
	STInit(&s);
	STPush(&s, 1);
	STPush(&s, 2);
	STPush(&s, 3);
	printf("%d ", STTop(&s));
	STPop(&s);
	printf("%d ", STTop(&s));
	STPop(&s);

	STPush(&s, 4);
	STPush(&s, 5);

	//    一     对     多
	// 入栈顺序  --  出栈顺序
	while (!STEmpty(&s))
	{
		printf("%d ", STTop(&s));
		STPop(&s);
	}
	printf("\n");

}


int main()
{
	//test1();
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	printf("%d ", QueueFront(&q));
	QueuePop(&q);
	printf("%d ", QueueFront(&q));
	QueuePop(&q);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}

	QueueDestroy(&q);
	return 0;
}