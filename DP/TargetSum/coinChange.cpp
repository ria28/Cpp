#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include<climits>
#define ll long long
using namespace std;
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)

// combination with infinite coins
void comb(vector<int> &arr, int tar)
{
    vector<int> dp(tar + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = arr[i]; j < dp.size(); j++)
        {
            dp[j] += dp[j - arr[i]];
        }
    }
    cout << dp[tar] << " ";
}

// permutation
void perm(vector<int> &arr, int tar)
{
    vector<int> dp(tar + 1, 0);
    dp[0] = 1;
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[j] <= i)
                dp[i] += dp[i - arr[j]];
        }
    }
    cout << dp[tar] << " ";
}

// https://leetcode.com/problems/coin-change-2/
// combination
int change(int target, vector<int> &coins)
{
    // 1D vector coz we have duplicacy over here or infinite coins
    vector<int> dp(target + 1, 0);

    // since this is a ques of combination
    dp[0] = 1;
    for (int i = 0; i < coins.size(); i++)
    {
        for (int j = coins[i]; j < dp.size(); j++)
        {
            // if(coins[i]<=j)
            dp[j] += dp[j - coins[i]];
        }
    }
    return dp[target];
}

// https://leetcode.com/problems/coin-change/
int coinChange(vector<int> &arr, int target)
{
    // permutation
    vector<long long> dp(target + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= target; i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[j] <= i)
                dp[i] = min(dp[i], dp[i - arr[j]] + 1);
        }
    }
    return dp[target] > target ? -1 : dp[target];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> coins = {2, 3, 5, 6};
    int tar = 10;
    comb(coins, tar);
    perm(coins, tar);
    return 0;
}