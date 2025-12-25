#include <stdio.h>
//struct Stu
//{
//	char name[20];//名字
//	int age;//年龄
//	char sex[5];//性别
//	char id[20];//学号
//};
//
//
//int main()
//{
//	//按照结构体成员的顺序初始化
//	struct Stu s = { "张三", 20, "男", "20230818001" };
//	printf("name: %s\n", s.name);
//	printf("age : %d\n", s.age);
//	printf("sex : %s\n", s.sex);
//	printf("id  : %s\n", s.id);
//	//按照指定的顺序初始化
//	struct Stu s2 = { .age = 18, .name = "lisi", .id = "20230818002", .sex = "女" };
//	printf("name: %s\n", s2.name);
//	printf("age : %d\n", s2.age);
//	printf("sex : %s\n", s2.sex);
//	printf("id  : %s\n", s2.id);
//	return 0;
//}

//struct
//{
//	int a;
//	char b;
//	float c;
//}x;
//struct
//{
//	int a;
//	char b;
//	float c;
//}a[20], * p;
//
//int main()
//{
//	p = &x;
//	return 0;
//}
//struct Stu
//{
//	char name[20];
//	int age;
//};
//void print(struct Stu* ps)
//{
//	printf("name = %s   age = %d\n", (*ps).name, (*ps).age);
//	//使用结构体指针访问指向对象的成员
//	printf("name = %s   age = %d\n", ps->name, ps->age);
//}
//int main()
//{
//	struct Stu s = { "zhangsan", 20 };
//	print(&s);//结构体地址传参
//	return 0;
//}