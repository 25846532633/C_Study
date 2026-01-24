#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NAME_MAX 20
#define SEX_MAX 5
#define TELE_MAX 12
#define ADDR_MAX 30

#define MAX 100

#define DEFAULT_SZ 3
#define DEFAULT_INC 2
typedef struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
}PeoInfo;

//动态通讯录的版本
typedef struct Contact
{
	PeoInfo* data;//存放数据
	int sz;//记录的时当前通讯录中存放的人的信息个数
	int capacity;//记录的是通讯录的当前容量
}Contact;

//typedef struct Contact
//{
//	PeoInfo data[MAX];
//	int sz;//记录当前通讯录中存放的个人信息的个数
//}Contact;

//初始化通讯录
void InitContact(Contact* pc);

//增加联系人
void AddContact(Contact* pc);

//显示所有的联系人
void ShowContact(const Contact* pc);

//删除指定联系人
void DelContact(Contact* pc);

//查找指定联系人
void SearchContact(Contact* pc);

//修改指定联系人
void ModifyContact(Contact* pc);

//排序
void sort_age(Contact* pc);
void sort_name(Contact* pc);

//销毁通讯录
void DestroyContact(Contact* pc);