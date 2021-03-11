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

// https://leetcode.com/problems/unique-binary-search-trees/

int catalan(int n)
{
    vi dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }

    // for (auto i : dp)
    //     cout << i << " ";
    return dp[n];
}
int numTrees(int n)
{
    return catalan(n);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    numTrees(3);
    return 0;
}