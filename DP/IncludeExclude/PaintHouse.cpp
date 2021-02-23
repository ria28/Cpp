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

// https://www.lintcode.com/problem/paint-house-ii/#:~:text=There%20are%20a%20row%20of,houses%20have%20the%20same%20color.
// Leetcode 516
int minCostII(vector<vector<int>> &costs)
{
    // write your code here
    int n = costs.size();
    if (n == 0)
        return 0;

    vector<vector<int>> dp(costs.size(), vector<int>(costs[0].size()));
    int prev_mi = INT_MAX;   // min
    int prev_s_mi = INT_MAX; // second minimum
    for (int i = 0; i < dp.size(); i++)
    {
        int curr_mi = INT_MAX;
        int curr_s_mi = INT_MAX; // next min , next second min
        for (int j = 0; j < dp[0].size(); j++)
        {
            if (i == 0)
            {
                dp[i][j] = costs[i][j];
                if (curr_mi > dp[i][j])
                {
                    curr_s_mi = curr_mi;
                    curr_mi = dp[i][j];
                }
                else if (curr_s_mi > dp[i][j])
                {
                    curr_s_mi = dp[i][j];
                }
            }
            else
            {
                int prev_cost = prev_mi == dp[i - 1][j] ? prev_s_mi : prev_mi;
                dp[i][j] = costs[i][j] + prev_cost;
                if (curr_mi > dp[i][j])
                {
                    curr_s_mi = curr_mi;
                    curr_mi = dp[i][j];
                }
                else if ( curr_s_mi > dp[i][j])
                {
                    curr_s_mi = dp[i][j];
                }
            }
        }
        // cout << "hello " << curr_mi << " " << curr_s_mi << "\n";
        prev_mi = curr_mi;
        prev_s_mi = curr_s_mi;
    }
    int res = INT_MAX;
    for (int i = 0; i < dp[0].size(); i++)
    {
        res = min(res, dp[n - 1][i]);
    }
    return res;
}

// https://www.lintcode.com/problem/paint-house/my-submissions
// Leetcode 515
int minCost(vector<vector<int>> &costs)
{
    // write your code here
    int n = costs.size();
    vector<vector<int>> dp(n, vector<int>(3)); // rows : n (houses) , col: 3 (colors)
    dp[0][0] = costs[0][0];
    dp[0][1] = costs[0][1];
    dp[0][2] = costs[0][2];
    for (int i = 1; i < costs.size(); i++)
    {
        dp[i][0] = costs[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = costs[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = costs[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }
    int res = INT_MAX;
    for (int i = 0; i < 3; i++)
    {
        res = min(res, dp[n - 1][i]);
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // vector<vector<int>> cost = {{14, 2, 11}, {11, 14, 5}, {14, 3, 10}};
    // cout << minCost(cost);

    // leetcode 516
    int n, k;
    n = 4;
    k = 6;
    // cin>>n>>k;
    vector<vector<int>> costs(n, vector<int>(k));
    // costs = {{3, 5, 7, 2, 1, 4}, {5, 8, 4, 3, 6, 4}, {3, 2, 9, 7, 2, 3}, {1, 2, 4, 9, 1, 7}};
    costs = {{3, 5, 3}, {6, 17, 6}, {7, 13, 18}, {9, 10, 18}};
    cout << minCostII(costs);
    return 0;
}