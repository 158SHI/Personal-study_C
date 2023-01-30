#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

class Solution
{
public:

    static bool cmp(pair<int, int>& m, pair<int, int>& n)
    {
        return m.second > n.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> hash;
        priority_queue<pair<int, int>, vector< pair<int, int> >, decltype(&cmp)> que(cmp);
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            hash[nums[i]]++;
        }
        for (auto& [num, count] : hash)
        {
            if (que.size() < k) {
                que.emplace(num, count);
            }
            else
            {
                if (count > que.top().second) {
                    que.pop();
                    que.emplace(num, count);
                }
            }
        }
        while (!que.empty())
        {
            ans.emplace_back(que.top().first);
            que.pop();
        }
        return ans;
    }
};