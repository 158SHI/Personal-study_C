#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

/*
����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ�����ʵ�֣���
*/

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	int dsum = 0;
//	int drinks = n;
//	int bottle = 0;
//	int bsum = 0;
//	while (drinks >= 1)
//	{
//		dsum += drinks;
//		bottle = drinks % 2;
//		bsum += bottle;
//		drinks /= 2;
//	}
//	dsum += bsum / 2;
//	printf("%d\n", dsum);
//	return 0;
//}


//int main()
//{
//    const char user[] = "admin";
//    const char pass[] = "admin";
//
//    char inuser[20] = { 0 };
//    char inpass[20] = { 0 };
//    scanf("%s %s", inuser, inpass);
//
//    if (strcmp(pass, inpass) == 0 && strcmp(user, inuser) == 0)
//    {
//        printf("Login Success!\n");
//    }
//    else
//    {
//        printf("Login Fail!\n");
//    }
//    return 0;
//}
#include<string.h>

//int main()
//{
//	char arr[6] = { 0 };
//	scanf("%s", arr);
//	printf("%d\n", strlen(arr));
//	return 0;
//}

/*
�����У�
��һ������һ������(0��N��50)��
�ڶ�������N���������е������������ÿո�ָ���N��������
������������Ҫ���в����һ��������
���������
���Ϊһ�У�N+1���������е�������
*/

//void Insert(int* p, int sz, int input)
//{
//	int key = sz - 1;
//	while(p[key]>input && key>=0)
//	{
//		p[key+1] = p[key];
//		key--;
//	}
//	p[key + 1] = input;
//}
//
//int main()
//{
//	int arr[51] = { 0 };
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	for ( i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	int input = 0;
//	scanf("%d", &input);
//	Insert(arr, n, input);
//
//	for ( i = 0; i < n+1; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

/*
���󽻻�
*/

//int main()
//{
//	int arr[11][11] = { 0 };
//	int n = 0, m = 0;
//	scanf("%d %d", &n, &m);//�С�����
//
//	int i = 0;
//	int j = 0;
//	for ( i = 1; i <= n; i++)//�������
//	{
//		for ( j = 1; j <= m; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//
//	int k = 0;
//	scanf("%d", &k);//k>=1 && k<=5
//	
//	char con = 0;
//	int op1 = 0;
//	int op2 = 0;
//
//	for ( i = 0; i < k; i++)
//	{
//		scanf(" %c %d %d", &con, &op1, &op2);//ע�⻺����
//
//		int tmp = 0;
//		if (con == 'r')
//		{
//			//�н���
//			for ( j = 1; j <= m; j++)
//			{
//				tmp = arr[op1][j];
//				arr[op1][j] = arr[op2][j];
//				arr[op2][j] = tmp;
//			}
//		}
//		else if (con == 'c')
//		{
//			//�н���
//			for (j = 1; j <= m; j++)
//			{
//				tmp = arr[j][op1];
//				arr[j][op1] = arr[j][op2];
//				arr[j][op2] = tmp;
//			}
//		}
//		else
//		{
//			continue;
//		}
//	}
//
//	for ( i = 1; i <= n; i++)
//	{
//		for ( j = 1; j <= m; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

/*
����
������ǣ��������Ƕ���ʽ(a+b)��n�η�չ��������ϵ���ųɵ������Ρ�
�����ʰ�����ÿ�еĶ˵���Ϊ1�� һ����ҲΪ1��ÿ�������������Ϸ����Ϸ�������֮�͡�

����������
��һ�а���һ��������n�� (1��n��30)
���������
����n�У�Ϊ������ǵ�ǰn�У�ÿ����������Ϊ5��
*/

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0, j = 0;
//	int arr[31][31] = { 0 };
//
//	for ( i = 0; i < n; i++)
//	{
//		for ( j = 0; j <= i; j++)
//		{
//			if (j==0 || i==j)//���˺�ĩβΪ1
//			{
//				arr[i][j] = 1;
//			}
//			else//�м䲿��
//			{
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//			}
//			printf("%5d", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}


//#define ROW 3
//#define COL 3
//
//int main()
//{
//    char arr[ROW][COL] = { 0 };
//    int i = 0, j = 0;
//    for (i = 0; i < ROW; i++)//����
//    {
//        for (j = 0; j < COL; j++)
//        {
//            scanf(" %c", &arr[i][j]);
//        }
//    }
//
//    //�ж�
//    char win = 0;
//    for (i = 0; i < ROW; i++)//�ж���
//    {
//        if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2])
//        {
//            win = arr[i][0];
//        }
//    }
//    for (i = 0; i < COL; i++)//�ж���
//    {
//        if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i])
//        {
//            win = arr[0][i];
//        }
//    }
//    //�ж϶Խ���
//    if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2])
//    {
//        win = arr[0][0];
//    }
//    if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])
//    {
//        win = arr[0][2];
//    }
//
//    if (win == 'K')
//    {
//        printf("KiKi wins!\n");
//    }
//    else if (win == 'B')
//    {
//        printf("BoBo wins!\n");
//    }
//    else
//    {
//        printf("No winner!\n");
//    }
//    return 0;
//}

int GCD(int m, int n)
{

    while (m%n != 0)
    {
        int c = m % n;
        m = n;
        n = c;
    }
    return n;
}

int LCM(int m, int n)
{
    if (m < n)
    {
        int tmp = m;
        m = n;
        n = tmp;
    }
    int i = 0;
    for (i = m; ; i++)
    {
        if (i % m == 0 && i % n == 0)
        {
            break;
        }
    }
    return i;
}

int main()
{
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);

    int gcd = GCD(m, n);
    int lcm = LCM(m, n);

    int add = gcd + lcm;
    printf("%d\n", add);
    return 0;
}