#define _CRT_SECURE_NO_WARNINGS 1

////printf�����ķ���ֵ
//#include<stdio.h>
//int main()
//{
//	int ret = printf("Hello world!");//��ֵ��ͬʱ��ִ��printf����
//	printf("\n%d", ret);//printf�ķ���ֵ������ӡ���ַ��ĸ���
//	/*
//	1.On success, the total number of characters written is returned.
//	2.If a writing error occurs, the error indicator (ferror) is set and a negative number is returned.
//	3.If a multibyte character encoding error occurs while writing wide characters, errno is set to EILSEQ and a negative number is returned.
//	*/
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	char str[20];
//	scanf("%s", str);
//	printf("%s", str);
//	return 0;
//
//}

//#include <stdio.h>
//
//int main()
//{
//    float c, math, Eng;
//    char str[20];
//    scanf("%s %f %f %f", str, &c, &math, &Eng);
//    printf("The each subject score of No. %s is %.2f, %.2f, %.2f.\n", str, c, math, Eng);
//    return 0;
//}

//�ַ�ʥ����
//#include <stdio.h>
//
//int main()
//{
//    char c;
//    scanf("%c", &c);
//    printf("    %c\n", c);
//    printf("   %c %c\n", c, c);
//    printf("  %c %c %c\n", c, c, c);
//    printf(" %c %c %c %c\n", c, c, c, c);
//    printf("%c %c %c %c %c\n", c, c, c, c, c);
//    return 0;
//}

//ASCII��
//#include <stdio.h>
//
//int main()
//{
//    printf("%c%c%c%c%c%c%c%c%c%c%c%c", 73, 32, 99, 97, 110, 32, 100, 111, 32, 105, 116, 33);
//    return 0;
//}

/*
����
����һ���˵ĳ������ڣ����������գ������������е��ꡢ�¡��շֱ������

���ݷ�Χ��������� 1990 \le y \le 2015 \1990��y��2015 ���·����� 1 \le m \le 12 \1��m��12  �������� 1 \le d \le 30 \1��d��30
����������
����ֻ��һ�У��������ڣ����������գ�������֮�������û�зָ�����
���������
���У���һ��Ϊ������ݣ��ڶ���Ϊ�����·ݣ�������Ϊ�������ڡ����ʱ����·ݻ�����Ϊ1λ������Ҫ��1λ��ǰ�油0��
ʾ��1
���룺
20130225
����
�����
year=2013
month=02
date=25
*/

//#include <stdio.h>
//int main()
//{
//    int y, m, d;
//    scanf("%4d%2d%2d", &y, &m, &d);//��ȡ
//    printf("year=%d\nmonth=%02d\ndate=%02d\n", y, m, d);//
//    return 0;
//}
//
///*
//ͨ��scanf������ %m ��ʽ���ƿ���ָ�������������������������������˿�Ƚ�ȡ�������ݣ�
//ͨ��printf������ %0 ��ʽ���Ʒ��������ֵʱָ�����治ʹ�õĿ�λ���Զ���0��
//*/

#include <stdio.h>

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
        {
            printf("%d\n", 1);
        }
        else
        {
            printf("%d\n", 2 << n);
        }
    }
    return 0;
}