#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <stack>
#include <assert.h>

using namespace std;

struct ListNode 
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}    
};

class Solution {

public:
    ListNode* BuyNode(int x)
    {
        ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
        assert(newNode);
        newNode->val = x;
        newNode->next = nullptr;
        return newNode;
    }

    void ListPushFront(ListNode* pHead, int x)
    {
        ListNode* newNode = BuyNode(x);
        newNode->next = pHead->next;
        pHead->next = newNode;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        stack<ListNode*> s1;
        stack<ListNode*> s2;
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        while (cur1) {
            s1.push(cur1);
            cur1 = cur1->next;
        }
        while (cur2) {
            s2.push(cur2);
            cur2 = cur2->next;
        }
        ListNode* dummyHead = BuyNode(0);
        int carry = 0;
        while (!s1.empty() || !s2.empty())
        {
            int n1 = (s1.empty() ? 0 : s1.top()->val);
            int n2 = (s2.empty() ? 0 : s2.top()->val);
            int sum = (n1 + n2 + carry) % 10;
            carry = (n1 + n2 + carry) / 10;
            ListPushFront(dummyHead, sum);
            if (!s1.empty()) {
                s1.pop();
            }
            if (!s2.empty()) {
                s2.pop();
            }
        }
        if (carry > 0) {
            ListPushFront(dummyHead, carry);
        }
        ListNode* retHead = dummyHead->next;
        free(dummyHead);
        return retHead;
    }
};

int main()
{
    Solution s;
    ListNode* n1 = s.BuyNode(7);
    ListNode* n2 = s.BuyNode(2);
    ListNode* n3 = s.BuyNode(4);
    ListNode* n4 = s.BuyNode(3);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;

    ListNode* m1 = s.BuyNode(5);
    ListNode* m2 = s.BuyNode(6);
    ListNode* m3 = s.BuyNode(4);
    m1->next = m2;
    m2->next = m3;
    m3->next = NULL;

    s.addTwoNumbers(n1, m1);

    return 0;
}