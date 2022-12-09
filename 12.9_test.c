#define _CRT_SECURE_NO_WARNINGS 1

#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>


struct ListNode
{
    int val;
    struct ListNode* next;
};

struct ListNode* removeElements(struct ListNode* head, int val)
{
    //创建一个新链表，将原链表中不满足条件的节点尾插到新链表
    struct ListNode* NewHead = NULL;
    struct ListNode* tail = NULL;//方便尾插

    struct ListNode* cur = head;
    while (cur)
    {
        if (cur->val != val)
        {
            if (tail == NULL)
            {
                NewHead = cur;
                tail = cur;
            }
            else
            {
                tail->next = cur;
                tail = tail->next;
            }
        }
        cur = cur->next;
    }

    tail->next = NULL;
    return NewHead;
}

void SListPrint(struct ListNode* head)
{
    struct ListNode* cur = head;
    while (cur)
    {
        printf("%d ", cur->val);
        cur = cur->next;
    }
}

int main()
{
    struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    node1->val = 1;
    node1->next = NULL;

    struct ListNode* node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    node2->val = 2;
    node2->next = NULL;

    struct ListNode* node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    node3->val = 6;
    node3->next = NULL;

    struct ListNode* node4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    node4->val = 3;
    node4->next = NULL;

    struct ListNode* node5 = (struct ListNode*)malloc(sizeof(struct ListNode));
    node5->val = 4;
    node5->next = NULL;

    struct ListNode* node6 = (struct ListNode*)malloc(sizeof(struct ListNode));
    node6->val = 5;
    node6->next = NULL;

    struct ListNode* node7 = (struct ListNode*)malloc(sizeof(struct ListNode));
    node7->val = 6;
    node7->next = NULL;

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = NULL;

    //removeElements(node1, 6);

    SListPrint(node1);

    return 0;
}

//进制转换
//void Exchange(int n)
//{
//    if (n > 2)
//    {
//        Exchange(n / 2);
//    }
//    printf("%d", n % 2);
//}
//
//int main()
//{
//    int n = 5;
//    Exchange(n);
//
//    return 0;
//}