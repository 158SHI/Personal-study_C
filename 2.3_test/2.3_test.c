#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }

    struct ListNode* i = l1;
    struct ListNode* j = l2;
    struct ListNode* newHead = NULL;
    if (i->val < j->val) {
        newHead = i;
        i = i->next;
    }
    else {
        newHead = j;
        j = j->next;
    }
    struct ListNode* cur = newHead;

    while (i != NULL && j != NULL)
    {
        if (i->val < j->val) {
            cur->next = i;
            i = i->next;
        }
        else {
            cur->next = j;
            j = j->next;
        }
        cur = cur->next;
    }

    if (i != NULL) {
        cur->next = i;
    }
    else {
        cur->next = j;
    }
    return newHead;
}

struct ListNode* merge(struct ListNode** lists, int l, int r)
{
    if (l == r) {
        return lists[l];
    }
    int mid = l + ((r - l) >> 1);
    return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    if (lists == NULL || listsSize == 0) {
        return NULL;
    }
    return merge(lists, 0, listsSize - 1);
}