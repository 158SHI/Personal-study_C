#define _CRT_SECURE_NO_WARNINGS 1

#include"1.18_test.h"
//子串匹配问题

int BpSolution::BF(string str, string sub)
{
	int StBegin = 0;
	int SuBegin = 0;
	int i = 0;//遍历主串
	int j = 0;//遍历子串
	while (i < str.length() && j < sub.length())
	{
		if (str.at(i) == sub.at(j)) {
			i++;
			j++;
		}
		else {
			StBegin++;
			i = StBegin;
			j = SuBegin;
		}
	}
	if (j == sub.length()) {
		return StBegin;
	}
	else {
		return -1;
	}
}

void KmpSolution::getNext(int*& next, string sub)
{
	next[0] = -1;
	int k = -1;//k一直是前一项(sub.at(i - 1))的k
	for (int i = 1; i < sub.length(); )
	{
		if (k == -1 || sub.at(i - 1) == sub.at(k)){
			
			next[i] = k + 1;
			k++;//这种情况k应该自增1
			i++;
		}
		else {
			k = next[k];
		}
	}
}

int KmpSolution::KMP(string str, string sub)
{
	int i = 0;//遍历主串
	int j = 0;//遍历子串
	int lenStr = str.length();
	int lenSub = sub.length();
	int* next = new int[lenSub];
	getNext(next, sub);//计算next数组
	while (i < lenStr && j < lenSub)
	{
		if (j == -1 || str.at(i) == sub.at(j)){
			i++;
			j++;
		}
		else {
			j = next[j];
		}
	}
	if (j == lenSub) {
		return i - j;
	}
	else {
		return -1;
	}
}

int main()
{
	//BpSolution Bf;
	//cout << Bf.BF("a", "a") << endl;
	KmpSolution Kmp;
	cout << Kmp.KMP("dsaabcaab", "abcaab") << endl;
	return 0;
}