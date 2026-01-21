#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Contact.h"

void menu()
{
	printf("********************************\n");
	printf("**** 1. add        2. del   ****\n");
	printf("**** 3. search     4.modify ****\n");
	printf("**** 5. show       6. sort  ****\n");
	printf("**** 0. exit                ****\n");
	printf("********************************\n");
}

enum Option
{
	EXIT,//0
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};


int main()
{
	int input = 0;
	Contact con;//通讯录
	InitContact(&con);
	do
	{
		menu();
		printf("请输入选项：>");
		scanf("%d", &input);
		int test = 0;
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			//排序  -qsort
			//按照什么排序?
			printf("请问你需要按照什么排序?\n");
			scanf("%d", &test);
			if (test == 1)
			{
				printf("按照年龄排序\n");
				sort_age(&con);
			}
			else
			{
				printf("按照姓名排序\n");
				sort_name(&con);
			}
			break;
			break;
		case EXIT:
			//DestroyContact(&con);
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误，重新选择\n");
			break;
		}
	} while(input);
	return 0;
}