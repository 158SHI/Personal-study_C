#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<assert.h>

//int main()
//{
//	char arr[1024] = { 0 };
//	fgets(arr, 1024, stdin);
//	fputs(arr, stdout);
//	return 0;
//}

//ģ��ʵ��strcpy

//char* my_strcpy(char* dest, const char* sour)
//{
//	assert(dest && sour);
//	char* ret = dest;
//	while (*dest++ = *sour++)
//	{
//		;
//	}
//	return dest;
//}
//
//int main()
//{
//	char arr1[20] = { 0 };
//	char arr2[20] = "hello,world!!!";
//	my_strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}

//size_t my_strlen(const char* p)
//{
//	assert(p);
//	char* end = p;
//	while (*end++);
//	return end - p - 1;
//}
//
//int main()
//{
//	int ret = my_strlen("hello");
//	printf("%d", ret);
//	return 0;
//}

//ͨ���������˽����������߼�
//int main()
//{
//	int i = 1;
//	int n = (++i) + (++i) + (++i);
//	printf("%d\n", n);
//	return 0;
//}

//�ļ������ж�

//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 0;
//	}
//
//	int ch = 0;//ע����int ch����ΪҪ�ж�EOF
//	while ((ch = fgetc(pf)) != EOF)
//	{
//		putchar(ch);
//	}
//
//	//�ж��ļ�����ԭ��
//	if (ferror(pf))
//	{
//		printf("error\n");
//	}
//	else if (feof(pf))
//	{
//		printf("end of file!\n");
//	}
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	FILE *pf = fopen("test2.txt", "w+");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 0;
//	}
//
//	char arrin[20] = { 0 };
//	scanf("%s", arrin);
//
//	fputs(arrin, pf);
//
//	fclose(pf);//�ļ��رպ�ŻὫ����д���ļ�
//	pf = NULL;
//
//	return 0;
//}

//ģ��ʵ��strcpy

//char* my_strcpy(char *dest, char *sour)
//{
//	assert(dest && sour);
//	char* ret = dest;
//	while (*dest++ = *sour++)
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	char arr_sour[10] = "hello!";
//	char arr_dest[10] = { 0 };
//	my_strcpy(arr_dest, arr_sour);
//	printf("%s\n", arr_dest);
//	return 0;
//}

//size_t my_strlen(const char* parr)
//{
//	assert(parr);
//	char* end = parr;
//	while (*end++)
//	{
//		;
//	}
//	return end - parr - 1;
//}
//
//int main()
//{
//	char arr[10] = "hello!";
//	int ret = my_strlen(arr);
//	printf("%d\n", ret);
//	return 0;
//}

//ѡ������

//void swap(int* x, int* y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//
//void SelectSort(const int* p, const int sz)
//{
//	assert(p != NULL);
//	for (int i = 0; i < sz-1; i++)
//	{
//		int min = i;
//		for (int j = i+1; j < sz; j++)
//		{
//			if (p[j]<p[min])
//			{
//				min = j;
//			}
//		}
//		swap(&p[min], &p[i]);
//	}
//}
//
//int main()
//{
//	int arr[10] = { 1,-3,5,-7,9,2,4,6,-8,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	SelectSort(arr, sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//�������
int main()
{
	int n = 0;
	scanf("%d", &n);
	int arr[31][31] = { 0 };
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j==1 || i==j)
			{
				arr[i][j] = 1;
			}
			else
			{
				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
			}
			printf("%5d", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}