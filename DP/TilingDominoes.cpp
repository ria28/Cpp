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
vector<ll> dp;
// int tiling_2X1(int n)
// {
//     if (dp[n] != -1)
//         return dp[n];
//     dp[n] = tiling_2X1(n - 1) + tiling_2X1(n - 2);
//     return dp[n];
// }

ll tiling_2X1(int n)
{
    dp[1] = 1;
    dp[2] = 2;
    for (ll i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    // 2 X n tiles
    dp.resize(n + 1, -1);
    // dp[1] = 1;
    // dp[2] = 2;
    cout << tiling_2X1(n) << " ";

    return 0;
}