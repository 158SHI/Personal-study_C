#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<string.h>

//ģ��ʵ��strcmp
//
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);//��ָ�붼��Ϊ��
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')//��������Ҷ����� \0 ��˵�����ַ������
//		{
//			return 0;
//		}
//		str1++;
//		str2++;
//	}
//	//if (*str1 > *str2)
//	//{
//	//	return 1;
//	//}
//	//else
//	//{
//	//	return -1;
//	//}
//	return (*str1) - (*str2);
//}
//
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abqwe";
//	int ret = my_strcmp(arr1, arr2);
//	printf("ret=%d\n", ret);
//	return 0;
//}

//strncpy
//int main()
//{
//	char arr1[] = "abcdefg123456789";
//	char arr2[] = "hello world!";
//	strncpy(arr1, arr2, 14);//strSource���Ȳ���ʱ�� \0
//	printf("%s\n", arr1);	//strSource�����㹻ʱ���� \0
//	return 0;
//}

//ʵ��strncpy

//char* my_strncpy(char* str1, const char* str2,int count)
//{
//	assert(str1 && str2);
//	char* ret = str1;
//	while (count && (*str1++ = *str2++))//���п���
//	{
//		count--;
//	}
//	while (count)//strSource���Ȳ���ʱ�� \0
//	{
//		*str1++ = '\0';
//		count--;
//	}
//	return ret;
//}
//
//int main()
//{
//	char arr1[] = "abcdefg123456789";
//	char arr2[] = "hello world!";
//	my_strncpy(arr1,arr2,12);
//	//printf("%s\n", strncpy(arr1, arr2, 12));
//	printf("%s\n", arr1);
//	return 0;
//}


//ʵ��strncat

//char* my_strncat(char* Des, const char* Sour,int count)
//{
//	assert(Des && Sour);
//	char* ret = Des;
//	while (*Des++)
//	{
//		;
//	}
//	Des--;
//	while (count && ( * Des++ = *Sour++))
//	{
//		count--;
//	}
//	*Des = '\0';//�� \0
//	return ret;
//}
//
//int main()
//{
//	char arr1[30] = "abcedf";
//	char arr2[] = "hello";
//	my_strncat(arr1,arr2,10);
//	printf("%s", arr1);
//	return 0;
//}

//strstr����

//int main()
//{
//	const char* p1= "abcdefghj";
//	const char* p2 = "def";//�Ӵ�
//	char* ret = strstr(p1, p2);
//	if (ret == NULL)
//	{
//		printf("�޷��ҵ����Ӵ�\n");
//	}
//	else
//	{
//		printf("%s", ret);
//	}
//	return 0;
//}

//ʵ��strstr(ע��)
//
//char* my_strstr(const char* p1, const char* p2)
//{
//	assert(p1 && p2);
//	char* s1 = p1;
//	char* s2 = p2;
//	char* cur = p1;
//	if (*p2 == '\0')//��Ҫ���ҵ��Ӵ�Ϊ�գ���ֱ�ӷ���p1
//	{
//		return p1;
//	}
//	else
//	{
//		while (*cur)
//		{	
//			s1 = cur;//����
//			s2 = p2;
//			while ((*s1 != '\0') && (*s2 != '\0') && (*s1==*s2))
//			{
//				s1++;
//				s2++;
//			}
//			if (*s2 == '\0')//�ҵ���ָ���Ӵ�
//			{
//				return cur;
//			}
//			cur++;//��һ
//		}
//		return NULL;
//	}
//}
//
//int main()
//{
//	const char* p1 = "abbbcde";
//	const char* p2 = "bbc";//Ҫ�ҵ��Ӵ�
//	char* ret = my_strstr(p1, p2);
//	if (ret == NULL)
//	{
//		printf("���Ӵ�������\n");
//	}
//	else
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}

//strtok
int main()
{
	char arr1[] = "1580405516@qq.com";
	char* p = "@.";
	char buf[1024] = { 0 };
	strcpy(buf, arr1);
	char* ret = NULL;
	for (ret=strtok(buf,p);ret != NULL;ret=strtok(NULL,p))
	{
		printf("%s\n", ret);
	}
	return 0;
}