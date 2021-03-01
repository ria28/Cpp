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
int subsets(int n, int k, vii &dp)
{
    if (n == 0 || k == 0 || n < k)
    {
        return 0;
    }
    for (int t = 1; t <= k; t++)
    {
        for (int p = 1; p <= n; p++)
        {
            if (p < t)
            {
                dp[t][p] = 0;
            }
            else if (t == p)
            {
                dp[t][p] = 1;
            }
            else
            {
                dp[t][p] = dp[t - 1][p - 1] + dp[t][p - 1] *t;
            }
        }
    }
    return dp[k][n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vii dp(k + 1, vector<int>(n + 1, 0));
    // dp.resize(k + 1);
    for (int i = 0; i <= k; i++)
    {
        dp[i].resize(n + 1);
    }
    // dp.resize(k + 1,vector<int>().resize(n+1));
    cout << subsets(n, k, dp) << " ";
    return 0;
}