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
	printf("\n");
	LTPopBack(plist);
	LTPrint(plist);
}


int main()
{
	test1();
}