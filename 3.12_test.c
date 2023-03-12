#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct ListNode
{
    int val;
    struct ListNode* next;    
};

typedef struct ListNode ListNode;

struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize)
{
    struct ListNode** retListArr = (struct ListNode**)malloc(sizeof(struct ListNode*) * k);
    *returnSize = k;
    int count = 0;
    struct ListNode* cur = head;
    while (cur)
    {
        count++;
        cur = cur->next;
    }
    int quotient = count / k; //3
    int remainder = count % k; //1
    int grp = 0;
    cur = head;
    while (grp < k)// < 3
    {
        retListArr[grp] = cur;

        if (grp < remainder)
        {
            for (int i = 0; i < quotient; i++) {
                cur = cur->next;
            }
        }
        else
        {
            for (int i = 0; i < quotient - 1; i++) {
                cur = cur->next;
            }
        }
        struct ListNode* nextNode = (cur == NULL ? NULL : cur->next);
        if (cur != NULL)
            cur->next = NULL;
        cur = nextNode;
        grp++;
    }
    return retListArr;
}

ListNode* BuyNode(int x)
{
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    assert(newNode);
    newNode->val = x;
    newNode->next = NULL;
    return newNode;
}

int main()
{

    ListNode* n1 = BuyNode(1);
    ListNode* n2 = BuyNode(2);
    ListNode* n3 = BuyNode(3);
    ListNode* n4 = BuyNode(4);
    ListNode* n5 = BuyNode(5);
    ListNode* n6 = BuyNode(6);
    ListNode* n7 = BuyNode(7);
    ListNode* n8 = BuyNode(8);
    ListNode* n9 = BuyNode(9);
    ListNode* n10 = BuyNode(10);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;
    n8->next = n9;
    n9->next = n10;

    int retSz = 0;
    splitListToParts(n1, 3, &retSz);
    return 0;
}