#include "Contact.h"

void InitContact(Contact* pc)
{
	assert(pc);
	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));
}

//增加联系人
void AddContact(Contact* pc)
{
	assert(pc);
	if (pc->sz == MAX)//满了
	{
		printf("当前通讯录已满.\n");
		return;
	}
	//没满就加
	printf("请输入名字:");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄:");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入性别:");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入电话:");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入地址:");
	scanf("%s", pc->data[pc->sz].addr);

	//总量要加
	pc->sz++;
}

//显示所有的联系人
void ShowContact(const Contact* pc)
{
	assert(pc);
	if (pc->sz == 0)
	{
		printf("通讯录为空，无需打印\n");
		return;
	}

	printf("%-20s%-5s%-5s%-12s%-30s\n", "名字", "年龄", "性别", "电话", "地址");
	for (int i = 0; i < pc->sz; i++)
	{
		printf("%-20s%-5d%-5s%-12s%-30s\n",
			pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tele, pc->data[i].addr);
	}
}

static int FindByName(Contact* pc, char name[])
{
	assert(pc);
	for (int i = 0; i < pc->sz; i++)
	{
		if (strcmp(name, pc->data[i].name) == 0)
		{
			return i;
		}
	}
	return -1;
}

//删除联系人
//1.输入姓名 2.查找是否存在此人 3.查找到后删除/没有就不删
void DelContact(Contact* pc)
{
	assert(pc);
	char name[NAME_MAX];
	if (pc->sz == 0)
	{
		printf("通讯录已空,无法进行删除\n");
		return;
	}
	printf("输入要删除的人的名字:");
	scanf("%s", name);
	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
	//开始删除
	for (int i = ret; i < pc->sz - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("删除成功\n");
}

//查找指定联系人
void SearchContact(Contact* pc)
{
	char name[NAME_MAX];
	assert(pc);
	printf("请输入要查找人的名字:");
	scanf("%s", name);
	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("你要查找的人不存在\n");
		return;
	}
	printf("%-20s%-5s%-5s%-12s%-30s\n", "名字", "年龄", "性别", "电话", "地址");
	printf("%-20s%-5d%-5s%-12s%-30s\n",
		pc->data[ret].name, pc->data[ret].age, pc->data[ret].sex, pc->data[ret].tele, pc->data[ret].addr);
}

//修改指定联系人
void ModifyContact(Contact* pc)
{
	char name[NAME_MAX];
	assert(pc);
	printf("请输入要修改人的名字:");
	scanf("%s", name);
	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("要修改的人不存在\n");
		return;
	}
	//修改
	printf("请输入名字:");
	scanf("%s", pc->data[ret].name);
	printf("请输入年龄:");
	scanf("%d", &(pc->data[ret].age));
	printf("请输入性别:");
	scanf("%s", pc->data[ret].sex);
	printf("请输入电话:");
	scanf("%s", pc->data[ret].tele);
	printf("请输入地址:");
	scanf("%s", pc->data[ret].addr);

	printf("修改成功\n");
}

int Compare(const void* a, const void* b)
{
	return ((PeoInfo*)a)->age - ((PeoInfo*)b)->age;
}

void sort_age(Contact* pc)
{
	assert(pc);
	qsort(pc->data, pc->sz, sizeof(PeoInfo), Compare);
}

int Compare2(const void* a, const void* b)
{
	return strcmp(((PeoInfo*)a)->name, ((PeoInfo*)b)->name);
}
void sort_name(Contact* pc)
{
	assert(pc);
	qsort(pc->data, pc->sz, sizeof(PeoInfo), Compare2);
}