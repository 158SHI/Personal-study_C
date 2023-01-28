#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<set>

using namespace std;

//int main()
//{
//	set<int> s;
//	s.insert(2);
//	s.insert(1);
//	s.insert(3);
//	s.insert(4);
//	if (s.find(5) == s.end())
//	{
//		cout << "Not in" << endl;
//	}
//	return 0;
//}


 struct ListNode
 {
     int val;
      struct ListNode *next;
 };
 
typedef struct ListNode ListNode;

ListNode* BuyNode(int value)
{
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->next = NULL;
    newNode->val = value;
    return newNode;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    ListNode* head = NULL;
    ListNode* tail = NULL;
    int carry = 0;
    while (l1 != NULL || l2 != NULL)
    {
        int n1 = (l1 == NULL ? 0 : l1->val);
        int n2 = (l2 == NULL ? 0 : l2->val);
        int sum = (n1 + n2 + carry) % 10;
        carry = (n1 + n2 + carry) / 10;

        ListNode* tmp = BuyNode(sum);
        if (tail == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tmp;
        }

        if (l1) {
            l1 = l1->next;
        }
        if (l2) {
            l2 = l2->next;
        }
    }
    if (carry > 0)
    {
        ListNode* tmp = BuyNode(carry);
        tail->next = tmp;
        tail = tmp;
    }
    return head;
}

int main()
{
    ListNode* n1 = BuyNode(9);
    ListNode* n2 = BuyNode(9);
    ListNode* n3 = BuyNode(9);
    ListNode* n4 = BuyNode(9);
    ListNode* n5 = BuyNode(9);
    ListNode* n6 = BuyNode(9);
    ListNode* n7 = BuyNode(9);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;

    ListNode* m1 = BuyNode(9);
    ListNode* m2 = BuyNode(9);
    ListNode* m3 = BuyNode(9);
    ListNode* m4 = BuyNode(9);
    m1->next = m2;
    m2->next = m3;
    m3->next = m4;

    addTwoNumbers(n1, m1);
    return 0;
}