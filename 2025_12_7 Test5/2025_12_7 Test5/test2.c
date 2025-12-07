////#define _CRT_SECURE_NO_WARNINGS
////#include <stdio.h>
////
////int is_leap_year(int y)
////{
////	if ((y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0))
////		return 1;
////	else
////		return 0;
////}
////
////int month_days_get(int y, int m)
////{
////	int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
////	int day = days[m];
////	if (is_leap_year(y) && m == 2)
////		day += 1;
////	return day;
////}
////
////int main()
////{
////	int y = 0;
////	int m = 0;
////	scanf("%d %d", &y, &m);
////	int d = month_days_get(y, m);
////	printf("%d\n", d);
////	return 0;
////}
//
//#include <stdio.h>
//#include "Add.h"
//
//int main()
//{
//	int a = Add(2, 3);
//	printf("%d", a);
//	return 0;
//}
//
