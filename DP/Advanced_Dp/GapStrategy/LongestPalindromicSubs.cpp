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

// https://leetcode.com/problems/longest-palindromic-subsequence/

void palin(string str, int n)
{
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
                {
                    dp[i][j] = 2;
                }
                else
                {
                    dp[i][j] = 1;
                }
            }
            else
            {
                string sub = str.substr(i, gap + 1);
                if (str[i] == str[j])
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
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
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str = "abkccbc";
    palin(str, str.size());
    return 0;
}