#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <utility>
#include <string>

using namespace std;

//pair<int, int> GetPair(void)
//{
//	return {1, 2};
//}
//
//int main()
//{
//	pair<int, int> p;
//	//auto [left1, right1] = GetPair();
//	//cout << p.first << endl;
//	string s = "abcd";
//	cout << s.length() << endl;
//	cout << s.size() << endl;
//	return 0;
//}

class Solution {
public:
    pair<int, int> Expand(string& s, int left, int right)
    {
        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return { left + 1, right - 1 };
    }

    string longestPalindrome(string s)
    {
        int begin = 0;
        int end = 0;
        for (int i = 0; i < s.length(); i++)
        {
            pair<int, int> p1 = Expand(s, i, i);
            pair<int, int> p2 = Expand(s, i, i + 1);
            if (p1.second - p1.first > end - begin)
            {
                begin = p1.first;
                end = p1.second;
            }
            if (p2.second - p2.first > end - begin)
            {
                begin = p2.first;
                end = p2.second;
            }
        }
        return s.substr(begin, end - begin + 1);
    }
};

int main()
{
    Solution s;
    s.longestPalindrome("babab");
    return 0;
}