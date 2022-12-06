#define _CRT_SECURE_NO_WARNINGS 1


int** generate(int numRows, int* returnSize, int** returnColumnSizes)
{
    //Ԥ����numRows�пռ�
    int** ret = malloc(sizeof(int*) * numRows);

    //��numRows������Ԫ��
    *returnSize = numRows;

    //��¼ÿ�е�Ԫ�ظ���������
    *returnColumnSizes = malloc(sizeof(int) * numRows);

    for (int i = 0; i < numRows; ++i)
    {
        //Ϊÿ�п��ٿռ�
        ret[i] = malloc(sizeof(int) * (i + 1));

        //��¼ÿ�е�Ԫ�ظ�����ÿ��������Ĵ�С��
        (*returnColumnSizes)[i] = i + 1;

        ret[i][0] = ret[i][i] = 1;
        for (int j = 1; j < i; ++j)
        {
            ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
        }
    }
    return ret;
}