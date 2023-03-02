#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//void print(char* s)
//{
//	if (*s)
//	{
//		print(++s);
//		printf("%c", *s);
//	}
//}
//
//int main()
//{
//	char str[] = "Geneius";
//	print(str);
//	return 0;
//}

//int main()
//{
//	char a[] = "124124";
//	char b[] = { '1', '2', '3' };
//	printf("%s\n", a);
//	return 0;
//}

struct ListNode
{
    int val;
    struct ListNode* next;
};

//struct ListNode* partition(struct ListNode* head, int x)
//{
//    struct ListNode* smallerHead = NULL;
//    struct ListNode* smallerTail = NULL;
//    struct ListNode* largerHead = NULL;
//    struct ListNode* largerTail = NULL;
//    struct ListNode* cur = head;
//    while (cur)
//    {
//        if (cur->val < x)
//        {
//            if (smallerHead == NULL)
//            {
//                smallerHead = cur;
//                smallerTail = cur;
//            }
//            else
//            {
//                smallerTail->next = cur;
//                smallerTail = smallerTail->next;
//            }
//        }
//        else
//        {
//            if (largerHead == NULL)
//            {
//                largerHead = cur;
//                largerTail = cur;
//            }
//            else
//            {
//                largerTail->next = cur;
//                largerTail = largerTail->next;
//            }
//        }
//        cur = cur->next;
//    }
//    smallerTail->next = largerHead;
//    largerTail->next = NULL;
//
//    return smallerHead;
//}

struct ListNode* partition(struct ListNode* head, int x)
{
    if (head == NULL) {
        return NULL;
    }
    struct ListNode* smallerHead = NULL;
    struct ListNode* smallerTail = NULL;
    struct ListNode* largerHead = NULL;
    struct ListNode* largerTail = NULL;
    struct ListNode* cur = head;
    while (cur)
    {
        if (cur->val < x)
        {
            if (smallerHead == NULL) {
                smallerHead = cur;
                smallerTail = cur;
            }
            else {
                smallerTail->next = cur;
                smallerTail = smallerTail->next;
            }
        }
        else
        {
            if (largerHead == NULL) {
                largerHead = cur;
                largerTail = cur;
            }
            else {
                largerTail->next = cur;
                largerTail = largerTail->next;
            }
        }
        cur = cur->next;
    }

    if (smallerHead == NULL) {
        return largerHead;
    }
    else if (largerHead == NULL) {
        return smallerHead;
    }
    else
    {
        smallerTail->next = largerHead;
        largerTail->next = NULL;
        return smallerHead;
    }
}

int main()
{
    struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    n1->val = 1;

    struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    n2->val = 4;

    struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    n3->val = 3;

    struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    n4->val = 2;

    struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
    n5->val = 5;

    struct ListNode* n6 = (struct ListNode*)malloc(sizeof(struct ListNode));
    n6->val = 2;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = NULL;

    partition(n1, 3);
    return 0;
}