#define _CRT_SECURE_NO_WARNINGS 1

//���������ڴ��еĴ洢
//#include<stdio.h>
//int main()
//{
//	float a = 5.5;
//	//101.1
//	//1.011*2^2
//	//(-1)^0 * 1.011 * 2^2
//	//S = 0
//	//M = 1.011
//	//E = 2
//	// 0 011 129
//	//0 10000001 01100000000000000000000
//	//0100 0000 1011 0000 0000 0000 0000 0000
//	//4 0 b 0 0 0 0 0
//	//0x40 b0 00 00
//	return 0;
//}

#include<stdio.h>
int main()
{
	int n = 9;

	float* pFloat = (float *)&n;
	printf("n��ֵΪ:%d\n", n);//9
	//00000000 00000000 00000000 00001001 ����
	//0 00000000 00000000000000000001001
	//S    E              M
	//(-1)^0 * 0.00000000000000000001001 * 2^(-126)
	//0.000000
	printf("*pFloat��ֵΪ:%f\n", *pFloat);

	*pFloat = 9.0;
	//1001.0
	//(-1)^0 * 1.001 * 2^3
	//0 10000010 00100000000000000000000
	//01000001 00010000 00000000 00000000
	//1091567616
	printf("num��ֵΪ:%d\n", n);

	printf("*pFloat��ֵΪ:%f\n", *pFloat);
	//9.000000
	return 0;
}