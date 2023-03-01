#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode 
{
	int val;
	struct ListNode* next;	
}ListNode;

//struct ListNode* rotateRight(struct ListNode* head, int k)
//{
//	if (head == NULL) {
//		return NULL;
//	}
//	struct ListNode* fast = head;
//	struct ListNode* slow = head;
//	struct ListNode* prev = NULL;
//	while (--k)
//	{
//		fast = fast->next;
//		if (fast == NULL) {
//			fast = head;
//		}
//	}
//	while (fast->next)
//	{
//		slow = prev;
//		fast = fast->next;
//		slow = slow->next;
//	}
//	prev->next = NULL;
//	fast->next = head;
//	return slow;
//}

//struct ListNode* rotateRight(struct ListNode* head, int k)
//{
//    if (head == NULL) {
//        return NULL;
//    }
//    if (k == 0) {
//        return head;
//    }
//
//    int length = 0;
//    ListNode* cur = head;
//    while (cur) {
//        length++;
//        cur = cur->next;
//    }
//
//    struct ListNode* fast = head;
//    struct ListNode* slow = head;
//    struct ListNode* prev = NULL;
//    k %= length;
//    while (--k)
//    {
//        fast = fast->next;
//        if (fast == NULL) {
//            fast = head;
//        }
//    }
//    while (fast->next)
//    {
//        prev = slow;
//        fast = fast->next;
//        slow = slow->next;
//    }
//
//    if (prev == NULL) {
//        return slow;
//    }
//    prev->next = NULL;
//    fast->next = head;
//    return slow;
//}

struct ListNode* rotateRight(struct ListNode* head, int k)
{
    if (head == NULL || k == 0) {
        return head;
    }

    int length = 0;
    struct ListNode* cur = head;
    while (cur) {
        length++;
        cur = cur->next;
    }

    struct ListNode* fast = head;
    struct ListNode* slow = head;
    struct ListNode* prev = NULL;

    k %= length;
    if (k == 0) {
        return slow;
    }

    while (--k)
    {
        fast = fast->next;
    }
    while (fast->next)
    {
        prev = slow;
        fast = fast->next;
        slow = slow->next;
    }

    if (prev == NULL) {
        return slow;
    }
    prev->next = NULL;
    fast->next = head;
    return slow;
}

int main()
{
	ListNode* n1 = (ListNode*)malloc(sizeof(ListNode));
	n1->val = 1;
	ListNode* n2 = (ListNode*)malloc(sizeof(ListNode));
	n2->val = 2;
	//ListNode* n3 = (ListNode*)malloc(sizeof(ListNode));
	//n3->val = 2;
	n1->next = n2;
	n2->next = NULL;
	
	//n3->next = NULL;
	
	rotateRight(n1, 3);
	
	return 0;
}