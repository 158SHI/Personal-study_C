#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<string.h>

//const���÷�
//#include<stdio.h>
//int main()
//{
//	int b = 0;
//
//	const int a = 10;//const ���� a���Կ���ͨ��ָ���޸� a ��ֵ
//
//	const int* p = &a;//const ���� *ǰ�棬����*p(a)���޷�ͨ��ָ��ı� a��ֵ
//
//	int* const p = &a;//const ���� * ���棬���� p ���޷��޸�ָ����� p 
//
//	*p = 20;//
//
//	p = &b;//
//
//	printf("%d\n", a);
//	return 0;
//}

//ģ��ʵ��strcpy�Ĺ���
//void my_strcpy(char* dest, char* src)
//{
//	while(*src != '\0')
//	{
//		*dest = *src;
//		src++;
//		dest++;
//	}
//	*dest = *src;//��\0����dest�ַ���
//}
//

//�Ż���
//char* my_strcpy(char* dest,const char* src)// ��const : ����src��dest���ã�src���޸ģ�
//{
//	char* ret = dest;//strcpy�ķ���ֵΪdest�ַ������ò�����ʼ dest�ַ�������
//	
//	//�������
//	assert(src != NULL);
//	assert(dest != NULL);//���ö��Է��ִ��󣬱�ָ֤�����Ч��
//
//	//�������̣�����'\0'
//	while (*dest++ = *src++)//��*srcΪ '\0'ʱ����ֵΪ0��ֹͣѭ��
//	{
//		;
//	}
//
//	//����
//	return ret;//���س�ʼ dest �ַ���
//}
//
//int main()
//{
//	char arr1[] = "########";
//	char arr2[] = "hello";
//	//strcpy(arr1, arr2);
//	printf("%s\n", my_strcpy(arr1, arr2));//��ʽ����
//	return 0;
//}

//ģ��ʵ��strlen���� Pro
#include<stdio.h>

int my_strlen(const char* str)//��const���Σ������ַ������ı�
{
	assert(str != NULL);//��ָ֤�����Ч��
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