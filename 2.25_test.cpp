#define _CRT_SECURE_NO_WARNINGS 1

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        int rowJudge[9][9] = { 0 };
        int colJudge[9][9] = { 0 };
        int gridJudge[3][3][9] = { 0 };
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int index = board[i][j] - '0' - 1;
                    rowJudge[i][index]++;
                    colJudge[j][index]++;
                    gridJudge[i / 3][j / 3][index]++;

                    if (rowJudge[i][index] > 1 || colJudge[j][index] > 1 ||
                        gridJudge[i / 3][j / 3][index] > 1)
                    {
                        return false;
                    }
                }

            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> v{ {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
         {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
         {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9' },
    };
    s.isValidSudoku(v);
    return 0;
}