#define _CRT_SECURE_NO_WARNINGS 1



//���׼�����
/*#include <stdio.h>

int main()
{
    //�����ַ���
    //�ж�������ĺϷ���
    //�������㣬�� �����жϲ�����2�ĺϷ���
    double a, b;
    char m;
    while (scanf("%lf%c%lf", &a, &m, &b) != EOF)
    {
        if (m == '+' || m == '-' || m == '*' || m == '/')//������Ϸ�
        {
            switch (m)
            {
            case '+':
            {
                printf("%.4f+%.4f=%.4f\n", a, b, a + b);
                break;
            }
            case '-':
            {
                printf("%.4f-%.4f=%.4f\n", a, b, a - b);
                break;
            }
            case '*':
            {
                printf("%.4f*%.4f=%.4f\n", a, b, a * b);
                break;
            }
            case '/':
            {
                if (b == 0.0)
                {
                    printf("Wrong!Division by zero!\n");
                }
                else
                {
                    printf("%.4f/%.4f=%.4f\n", a, b, a / b);
                }
                break;
            }
            }
        }
        else//��������Ϸ�
        {
            printf("Invalid operation!\n");
        }
    }
    return 0;
}*/


/*
KiKiѧϰ��ѭ����BoBo��ʦ��������һϵ�д�ӡͼ������ϰ���������Ǵ�ӡ�á�*����ɵĴ��ո�ֱ��������ͼ����

����������
�������룬һ��������2~20������ʾֱ��������ֱ�Ǳߵĳ��ȣ�����*����������Ҳ��ʾ���������

���������
���ÿ�����룬����á�*����ɵĶ�Ӧ���ȵ�ֱ�������Σ�ÿ����*��������һ���ո�

ʾ��1
���룺
5

�����
        *
      * *
    * * *
  * * * *
* * * * *
*/

//#include <stdio.h>
//int main()
//{
//    int n;
//    while (scanf("%d", &n) != EOF)
//    {
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < n - i -1; j++)//��ӡ�ո�
//            {
//                printf("  ");
//            }
//            for (int k = 0; k <= i; k++)//��ӡ*
//            {
//                printf("* ");
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}

/*
������

����
KiKiѧϰ��ѭ����BoBo��ʦ��������һϵ�д�ӡͼ������ϰ���������Ǵ�ӡ�á�*����ɵĽ�����ͼ����
����������
�������룬һ��������2~20������ʾ�������ߵĳ��ȣ�����*������������Ҳ��ʾ���������
���������
���ÿ�����룬����á�*����ɵĽ�������ÿ����*��������һ���ո�


���룺
4

�����
   *
  * *
 * * *
* * * *
*/

//#include <stdio.h>
//int main()
//{
//    int n;
//    while (scanf("%d", &n) != EOF)
//    {
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < n - i - 1; j++)
//            {
//                printf(" ");
//            }
//            for (int k = 0; k <= i; k++)
//            {
//                printf("* ");
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}


/*

* * * * *
  * * * *
    * * *
      * *
        *
*/
//#include <stdio.h>
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    for (int i = n; i > 0; i--)
//    {
//        //��ӡ�ո�
//        for (int j = 0; j < n - i; j++)
//        {
//            printf("  ");
//        }
//        //��ӡ*
//        for (int k = 0; k < i; k++)
//        {
//            printf("* ");
//        }
//        printf("\n");
//    }
//    return 0;
//}


/*
* * * * *
 * * * *
  * * *
   * *
    *
*/
//#include <stdio.h>
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    for (int i = n; i > 0; i--)
//    {
//        //��ӡ�ո�
//        for (int j = 0; j < n - i; j++)
//        {
//            printf(" ");
//        }
//        //��ӡ*
//        for (int k = 0; k < i; k++)
//        {
//            printf("* ");
//        }
//        printf("\n");
//    }
//    return 0;
//}


/*
     *
    * *
   * * *
  * * * *
 * * * * *
* * * * * *
 * * * * *
  * * * *
   * * *
    * *
     *
*/

//#include <stdio.h>
//int main()
//{
//    //��ӡn*n�Ͻ�����
//    //��ӡһ��n+1��*
//    //��ӡn*n�½�����
//    int n;
//    scanf("%d", &n);
//
//    for (int i = 0; i < n; i++)//��ӡ�Ͻ�����
//    {
//        for (int j = 0; j < n - i; j++)
//        {
//            printf(" ");
//        }
//        for (int k = 0; k <= i; k++)
//        {
//            printf("* ");
//        }
//        printf("\n");
//    }
//
//    for (int m = 0; m < n+1; m++)//��ӡһ��
//    {
//        printf("* ");
//    }
//
//    printf("\n");
//
//    for (int i = n; i > 0; i--)//��ӡ�½�����
//    {
//        //��ӡ�ո�
//        for (int j = 0; j <= n - i; j++)
//        {
//            printf(" ");
//        }
//        //��ӡ*
//        for (int k = 0; k < i; k++)
//        {
//            printf("* ");
//        }
//        printf("\n");
//    }
//    return 0;
//}


/*

* * * * * *
* * * * *
* * * *
* * *
* *
*
* *
* * *
* * * *
* * * * *
* * * * * *

*/
#include <stdio.h>
int main()
{
    //��ӡ����
    //��ӡ��������
    int n;
    scanf("%d", &n);
    //��ӡ����(n+1)��
    for (int i = n; i >= 0; i--)
    {
        int j;
        for ( j = i; j >= 0; j--)
        {
            printf("* ");
        }
        if (j<i)
        {
            printf("\n");
        }
    }
    //��ӡ��������
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}