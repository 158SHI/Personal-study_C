#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<string.h>

//模拟实现strcmp
//
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);//两指针都不为空
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')//二者相等且都等于 \0 ，说明两字符串相等
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
//	strncpy(arr1, arr2, 14);//strSource长度不够时补 \0
//	printf("%s\n", arr1);	//strSource长度足够时不补 \0
//	return 0;
//}

//实现strncpy

//char* my_strncpy(char* str1, const char* str2,int count)
//{
//	assert(str1 && str2);
//	char* ret = str1;
//	while (count && (*str1++ = *str2++))//进行拷贝
//	{
//		count--;
//	}
//	while (count)//strSource长度不够时补 \0
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


//实现strncat

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
//	*Des = '\0';//补 \0
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

//strstr函数

//int main()
//{
//	const char* p1= "abcdefghj";
//	const char* p2 = "def";//子串
//	char* ret = strstr(p1, p2);
//	if (ret == NULL)
//	{
//		printf("无法找到该子串\n");
//	}
//	else
//	{
//		printf("%s", ret);
//	}
//	return 0;
//}

//实现strstr(注意)
//
//char* my_strstr(const char* p1, const char* p2)
//{
//	assert(p1 && p2);
//	char* s1 = p1;
//	char* s2 = p2;
//	char* cur = p1;
//	if (*p2 == '\0')//若要查找的子串为空，则直接返回p1
//	{
//		return p1;
//	}
//	else
//	{
//		while (*cur)
//		{	
//			s1 = cur;//回溯
//			s2 = p2;
//			while ((*s1 != '\0') && (*s2 != '\0') && (*s1==*s2))
//			{
//				s1++;
//				s2++;
//			}
//			if (*s2 == '\0')//找到了指定子串
//			{
//				return cur;
//			}
//			cur++;//进一
//		}
//		return NULL;
//	}
//}
//
//int main()
//{
//	const char* p1 = "abbbcde";
//	const char* p2 = "bbc";//要找的子串
//	char* ret = my_strstr(p1, p2);
//	if (ret == NULL)
//	{
//		printf("该子串不存在\n");
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