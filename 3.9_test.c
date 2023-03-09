#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int val;
    struct ListNode* next;    
}ListNode;

struct ListNode* detectCycle(struct ListNode* head)
{
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            struct ListNode* meet = slow;
            struct ListNode* cur = head;
            while (cur != meet)
            {
                cur = cur->next;
                meet = meet->next;
            }
            return cur;
        }
    }
    return NULL;
}

int main()
{
    ListNode* n1 = (ListNode*)malloc(sizeof(ListNode));
    n1->val = 3;

    ListNode* n2 = (ListNode*)malloc(sizeof(ListNode));
    n2->val = 2;

    ListNode* n3 = (ListNode*)malloc(sizeof(ListNode));
    n3->val = 0;

    ListNode* n4 = (ListNode*)malloc(sizeof(ListNode));
    n4->val = -4;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;

    detectCycle(n1);
	return 0;
}