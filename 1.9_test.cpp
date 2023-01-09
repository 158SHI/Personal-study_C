#define _CRT_SECURE_NO_WARNINGS 1

#include <unordered_map>
#include <iostream>
#include<vector>

using namespace std;

class Solution {
public:
    /**
     *
     * @param numbers int整型vector
     * @param target int整型
     * @return int整型vector
     */
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        vector<int> retNums;

        unordered_map<int, int> Hash;
        for (int i = 0; i < numbers.size(); i++)
        {
            Hash[numbers[i]] = i;
        }
        unordered_map<int, int>::iterator it;
        for (int i = 0; i < numbers.size(); i++)
        {
            it = Hash.find(target - numbers[i]);
            if (it != Hash.end() && it->second != i)
            {
                retNums.push_back(i);
                retNums.push_back(it->second);
                break;
            }
        }
        return  retNums;
    }
};

//int main()
//{
//    vector<int> v = { 3, 2, 4 };
//    Solution s;
//    s.twoSum(v, 6);
//    return 0;
//}

//模拟实现strlen

#include<assert.h>

size_t my_strlen(const char* p)
{
    assert(p);
    const char* end = p;
    while (*end++)
    {
        ;
    }
    return end - p - 1;
}

//int main()
//{
//    char arr[20] = "abcde";
//    printf("%d\n", my_strlen(arr));
//    return 0;
//}

char* my_strcpy(char* DestStr, const char* SourStr)
{
    assert(DestStr && SourStr);
    char* ret = DestStr;
    while (*DestStr++ = *SourStr++)
    {
        ;
    }
    return ret;
}

void test1(void)
{
    char Des[20] = "hello world";
    char Sour[20] = "world";
    printf("%s\n", my_strcpy(Des, Sour));
}

int my_strcmp(const char* DestStr, const char* SourStr)
{
    assert(DestStr && SourStr);
    while (*DestStr++ == *SourStr++)
    {
        if (*(DestStr - 1) == '\0')
        {
            return 0;
        }
    }
    return *(DestStr - 1) > *(SourStr - 1) ? 1 : -1;
}

void test2(void)
{
    char arr1[10] = "abcdg";
    char arr2[10] = "abcdg";
    if (my_strcmp(arr1, arr2) > 0){
        printf("arr1 > arr2\n");
    }
    else if(my_strcmp(arr1, arr2) < 0){
        printf("arr1 < arr2\n");
    }
    else{
        printf("arr1 == arr2\n");
    }
}

char* my_strcat(char* DestStr, const char* SourStr)
{
    assert(DestStr && SourStr);
    char* ret = DestStr;
    while (*DestStr++){
        ;
    }
    DestStr--;
    while (*DestStr++ = *SourStr++){
        ;
    }
    return ret;
}

void test3(void)
{
    char arr1[20] = "hello ";
    char arr2[10] = "world";
    printf("%s\n", my_strcat(arr1, arr2));
}

char* my_strstr(const char* DestStr, const char* SourStr)
{
    assert(DestStr && SourStr);
    const char* s1 = NULL;
    const char* s2 = NULL;
    const char* cp = DestStr;

    while (*cp)
    {
        s1 = cp;
        s2 = SourStr;
        while (*s1 == *s2 && *s1 && *s2)
        {
            s1++;
            s2++;
        }
        if (!*s1 && *s2){
            break;
        }
        if (!*s2){
            return (char*)cp;
        }
        if (*s1 != *s2){
            cp++;
        }
    }
    return NULL;
}

void test4(void)
{
    char Dest[20] = "abbbbcgdf";
    //char Dest[20] = "bbcg";
    char Sour[20] = "bbcg";
    printf("%s\n", my_strstr(Dest, Sour));
}

int main()
{
    //test2();
    //test3();
    test4();
    return 0;
}