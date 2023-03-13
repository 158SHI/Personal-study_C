#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <set>
#include <vector>

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
    int numComponents(ListNode* head, vector<int>& nums)
    {
        set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }
        ListNode* cur = head;
        bool pre = false;
        int count = 0;
        while (cur)
        {
            if ((cur == head) && (s.find(cur->val) != s.end()))
            {
                count++;
                pre = true;
            }
            else if ((cur != head) && (s.find(cur->val) != s.end()) && !pre)
            {
                count++;
                pre = true;
            }
            else {
                pre = false;
            }
            cur = cur->next;
        }
        return count;
    }
};

int main()
{
    Solution s;

	return 0;
}