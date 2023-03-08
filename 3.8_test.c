#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode* next;    
};

typedef struct ListNode ListNode;

ListNode* BuyNode(int x)
{
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    assert(newNode);
    newNode->next = NULL;
    newNode->val = x;
    return newNode;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    ListNode* retHead = NULL;
    ListNode* tail = NULL;
    ListNode* cur1 = l1;
    ListNode* cur2 = l2;
    int carry = 0;
    while (cur1 || cur2)
    {
        //无节点视节点值为 0
        int n1 = (cur1 == NULL ? 0 : cur1->val);
        int n2 = (cur2 == NULL ? 0 : cur2->val);
        int sum = (n1 + n2 + carry) % 10; //和
        carry = (n1 + n2 + carry) / 10; //余数

        ListNode* newNode = BuyNode(sum);
        if (retHead == NULL) {
            retHead = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = tail->next;
        }
        if (cur1) {
            cur1 = cur1->next;
        }
        if (cur2) {
            cur2 = cur2->next;
        }
    }
    //余数大于 0，新建节点进位
    if (carry > 0) {
        ListNode* newNode = BuyNode(carry);
        tail->next = newNode;
        tail = tail->next;
    }
    return retHead;
}
