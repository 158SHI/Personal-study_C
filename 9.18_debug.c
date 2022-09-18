#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<string.h>

//const的用法
//#include<stdio.h>
//int main()
//{
//	int b = 0;
//
//	const int a = 10;//const 修饰 a，仍可以通过指针修改 a 的值
//
//	const int* p = &a;//const 放在 *前面，修饰*p(a)，无法通过指针改变 a的值
//
//	int* const p = &a;//const 放在 * 后面，修饰 p ，无法修改指针变量 p 
//
//	*p = 20;//
//
//	p = &b;//
//
//	printf("%d\n", a);
//	return 0;
//}

//模拟实现strcpy的功能
//void my_strcpy(char* dest, char* src)
//{
//	while(*src != '\0')
//	{
//		*dest = *src;
//		src++;
//		dest++;
//	}
//	*dest = *src;//将\0赋给dest字符串
//}
//

//优化后
//char* my_strcpy(char* dest,const char* src)// 加const : 避免src与dest倒置（src被修改）
//{
//	char* ret = dest;//strcpy的返回值为dest字符串，该步将初始 dest字符串保留
//	
//	//检验过程
//	assert(src != NULL);
//	assert(dest != NULL);//利用断言发现错误，保证指针的有效性
//
//	//拷贝过程，包含'\0'
//	while (*dest++ = *src++)//当*src为 '\0'时，其值为0，停止循环
//	{
//		;
//	}
//
//	//返回
//	return ret;//返回初始 dest 字符串
//}
//
//int main()
//{
//	char arr1[] = "########";
//	char arr2[] = "hello";
//	//strcpy(arr1, arr2);
//	printf("%s\n", my_strcpy(arr1, arr2));//链式访问
//	return 0;
//}

//模拟实现strlen函数 Pro
#include<stdio.h>

int my_strlen(const char* str)//用const修饰，避免字符串被改变
{
	assert(str != NULL);//保证指针的有效性
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

int main()
{
	char arr[] = "hello";
	int ret = my_strlen(arr);
	printf("ret=%d\n", ret);
	return 0;
}