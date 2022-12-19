#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<Windows.h>
#include<string.h>

//进度条
void ProcBar()
{
	//存储进度条
	char bar[101];
	//存储旋转动画
	const char* p = "|/\\-";
	//初始化进度条
	memset(bar, 0, sizeof(bar));
	int i = 0;
	printf("Loading:\n");
	while (i <= 100)
	{
		printf("[%-100s][%-3d%%][%c]\r", bar, i, p[i % 4]);
		fflush(stdout);//刷新stdout以显示
		Sleep(20);
		bar[i] = '#';//进度条增长
		i++;
	}
	printf("\n");
}



int _bin_search(int* numbers, int numbersSize, int key, int i)
{
    int left = i + 1;
    int right = numbersSize - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (numbers[mid] > key)
        {
            right = mid - 1;
        }
        else if (numbers[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
    int* retnum = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    //从左至右遍历数组，同时二分查找对应的数字
    int i = 0;
    //注意下标从 1 开始
    for (int i = 0; i < numbersSize; i++)
    {
        int key = target - numbers[i];
        int ret = _bin_search(numbers, numbersSize, key, i);

        //无法找到所需元素
        if (ret == -1)
        {
            continue;
        }
        else
        {
            retnum[0] = i + 1;
            retnum[1] = ret + 1;
            break;
        }
    }
    return retnum;
}

int binary_search(int* p, int sz, int aim)
{
    int left = 0;
    int right = sz - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (p[mid] > aim)
        {
            right = mid - 1;
        }
        else if (p[mid] < aim)
        {
            left = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}


int main()
{
    //ProcBar();
    //int numbers[] = {2, 7, 11, 15};
    int numbers[] = { 2, 3, 4 };
    int sz = sizeof(numbers) / sizeof(numbers[0]);
    int target = 6;
    int retsize = 0;
    twoSum(numbers, sz, target, &retsize);
	return 0;
}

//int main()
//{
//    int arr[] = { 2,3,4 };
//    int ret = binary_search(arr, 3, 4);
//    printf("%d\n", ret);
//    return 0;
//}