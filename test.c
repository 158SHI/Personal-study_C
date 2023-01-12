#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>


typedef struct ListNode
{
	int val;
	struct ListNode* next;	
}ListNode;

struct ListNode* deleteNode(struct ListNode* head, int val)
{
    if (head == NULL)
    {
        return NULL;
    }
    
    ListNode* pre = NULL;
    ListNode* i = head;
    ListNode* j = head;
    
    while (i != NULL)
    {
        if (i->val != val)
        {
            j->val = i->val;
            i = i->next;
            pre = j;
            j = j->next;
            
        }
        else
        {
            i = i->next;
        }
    }
    if (pre != NULL)
    {
        pre->next = NULL;
    }
    return head;
}


int main()
{
	ListNode* A = (ListNode*)malloc(sizeof(ListNode));
	A->val = 4;
	A->next = NULL;

	ListNode* B = (ListNode*)malloc(sizeof(ListNode));
	B->val = 5;
	B->next = NULL;

	ListNode* C = (ListNode*)malloc(sizeof(ListNode));
	C->val = 1;
	C->next = NULL;


	ListNode* D = (ListNode*)malloc(sizeof(ListNode));
	D->val = 9;
	D->next = NULL;

	A->next = B;
	B->next = C;
	C->next = D;

    deleteNode(A, 5);
    ListNode* cur = A;
    while (cur)
    {
        printf("%d->", cur->val);
        cur = cur->next;
    }

	return 0;
}