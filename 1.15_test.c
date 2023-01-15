#define _CRT_SECURE_NO_WARNINGS 1

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

/*
输入: [3,30,34,5,9]
输出: "3033459"
*/

//int cmp_str(const void* e1, const void* e2)
//{
//	char* s1 = *(char**)e1;
//	char* s2 = *(char**)e2;
//	char tmp1[100] = { 0 };
//	char tmp2[100] = { 0 };
//	//char tmp3[100] = { 0 };
//
//	strcpy(tmp1, s1);
//	strcpy(tmp2, s2);
//	//strcpy(tmp3, tmp1);
//
//	char* buf1 = strcat(tmp1, tmp2);
//	char* buf2 = strcat(tmp2, s1);
//	return strcmp(buf1, buf2);
//}
//
////int main()
////{
////	char arr1[10] = "3";
////	char arr2[10] = "30";
////	char arr3[10] = "34";
////	char arr4[10] = "5";
////	char arr5[10] = "9";
////	char* pstr[5] = { arr1, arr2, arr3, arr4, arr5 };
////	qsort(pstr, 5, sizeof(pstr[0]), cmp_str);
////	return 0;
////}
//
//int main()
//{
//	int nums[] = { 3, 30, 34, 5, 9 };
//	char** strArr = (char**)malloc(sizeof(char*) * 5);
//	for (int i = 0; i < 5; i++)
//	{
//		sprintf(strArr, "%d", nums[i]);
//	}
//	return 0;
//}

int cmp_str(const void* e1, const void* e2)
{
    char tmp1[100] = { 0 };
    char tmp2[200] = { 0 };
    sprintf(tmp1, "%d%d", *(int*)e1, *(int*)e2);
    sprintf(tmp2, "%d%d", *(int*)e2, *(int*)e1);
    return strcmp(tmp1, tmp2);
}

char* minNumber(int* nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), cmp_str);
    char* retArr = (char*)calloc(numsSize * 100, sizeof(char));
    char tmp[100] = { 0 };
    for (int i = 0; i < numsSize; i++)
    {
        sprintf(tmp, "%d", nums[i]);
        strcat(retArr, tmp);
    }
    return retArr;
}

/*
输入: [3,30,34,5,9]
输出: "3033459"
*/

//int main()
//{
//    int nums[] = { 3, 30, 34, 5, 9 };
//    minNumber(nums, 5);
//    return 0;
//}

void test1(void)
{
    int nums[] = { 3, 30, 34, 5, 9 };
    char** strArr = (char**)malloc(sizeof(char*) * 5);
    for(int i = 0; i < 5; i++)
    {
        strArr[i] = (char*)malloc(sizeof(char) * 100);
        sprintf(strArr[i], "%d", nums[i]);
    }
    char retArr[200] = { 0 };
    for (int i = 0; i < 5; i++)
    {
        strcat(retArr, strArr[i]);
    }
    printf(retArr);
}

int main()
{
    test1();
    return 0;
}