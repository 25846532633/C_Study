#include "SList.h"

void test1()
{
	SLNode* s1 = NULL;
	SLTPushBack(&s1, 1);
	SLTPushBack(&s1, 2);
	SLTPushBack(&s1, 3);
	SLTPushBack(&s1, 4);
	SLTPrint(s1);
	SLTPushFront(&s1, 5);
	SLTPrint(s1);
	SLTPopBack(&s1);
	SLTPrint(s1);
	/*SLTPopBack(&s1);
	SLTPrint(s1);
	SLTPopBack(&s1);*/
	SLTPopFront(&s1);
	SLTPrint(s1);
}

void test2()
{
	SLNode* plist = NULL;
	SLTPushFront(&plist, 1);
	SLTPushFront(&plist, 2);
	SLTPushFront(&plist, 3);
	SLTPushFront(&plist, 4);
	SLTPrint(plist);

	//SLTPopFront(&plist);
	//SLTPrint(plist);

	SLNode* pos = SLTFind(plist, 3);
	SLTInsert(&plist, pos, 30);
	SLTPrint(plist);
	SLTEraseAfter(pos);
	SLTPrint(plist);
}

int main()
{
	//test1();
	test2();
	return 0;
}