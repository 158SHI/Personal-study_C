#define _CRT_SECURE_NO_WARNINGS 1

//���������ڴ��еĴ洢
//#include<stdio.h>
//int main()
//{
//	int n = 9;
//	//00000000 00000000 00000000 00001001
//	float* pFloat = (float*)&n;
//	printf("n��ֵΪ:%d\n", n);//9
//	printf("*pFloat��ֵΪ:%f\n", *pFloat);
//	//0 00000000 00000000000000000001001
//	//S     E              M
//	//(-1)^S * 0.00000000000000000001001 * 2^(-126)
//	//0.000000
//	*pFloat = 9.0;
//	//1001.0
//	//(-1)^0 * 1.001 * 2^3
//	//S 0
//	//E 130 10000010
//	//M 001
//	//0 10000010 00100000000000000000000
//	//01000001 00010000 00000000 00000000
//	//1091567616
//	printf("num��ֵΪ:%d\n", n);
//
//	printf("*pFloat��ֵΪ:%f\n", *pFloat);
//	//9.000000
//	return 0;
//}

//�ַ�ָ��
//#include<stdio.h>
//int main()
//{
//	const char* p = "abcdef";//"abcdef"��һ�������ַ���,�� a �ĵ�ַ�ŵ� p ��
//	//*p = 'w';
//	printf("%s\n", p);//�����ַ����������޷����޸ġ��δ���
//	printf("%c\n", *p);
//	printf("%s\n", p);
//	return 0;
//}

//�ַ�ָ��
//#include<stdio.h>
//int main()
//{
//	char arr1[] = "asdf";
//	char arr2[] = "asdf";
//	const char* p1 = "asdf";//�����ַ���
//	const char* p2 = "asdf";
//	//if (arr1 == arr2)
//	//{
//	//	printf("hehe");
//	//}
//	//else
//	//{
//	//	printf("haha");
//	//}
//	if (p1 == p2)
//	{
//		printf("hehe");//�����ַ��������ݲ��ɱ��޸ģ��洢ʱֻ�洢һ��
//	}                  //p1��p2��ָ��"asdf"
//	else
//	{
//		printf("haha");
//	}
//	return 0;
//}

//ָ������
#include<stdio.h>
int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 2,3,4,5,6 };
	int arr3[] = { 3,4,5,6,7 };
	int* parr[] = { arr1,arr2,arr3 };//����ָ����������������
	int i = 0;
	for ( i = 0; i < 3; i++)
	{
		int j = 0;
		for ( j = 0; j < 5; j++)
		{
			printf("%d ", *(parr[i] + j));
		}
		printf("\n");
	}//������������е�Ԫ��
	return 0;
}