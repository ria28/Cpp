#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#define ll long long
using namespace std;
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)
#define vi vector<int>
#define vii vector<vector<int>>

// https://leetcode.com/problems/maximal-square/

int maximalSquare(vector<vector<int>> &matrix)
{
    if (matrix.size() == 0)
        return 0;
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));
    int max_sq = 0;
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= cols; j++)
        {
            if (matrix[i - 1][j - 1] == 1)
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                max_sq = max(max_sq, dp[i][j]);
            }
        }
    }
    return max_sq * max_sq;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vii arr = {{0, 1, 1, 0, 1},
               {1, 1, 0, 1, 0},
               {0, 1, 1, 1, 0},
               {1, 1, 1, 1, 0},
               {1, 1, 1, 1, 1},
               {0, 0, 0, 0, 0}};
    cout << maximalSquare(arr);
    return 0;
}