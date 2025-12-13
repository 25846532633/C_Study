#include <stdio.h>


int main()
{
    int a = 10;//1010
    int b = 9;//1001
    int n = a ^ b;//0011
    int count = 0;
    while (n)
    {
        count++;
        n &= (n - 1);
    }
    printf("%d", count);
    return 0;
}