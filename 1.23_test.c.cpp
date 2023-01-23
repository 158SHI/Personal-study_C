int* printNumbers(int n, int* returnSize)
{
    int aim = 0;
    while(n)
    {
        aim = aim * 10 + 9;
        n--;
    }
    *returnSize = 0;
    int* retNums = (int*)malloc(sizeof(int) * aim);
    for(int i = 1; i <= aim; i++)
    {
        retNums[(*returnSize)++] = i;
    }
    return retNums;
}
