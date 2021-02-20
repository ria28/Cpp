#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)

// same as target sum subset 2D matrix
int knapsack_01(vector<int> &profit, vector<int> &wt, int n, int capacity)
{
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[0].size(); j++)
        {
            if (wt[i - 1] <= j)
            {
                // cout<<wt[i]<<" ";
                int new_pro = profit[i - 1] + dp[i - 1][j - wt[i - 1]];
                dp[i][j] = max(dp[i - 1][j - 1], new_pro);
            }
        }
    }
    for (int i = 0; i < dp.size(); i++)
    {
        for (auto j : dp[i])
            cout << j << " ";
        cout << "\n";
    }
    return dp[n][capacity];
}

// unbounded knapsack
// here we have duplicacy unlike knapsack above--> this is more like combination/permutation 1D TABULATION ARRAY
int unbounded_knap(vector<int> &profit, vector<int> &wt, int n, int capacity)
{
    vector<int> dp(capacity + 1, 0);
    dp[0] = 0;
    for (int i = 1; i < n; i++) // wts
    {
        for (int j = wt[i]; j <= capacity; j++) // dp array
        {
            dp[j] = max(dp[j], dp[j - wt[i]] + profit[i]);
        }
    }
    return dp[capacity];
}

int unbounded_knap_perm(vector<int> &profit, vector<int> &wt, int n, int capacity)
{
    vector<int> dp(capacity + 1, 0);
    dp[0] = 0;

    for (int i = 1; i <= capacity; i++) // dp array of capacity + 1 size
    {
        for (int j = 0; j < n; j++) // n elements or the given weights
        {
            if (wt[j] <= i)
            {
                dp[i] = max(dp[i], profit[j] + dp[i - wt[j]]);
            }
        }
    }

    return dp[capacity];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 5;
    // cin >> n;
    vector<int> profit = {15, 14, 10, 45, 30};
    vector<int> wt = {2, 5, 1, 3, 4};
    int capacity = 7;
    // cout << knapsack_01(profit, wt, n, capacity);

    // cout << unbounded_knap(profit, wt, n, capacity);
    cout<<unbounded_knap_perm(profit, wt, n, capacity);

    return 0;
}