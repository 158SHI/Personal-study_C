#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	float b = 10.0;
//	return 0;
//}

//写一个小程序判断一个机器存储模式是大端存储还是小端存储
//#include<stdio.h>
//
//int Check_sys()
//{
//	int a = 1;
//	char* p = (char*)&a;
//	return *p;
//	//返回1，小端
//	//返回0，大端
//}
//
//int main()
//{
//	int a = 1;
//	int ret = Check_sys();
//	if (ret == 1)
//	{
//		printf("小端存储");
//	}
//	else
//	{
//		printf("大端存储");
//	}
//	return 0;
//}

//输出的是什么？
//#include<stdio.h>
//int main()
//{
//	char a = -1;
//	//11111111111111111111111111111111
//	//11111111
//	// 整型提升
//	//11111111111111111111111111111111
//	//-1
//	signed char b = -1;
//	//11111111
//	//整型提升，同 char a
//	unsigned char c = -1;
//	//11111111
//	//整型提升
//	//00000000000000000000000011111111
//	//255
//	printf("a=%d b=%d c=%d\n", a, b, c);
//	return 0;
//}

//输出的是什么?
#include<stdio.h>
int main()
{
	char a = -128;
	//10000000000000000000000010000000
	//11111111111111111111111101111111
	//11111111111111111111111110000000
	//10000000
	//整型提升
	//11111111111111111111111110000000
	printf("%u\n", a);
	return 0;
}