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


// https://leetcode.com/problems/burst-balloons/

int maxCoins(vector<int> &nums)
{
    int n = nums.size();
    vii dp(n, vi(n, 0));

    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; j++, i++)
        {
            for (int k = i; k <= j; k++)
            {
                int cost = 0;
                int right = 0, left = 0, val = 0;
                left = k == i ? 0 : dp[i][k - 1];
                right = k == j ? 0 : dp[k + 1][j];

                val = ((i == 0) ? 1 : nums[i - 1]) * (nums[k]) * ((j == n - 1) ? 1 : nums[j + 1]);
                int total = left + right + val;
                dp[i][j] = max(dp[i][j], total);
            }
        }
    }
    cout << dp[0][n - 1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vi nums = {3, 1, 5, 8};
    maxCoins(nums);
    return 0;
}