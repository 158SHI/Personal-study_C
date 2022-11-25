#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<errno.h>

//int main()
//{
//	FILE *pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//fgetc()
//int main()
//{
//	FILE* pf = fopen("testin.txt", "r");
//	//if (pf != NULL)
//	//{
//	//	fputc('h', pf);
//	//	fputc('e', pf);
//	//	fputc('h', pf);
//	//	fputc('e', pf);
//	//}
//
//	printf("%c", fgetc(pf));
//	printf("%c", fgetc(pf));
//	printf("%c", fgetc(pf));
//	printf("%c", fgetc(pf));
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	char ch = fgetc(stdin);//fgetc将stdin中的一个字符读出，返回该字符
//	fputc(ch, stdout);//fputc将ch写入stdout
//	return 0;
//}

int main()
{
	char arr[1024] = { 0 };
	fgets(arr,1024,stdin);
	fputs(arr, stdout);
	return 0;
}