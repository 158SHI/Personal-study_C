#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

void test1()
{
	SeqList sq;
	SeqListInit(&sq);
	SeqListPushBack(&sq, 1);
	SeqListPushBack(&sq, 2);
	SeqListPushBack(&sq, 3);
	SeqListPushBack(&sq, 4);
	SeqListPushHead(&sq, 1);
	SeqListPushHead(&sq, 1);
	SeqListPushHead(&sq, 1);
	SeqListDisplay(&sq);

	SeqListPopHead(&sq);
	SeqListPopHead(&sq);
	SeqListPopHead(&sq);
	SeqListDisplay(&sq);

	SeqListPopBack(&sq);
	SeqListPopBack(&sq);
	SeqListPopBack(&sq);
	SeqListPopBack(&sq);
	SeqListDisplay(&sq);
}

struct ListNode
{
    int val;
    struct ListNode* next;
};

int* reversePrint(struct ListNode* head, int* returnSize)
{
    if (head == NULL)
    {
        return NULL;
    }

    //先反转链表
    struct ListNode* first = NULL;
    struct ListNode* second = head;
    struct ListNode* third = head->next;
    int count = 0;

    while (second != NULL)
    {
        count++;
        second->next = first;
        first = second;
        second = third;
        if (third != NULL)
        {
            third = third->next;
        }
    }

    int* retNums = (int*)malloc(sizeof(int) * count);
    *returnSize = count;
    for (int i = 0; i < count; i++)
    {
        retNums[i] = first->val;
        first = first->next;
    }

    return retNums;
}

void test2()
{
    struct ListNode* l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->val = 1;
    l1->next = NULL;

    struct ListNode* l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->val = 2;
    l2->next = NULL;

    struct ListNode* l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l3->val = 3;
    l3->next = NULL;

    l1->next = l2;
    l2->next = l3;

    int sz = 0;
    int* retNums = reversePrint(NULL, &sz);
    for (int i = 0; i < sz; i++)
    {
        printf("%d ", retNums[i]);
    }
}


//char* replaceSpace(char* s)
//{
//    if (s == NULL)
//    {
//        return NULL;
//    }
//
//    int left = strlen(s) - 1;
//
//    int exp_size = 0;
//    for (int i = 0; i < strlen(s); i++)
//    {
//        if (s[i] == ' ')
//        {
//            exp_size += 2;
//        }
//    }
//
//    int right = strlen(s) + exp_size - 1;
//
//    char* tmp = (char*)realloc(s, sizeof(char) * (right + 1));
//    if (tmp != NULL)
//    {
//        s = tmp;
//    }
//
//    while (left >= 0)
//    {
//        if (s[left] != ' ')
//        {
//            s[right] = s[left];
//            right--;
//            left--;
//        }
//        else
//        {
//            s[right--] = '0';
//            s[right--] = '2';
//            s[right--] = '%';
//            left--;
//        }
//    }
//
//    return s;
//}

//void test3()
//{
//    char arr[20] = "hello world";
//    puts(replaceSpace(arr));
//}


char* replaceSpace(char* s)
{
    char* retStr = (char*)malloc(sizeof(char) * strlen(s) * 3 + 1);
    int i = 0;
    int j = 0;
    for (int i = 0; i <= strlen(s); i++)
    {
        if (s[i] != ' ')
        {
            retStr[j] = s[i];
            j++;
        }
        else
        {
            retStr[j++] = '%';
            retStr[j++] = '2';
            retStr[j++] = '0';
        }
    }
    return retStr;
}

void test4()
{
    char arr[30] = "     ";
    puts(replaceSpace(arr));
}

int main()
{
	//test1();
	//test2();
    //test3();
    test4();
	return 0;
}