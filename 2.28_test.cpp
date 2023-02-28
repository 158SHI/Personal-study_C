#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums)
    {
        int maxPos = 0, n = nums.size(), end = 0, step = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            if (maxPos >= i)
            {
                maxPos = max(maxPos, i + nums[i]);
                //到达边界，更新边界
                if (i == end)
                {
                    end = maxPos;
                    ++step;
                }
            }
        }
        return step;
    }
};

int main()
{
    Solution s;
    vector<int> v{ 2, 3, 1, 1, 4 };
    s.jump(v);
    return 0;
}