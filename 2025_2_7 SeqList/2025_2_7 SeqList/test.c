#include "SeqList.h"


void Test1()
{
	SL s1;
	SLInit(&s1);

	/*SLPushBack(&s1, 1);
	SLPushBack(&s1, 1);
	SLPushBack(&s1, 1);
	SLPushBack(&s1, 1);
	SLPushBack(&s1, 1);*/

	SLPushFront(&s1, 1);
	SLPushFront(&s1, 2);
	SLPushFront(&s1, 3);
	SLPushFront(&s1, 4);
	SLPrint(&s1);
	SLPopBack(&s1);
	SLPrint(&s1);
	SLPopFront(&s1);
	SLPrint(&s1);

	SLDestroy(&s1);
}

void Test2()
{
	SL s1;
	SLInit(&s1);

	SLPushBack(&s1, 1);
	SLPushBack(&s1, 2);
	SLPushBack(&s1, 3);
	SLPushBack(&s1, 4);
	SLErase(&s1,2);
	SLPrint(&s1);
	printf("%d",SLFind(&s1, 2));
}


int main()
{
	//Test1();
	Test2();
	return 0;
}