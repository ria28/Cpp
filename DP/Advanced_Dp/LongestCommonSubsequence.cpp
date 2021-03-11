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

// https://leetcode.com/problems/longest-common-subsequence/

void common(string str1, string str2)
{
    int n1 = str1.size();
    int n2 = str2.size();
    vii dp(n1 + 1, vi(n2 + 1));

    for (int i = n1; i >= 0; i--)
    {
        for (int j = n2; j >= 0; j--)
        {

            if (i == n1 || j == n2)
            {
                dp[i][j] = 0;
            }
            else
            {
                if (str1[i] == str2[j])
                {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
            // cout << dp[i][j] << " ";
        }
    }

    for (int i = 0; i < dp.size(); i++)
    {
        for (auto j : dp[i])
            cout << j << " ";
        cout << "\n";
    }
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    string str1 = "abcd";
    string str2 = "aebd";
    common(str2, str1);
    return 0;
}