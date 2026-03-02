#include "List.h"
#include <stdio.h>

void test1()
{
	LTNode* plist = LTInit();
	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 5);
	LTPushBack(plist, 4);

	LTPrint(plist);
	LTNode* find = ListFind(plist, 3);
	LTPrint(plist);
	ListInsert(find,10);
	LTPrint(plist);
	ListErase(find);
	LTPrint(plist);
	/*printf("\n");
	LTPopBack(plist);
	LTPrint(plist);
	printf("\n");
	ListPushFront(plist, 2);
	LTPrint(plist);printf("\n");
	ListPopFront(plist);
	LTPrint(plist);*/
}


int main()
{
	test1();
}