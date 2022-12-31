#define _CRT_SECURE_NO_WARNINGS 1


/*
智能应用_3班_施浩然
学号:2228624173
*/

/*
    7.13_任务六
任务描述：
从键盘任意输入一个整数m，若m不是素数，则对m进行质因数分解，
并将 m 以质因数从小到大顺序排列的乘积形式输出,否则输出"It is a prime number"。
例如：用户输入90时程序输出90=2x 3x 3x 5;用输入17时程序输出"It is a prime number”。
*/

#include<iostream>
#include<queue>

using namespace std;

class PrimeFac
{
public:
    queue<int> v;
    int pri;//输入用
    int pri_pv;//对输入数字进行备份

public:
    PrimeFac(void)//构造函数
    {
        pri = 0;
        pri_pv = 0;
    }

    //输入
    void Input(void)
    {
        cout << "Please input a number >: ";
        cin >> pri;
        pri_pv = pri;
    }

    //将数据暂时存储在队列中
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

    //判断和输出
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
体会总结：
    最先想到的方法是先判断数字是否为素数，再进行相应的输出。
    考虑到进行质因数输出时，已经确定该数字不是素数，为了省去不必要的工作，
    我先对数字进行质因数分解，并将这些因数临时存放到queue容器中，若最后
    queue中只有一个元素，则该元素只能是该数字本身，即该数字为素数；否则该数字
    不为素数，则依次输出queue中的元素。
    这种做法虽然使用了额外的空间，但是避免了不必要的工作。有时候以空间换时间
    是个更好的选择。
*/