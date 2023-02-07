#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
#include<stdlib.h>

//int main()
//{
//	int n = 9;
//	//00000000 00000000 00000000 00001001 - ����
//	float* pFloat = (float*)&n;
//	printf("n��ֵΪ��%d\n", n);// 9
//	printf("*pFloat��ֵΪ��%f\n", *pFloat);// 0.000000
//	//0 00000000 00000000000000000001001 - *pFloat
//	*pFloat = 9.0;
//	printf("num��ֵΪ��%d\n", n);
//	//1001.0
//	//(-1) ^ 0 * 1.001 * 2 ^ 3
//	//0 10000010 00100000000000000000000
//	//01000001 00010000 00000000 00000000
//	//1,091,567,616
//	printf("*pFloat��ֵΪ��%f\n", *pFloat);// 9.000000
//	return 0;
//}

//int main()
//{
//	//printf("%x\n", -1);
//	int n = 0x3938;
//	printf("%x\n", n);
//	return 0;
//}

//int main()
//{
//    union
//    {
//        short k;
//        char i[2];
//    }*s, a;
//    s = &a;
//    s->i[0] = 0x39;
//    s->i[1] = 0x38;
//    printf("%x\n", -2);
//    return 0;
//}

int my_atoi(const char* string)
{
	assert(string);//����ָ��Ϊ��
	bool flag = false;//��¼����
	long long retNum = 0;//��ΪҪ�ж�int�ı߽磬����retNum����Ϊlong long����
	int pos = 0;
	//����ǰ����ַ�
	while (!isdigit(string[pos]) && string[pos] != '-')
	{
		pos++;
	}
	//�ж�����
	if (string[pos] == '-') {
		flag = true;
		pos++;
	}
	//����'\0'ʱ��'\0'ASCIIֵΪ0���ж�Ϊ�٣�����
	while (isdigit(string[pos]))
	{
		char key = string[pos++];
		retNum = retNum * 10 + (key - '0');
		//�������ݹ���
		if (retNum > INT_MAX || retNum < INT_MIN) {
			return 0;
		}
	}
	return flag ? -(int)retNum : (int)retNum;
}

//int main()
//{
//	printf("%d\n", my_atoi("dqw-1212-wq"));
//	return 0;
//}

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime)
    {
        unordered_map< string, vector<int> > timeMap;
        vector<string> retList;
        //�ù�ϣ���¼����Ա�����ÿ�ʱ���б�
        for (int i = 0; i < keyName.size(); i++)
        {
            string name = keyName[i];
            string time = keyTime[i];
            //��24Сʱ��ת��Ϊ���ӣ����ڼ���
            int hour = (time[0] - '0') * 10 + (time[1] - '0');
            int minute = (time[3] - '0') * 10 + (time[4] - '0');
            timeMap[name].emplace_back(hour * 60 + minute);
        }
        //������ϣ��������Ա�����ÿ�ʱ���б�
        for (auto& [name, timeList] : timeMap)
        {
            sort(timeList.begin(), timeList.end());
            //����ʱ���б����м��
            for (int i = 2; i < timeList.size(); i++)
            {
                int subTime = timeList[i] - timeList[i - 2];
                if (subTime <= 60) {
                    retList.emplace_back(name);
                    break;//��ǰ��ֹ
                }
            }
        }
        sort(retList.begin(), retList.end());
        return retList;
    }
};