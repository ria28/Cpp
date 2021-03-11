#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <math.h>
#define ll long long
using namespace std;
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)
#define vi vector<int>
#define vii vector<vector<int>>

// https://leetcode.com/problems/perfect-squares/
int numSquares(int n)
{
    vi dp(n + 1,0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < n + 1; i++)
    {
        int mi = INT_MAX;
        for (int j = 1 ;j <=sqrt(i); j++)
        {
            int k = i - pow(j, 2);
            mi = min(mi, dp[k]);
        }

        dp[i] = mi + 1;
        // cout<<dp[i]<<" ";
    }
    // for (int i = 0; i < n + 1; i++)
    //     cout << dp[i] << " ";
    return dp[n];
}

int main()
{
    // ios_base::sync_cls
    cout << numSquares(12);
    return 0;
}