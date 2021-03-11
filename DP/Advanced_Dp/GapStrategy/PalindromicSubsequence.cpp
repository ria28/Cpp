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

// gap strategy
void countPalin(string str)
{
    int n = str.size();
    vii dp(n, vi(n));

    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            if (gap == 0)
            {
                dp[i][j] = 1;
            }
            else if (gap == 1)
            {
                if (str[i] == str[j])
                    dp[i][j] = 3;
                else
                    dp[i][j] = 2;
            }
            else
            {
                if (str[i] == str[j])
                {
                    int prefix = dp[i][j - 1];
                    int suffix = dp[i + 1][j];
                    dp[i][j] = prefix + suffix + 1;
                }
                else
                {
                    int prefix = dp[i][j - 1];
                    int suffix = dp[i + 1][j];
                    int middle = dp[i + 1][j - 1];
                    dp[i][j] = prefix + suffix - middle;
                }
            }
        }
    }
    cout << dp[0][n-1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    countPalin("abccbc"); // not distinct (but all)
    return 0;
}