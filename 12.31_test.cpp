#define _CRT_SECURE_NO_WARNINGS 1


/*
����Ӧ��_3��_ʩ��Ȼ
ѧ��:2228624173
*/

/*
    7.13_������
����������
�Ӽ�����������һ������m����m�������������m�����������ֽ⣬
���� m ����������С����˳�����еĳ˻���ʽ���,�������"It is a prime number"��
���磺�û�����90ʱ�������90=2x 3x 3x 5;������17ʱ�������"It is a prime number����
*/

#include<iostream>
#include<queue>

using namespace std;

class PrimeFac
{
public:
    queue<int> v;
    int pri;//������
    int pri_pv;//���������ֽ��б���

public:
    PrimeFac(void)//���캯��
    {
        pri = 0;
        pri_pv = 0;
    }

    //����
    void Input(void)
    {
        cout << "Please input a number >: ";
        cin >> pri;
        pri_pv = pri;
    }

    //��������ʱ�洢�ڶ�����
    void TmpStor(void)
    {
        for (int i = 2; i <= pri; i++)
        {
            if (pri % i == 0)
            {
                pri = pri / i;

                if (pri == 1)
                {
                    v.push(i);
                    return;
                }
                v.push(i);
                return TmpStor();
            }
        }
    }

    //�жϺ����
    void JudgeAnOut(void)
    {
        if (v.size() == 1)
        {
            cout << "It is a prime number" << endl;
        }
        else
        {
            cout << pri_pv << " = ";
            while(!v.empty())
            {
                if (v.size() == 1)
                {
                    cout << v.front() << endl;
                }
                else
                {
                    cout << v.front() << " * ";
                }
                v.pop();
            }
        }
    }
};

int main()
{
	PrimeFac pef;
    pef.Input();
    pef.TmpStor();
    pef.JudgeAnOut();
	return 0;
}

/*
����ܽ᣺
    �����뵽�ķ��������ж������Ƿ�Ϊ�������ٽ�����Ӧ�������
    ���ǵ��������������ʱ���Ѿ�ȷ�������ֲ���������Ϊ��ʡȥ����Ҫ�Ĺ�����
    ���ȶ����ֽ����������ֽ⣬������Щ������ʱ��ŵ�queue�����У������
    queue��ֻ��һ��Ԫ�أ����Ԫ��ֻ���Ǹ����ֱ�����������Ϊ���������������
    ��Ϊ���������������queue�е�Ԫ�ء�
    ����������Ȼʹ���˶���Ŀռ䣬���Ǳ����˲���Ҫ�Ĺ�������ʱ���Կռ任ʱ��
    �Ǹ����õ�ѡ��
*/