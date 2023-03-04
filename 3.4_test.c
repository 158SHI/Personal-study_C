#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode* next;    
};

void Reverse(struct ListNode* leftNode)
{
    struct ListNode* prev = NULL;
    struct ListNode* cur = leftNode;
    struct ListNode* nextNode = cur->next;

    while (cur)
    {
        cur->next = prev;
        prev = cur;
        cur = nextNode;
        if (nextNode != NULL) {
            nextNode = nextNode->next;
        }
    }
}

struct ListNode* reverseBetween(struct ListNode* head, int left, int right)
{
    struct ListNode* dummyNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyNode->next = head;
    struct ListNode* leftNode = head;
    struct ListNode* preLeft = dummyNode;
    //struct ListNode* preLeft = NULL;
    //if (left == 1) {
    //    preLeft = dummyNode;
    //}
    //else {
    //    preLeft = head;
    //}
    struct ListNode* rightNode = head;
    struct ListNode* nextRight = head;
    struct ListNode* cur = head;
    int step = 1;
    while (cur)
    {
        if (step <= left - 1) {
            preLeft = preLeft->next;
        }
        if (step < left) {
            leftNode = leftNode->next;
        }
        if (step < right + 1) {
            nextRight = nextRight->next;
        }
        if (step < right) {
            rightNode = rightNode->next;
        }
        cur = cur->next;
        step++;
    }
    rightNode->next = NULL;
    preLeft->next = NULL;
    Reverse(leftNode);
    preLeft->next = rightNode;
    leftNode->next = nextRight;
    return dummyNode->next;
}

int main()
{
    struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    n1->val = 3;

    struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    n2->val = 5;

    struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    n3->val = 3;

    struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    n4->val = 4;

    struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
    n5->val = 5;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;

    reverseBetween(n1, 3, 4);
    return 0;
}