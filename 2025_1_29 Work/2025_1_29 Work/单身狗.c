//#include <stdio.h>
//void findTwoNum(int arr[], int n, int* pnum1, int* pnum2)
//{
//    int i;
//    int sum = 0;
//    // 步骤1：计算所有数字的异或
//    for (i = 0; i < n; i++)
//    {
//        sum ^= arr[i];
//    }
//   // 步骤2：找到sum中为1的最低位
//    int pos = 0;
//    for (i = 0; i < 32; i++)
//    {
//        if (sum & (1 << i))
//        {
//            pos = i;
//            break;
//        }
//    }
//    // 步骤3：分组异或
//    //分组原则：x 和 y 会被分到不同组（因为这一位不同）
//    //在每个组内进行异或，成对的数字抵消，剩下就是唯一数字
//    *pnum1 = 0;
//    *pnum2 = 0;
//    for (i = 0; i < n; i++)
//    {
//        if (arr[i] & (1 << pos))
//        {
//            *pnum1 ^= arr[i];
//        }
//        else
//        {
//            *pnum2 ^= arr[i];
//        }
//    }
//}
//int main()
//{
//	int arr1[10] = { 1,2,3,4,5,1,2,3,4,6 };
//	int arr2[100] = { 0 };
//    int a, b;
//    findTwoNum(arr1, sizeof(arr1) / sizeof(arr1[0]), &a, &b);
//    printf("%d %d", a, b);
//	return 0;
//}
//
