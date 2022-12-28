#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

//int main()
//{
//	char c;
//	int v0 = 0, v1 = 0, v2 = 0;
//		do
//		{
//			switch (c = getchar())
//			{
//			case'a':case'A':
//			case'e':case'E':
//			case'i':case'I':
//			case'o':case'O':
//			case'u':case'U':v1 += 1;
//			default:v0 += 1; v2 += 1;
//			}
//
//		} while (c != '\n');
//		printf("v0=%d,v1=%d,v2=%d\n", v0, v1, v2);
//		return 0;
//}

int* findErrorNums(int* nums, int numsSize, int* returnSize)
{
    *returnSize = 2;
    int* cnt = (int*)calloc(numsSize, sizeof(int));
    int* retNums = (int*)malloc(sizeof(int) * 2);

    for (int i = 0; i < numsSize; i++)
    {
        cnt[nums[i] - 1]++;
    }

    for (int i = 0; i < numsSize; i++)
    {
        if (cnt[i] == 2)
        {
            retNums[0] = i + 1;
        }

        else if (cnt[i] == 0)
        {
            retNums[1] = i + 1;
        }
    }

    return retNums;
}

//int main()
//{
//    int arr[] = { 1,2,3,4,5,6,7,2 };
//    //int arr[] = { 2,3,2 };
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    int retsz = 0;
//    findErrorNums(arr, sz, &retsz);
//    return 0;
//}


#include <string.h>
#include <ctype.h>

//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    //char ch = getchar();
//    char input[101] = { 0 };
//    for (int i = 0; i < n; i++)
//    {
//        int upper = 0;
//        int low = 0;
//        int digit = 0;
//        int others = 0;
//        scanf("%s", input);
//        //长度小于8
//        if (strlen(input) < 8)
//        {
//            printf("NO\n");
//            continue;
//        }
//        //开头是数字
//        if (isdigit(input[0]) != 0)
//        {
//            printf("NO\n");
//            continue;
//        }
//
//        for (int j = 0; j < strlen(input); j++)
//        {
//            //含大写字母
//            if (isupper(input[j]) != 0)
//            {
//                upper++;
//            }
//            //含小写字母
//            else if (islower(input[j]) != 0)
//            {
//                low++;
//            }
//            //含数字
//            else if (isdigit(input[j]) != 0)
//            {
//                digit++;
//            }
//            //含其他类型
//            else
//            {
//                others++;
//            }
//        }
//        if (others != 0)
//        {
//            printf("NO\n");
//            continue;
//        }
//
//        if ((upper > 0) + (low > 0) + (digit > 0) < 2)
//        {
//            printf("NO\n");
//            continue;
//        }
//
//        printf("YES\n");
//    }
//    return 0;
//}

#include<stdbool.h>

//int main()
//{
//    printf("%d", 1 < 2);
//    return 0;
//}

void CreatNewImage(int** image, int sr, int sc, int row, int col, int newColor)
{
    int color = image[sr][sc];
    image[sr][sc] = newColor;
    if (sr + 1 < row && image[sr + 1][sc] == color)
    {
        CreatNewImage(image, sr + 1, sc, row, col, newColor);
    }
    if (sr - 1 >= 0 && image[sr - 1][sc] == color)
    {
        CreatNewImage(image, sr - 1, sc, row, col, newColor);
    }
    if (sc + 1 < col && image[sr][sc + 1] == color)
    {
        CreatNewImage(image, sr, sc + 1, row, col, newColor);
    }
    if (sc - 1 >= 0 && image[sr][sc - 1] == color)
    {
        CreatNewImage(image, sr, sc - 1, row, col, newColor);
    }
    return;
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes)
{
    int row = imageSize;
    int col = imageColSize[0];

    *returnSize = row;
    for (int i = 0; i < row; i++)
    {
        (*returnColumnSizes)[i] = col;
    }

    CreatNewImage(image, sr, sc, row, col, color);

    return image;
}

int main()
{
    int arr[3][3] = { 1,1,1,1,1,0,1,0,1 };
    int imageColSize[] = { 3,3,3 };
    int returnSize = 0;
    int retArr[3][3];
    floodFill(arr, 3, imageColSize, 1, 1, 2, &returnSize, retArr);
    return 0;
}