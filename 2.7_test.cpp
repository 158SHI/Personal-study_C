#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
#include<stdlib.h>

//int main()
//{
//	int n = 9;
//	//00000000 00000000 00000000 00001001 - 补码
//	float* pFloat = (float*)&n;
//	printf("n的值为：%d\n", n);// 9
//	printf("*pFloat的值为：%f\n", *pFloat);// 0.000000
//	//0 00000000 00000000000000000001001 - *pFloat
//	*pFloat = 9.0;
//	printf("num的值为：%d\n", n);
//	//1001.0
//	//(-1) ^ 0 * 1.001 * 2 ^ 3
//	//0 10000010 00100000000000000000000
//	//01000001 00010000 00000000 00000000
//	//1,091,567,616
//	printf("*pFloat的值为：%f\n", *pFloat);// 9.000000
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
	assert(string);//避免指针为空
	bool flag = false;//记录正负
	long long retNum = 0;//因为要判断int的边界，所以retNum定义为long long类型
	int pos = 0;
	//忽略前面的字符
	while (!isdigit(string[pos]) && string[pos] != '-')
	{
		pos++;
	}
	//判断正负
	if (string[pos] == '-') {
		flag = true;
		pos++;
	}
	//遇到'\0'时，'\0'ASCII值为0，判断为假，结束
	while (isdigit(string[pos]))
	{
		char key = string[pos++];
		retNum = retNum * 10 + (key - '0');
		//避免数据过大
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
        //用哈希表记录各个员工的用卡时间列表
        for (int i = 0; i < keyName.size(); i++)
        {
            string name = keyName[i];
            string time = keyTime[i];
            //将24小时制转化为分钟，便于计算
            int hour = (time[0] - '0') * 10 + (time[1] - '0');
            int minute = (time[3] - '0') * 10 + (time[4] - '0');
            timeMap[name].emplace_back(hour * 60 + minute);
        }
        //遍历哈希表，检查各个员工的用卡时间列表
        for (auto& [name, timeList] : timeMap)
        {
            sort(timeList.begin(), timeList.end());
            //遍历时间列表，进行检查
            for (int i = 2; i < timeList.size(); i++)
            {
                int subTime = timeList[i] - timeList[i - 2];
                if (subTime <= 60) {
                    retList.emplace_back(name);
                    break;//提前终止
                }
            }
        }
        sort(retList.begin(), retList.end());
        return retList;
    }
};