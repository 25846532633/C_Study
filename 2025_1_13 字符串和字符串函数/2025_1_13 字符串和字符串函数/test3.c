#define _CRT_SECURE_NO_WARNINGS	
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <errno.h>
//int main()
//{
//	char arr[] = "192.168.224@qq.com";
//	char* seq = ".@";
//	char* str = NULL;
//	str = strtok(arr, seq);//192
//	printf("%s\n", str);
//	str = strtok(NULL, seq);//168
//	printf("%s\n", str);
//	str = strtok(NULL, seq);//224
//	printf("%s\n", str);
//	str = strtok(NULL, seq);//qq
//	printf("%s\n", str);
//	str = strtok(NULL, seq);//com
//	printf("%s\n", str);
//	printf("%s", str);//com
//	return 0;
//}

//int main()
//{
//	for (int i = 0; i <= 10; i++) {
//		printf("%s\n", strerror(i));
//	}
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    FILE* pFile;
//    pFile = fopen("unexist.ent", "rb");
//    if (pFile == NULL)
//        perror("The following error occurred");
//    else
//        fclose(pFile);
//    return 0;
//}
//#include <stdio.h>
//#include <ctype.h>
//int main()
//{
//	int i = 0;
//	char str = 'a';
//	printf("%d\n", islower(str));
//	printf("%d\n", isupper(str));
//	printf("%d\n", isalnum(str));
//	printf("%d", isalpha(str));
//	return 0;
//}

#include <stdio.h>
#include <ctype.h>
int main()
{
	int i = 0;
	char str[] = "Test String.\n";
	char c;
	while (str[i])
	{
		c = str[i];
		if (islower(c))
			c = toupper(c);
		putchar(c);
		i++;
	}
	return 0;
}