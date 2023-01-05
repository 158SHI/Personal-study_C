#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdbool.h>
#include<math.h>

bool IsPerfectNum(int num)
{
    int sum = 0;
    for (int i = 1; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            sum += i;
            if (num / i != i && num / i != num)
            {
                sum += num / i;
            }
        }
    }
    return  sum == num ? true : false;
}

//int main()
//{
//    IsPerfectNum(28);
//    return 0;
//}

#include<stdlib.h>
#include<string.h>

int findRepeatNumber(int* nums, int numsSize)
{
    //哈希表
    int* cnt = (int*)malloc(sizeof(int) * numsSize);
    memset(cnt, 0, sizeof(int) * numsSize);
    int ret = 0;
    for (int i = 0; i < numsSize; i++)
    {
        cnt[nums[i]]++;
    }
    for (int i = 0; i < numsSize; i++)
    {
        if (cnt[i] > 1)
        {
            ret = i;
            break;
        }
    }
    return ret;
}

//int main()
//{
//    int arr[] = { 3, 1, 2, 3 };
//    findRepeatNumber(arr, 4);
//    return 0;
//}

int Add(int x, int y)
{
    return x + y;
}

int Sub(int x, int y)
{
    return x - y;
}

int Mul(int x, int y)
{
    return x * y;
}

int Div(int x, int y)
{
    return x / y;
}

//转移表
//int (*pf[5])(int, int) = { NULL, Add, Sub, Mul, Div };
//
//int main()
//{
//    int input = 0;
//    scanf("%d", &input);
//    if (input >= 1 && input <= 4)
//    {
//        int x = 0;
//        int y = 0;
//        scanf("%d %d", &x, &y);
//        int ret = pf[input](x, y);
//        printf("%d\n", ret);
//    }
//    return 0;
//}

int Cacu(int (*pf)(int, int))
{
    int x = 0;
    int y = 0;
    scanf("%d %d", &x, &y);
    //回调函数
    return pf(x, y);
}

//int main()
//{
//    int input = 0;
//    scanf("%d", &input);
//    switch (input)
//    {
//    case 1:
//        printf("%d\n", Cacu(Add));
//        break;
//    case 2:
//        printf("%d\n", Cacu(Sub));
//        break;
//    case 3:
//        printf("%d\n", Cacu(Mul));
//        break;
//    case 4:
//        printf("%d\n", Cacu(Div));
//        break;
//    default:
//        break;
//    }
//    return 0;
//}

//void BubbleSort01(int* arr, int sz)
//{
//    for(int i = 0; i < sz - 1; i ++)
//    {
//        for (int j = 0; j < sz - 1 - i; j++)
//        {
//            if (arr[j] > arr[j + 1])
//            {
//                swap(arr[j], arr[j + 1]);
//            }
//        }
//    }
//}

void Swap(char* e1, char* e2, size_t width)
{
    //逐字节交换
    for (size_t i = 0; i < width; i++)
    {
        char tmp = *e1;
        *e1 = *e2;
        *e2 = tmp;
        e1++;
        e2++;
    }
}

//改造冒泡排序
void BubbleSort(void* base, size_t num, size_t width, int (*cmp_fun)(const void*, const void*))
{
    for (size_t i = 0; i < num - 1; i++)
    {
        for (size_t j = 0; j < num - 1 - i; j++)
        {
            if (cmp_fun((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
            {
                Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
            }
        }
    }
}

int cmp_int(const void* e1, const void* e2)
{
    return *(int*)e1 - *(int*)e2;
}

void Print(int* arr, int sz);

void test1(void)
{
    int arr[] = { 1,3,5,7,2,4,6,8 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    BubbleSort(arr, sz, sizeof(int), cmp_int);
    Print(arr, sz);
}

struct Demo
{
    int n;
    char arr[10];
};

int cmp_str(const void* e1, const void* e2)
{
    return strcmp(((struct Demo*)e1)->arr, ((struct Demo*)e2)->arr);
}

void test2(void)
{
    struct Demo d[3] = { {2, "zeze"}, {3, "ahah"}, {1, "hehe"} };
    BubbleSort(d, 3, sizeof(d[0]), cmp_str);
}

int main()
{
    test1();
    //test2();
    return 0;
}

/*
练习使用库函数，qsort排序各种类型的数据
*/

#include<stdlib.h>

void Print(int* arr, int sz)
{
    for (int i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//排序整型
void test01(void)
{
    int arr[] = { 1, 3, 5, 7, 2, 4, 6, 8 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    qsort(arr, sz, sizeof(int), cmp_int);
    Print(arr, sz);
}

//排序结构体中的字符串
void test02(void)
{
    struct Demo d[3] = { {2, "zeze"}, {3, "ahah"}, {1, "hehe"} };
    int sz = sizeof(d) / sizeof(d[0]);
    qsort(d, sz, sizeof(d[0]), cmp_str);
    for (int i = 0; i < sz; i++)
    {
        printf("%s\n", d[i].arr);
    }
}

//int main()
//{
//    test01();
//    //test02();
//    return 0;
//}