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

void gameStrategy(vi &arr)
{
    int n = arr.size();
    vii dp(n, vi(n));
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; j++, i++)
        {
            if (gap == 0)
            {
                dp[i][j] = arr[i];
            }
            else if (gap == 1)
            {
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
            else
            {
                // left - middle - right    for 3 elements
                // 20-30-2
                int left = min(dp[i + 2][j], dp[i + 1][j - 1]) + arr[i];  // removing 2  ->> 20-30
                int right = min(dp[i][j - 2], dp[i + 1][j - 1]) + arr[j]; // removing 20 --> 30-2
                dp[i][j] = max(left, right);   // out of all the minimum left by the opponent I choose the maximum
            }  
        }
    }

    // for (int i = 0; i < dp.size(); i++)
    // {
    //     for (int j = 0; j < dp[0].size(); j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << dp[0][n - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vi arr = {20, 30, 2, 10};
    gameStrategy(arr);
    return 0;
}