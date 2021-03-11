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

// https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
//tushar roy
void rodcut(vi &prices, int n)
{
    vii dp(prices.size()+1, vi(n + 1, 0));

    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[0].size(); j++)
        {
            if (j == 0)
                dp[i][j] = 0;
            else
            {
                if (i == 0)
                {
                    dp[i][j] = prices[i-1] * j;
                }
                else if (j >= i)
                {
                    dp[i][j] = max(dp[i - 1][j], prices[i-1] + dp[i][j - i]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }
    for (int i = 0; i < dp.size(); i++)
    {
        for (auto j : dp[i])
            cout << j << " ";
        cout << "\n";
    }
    // cout << dp[prices.size() - 1][n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vi profit = {2, 5, 7, 8};
    int n = 5;
    rodcut(profit, n);
    return 0;
}