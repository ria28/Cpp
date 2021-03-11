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

// https://leetcode.com/problems/regular-expression-matching/

bool isMatch(string s, string p)
{
    vector<vector<bool>> dp(p.size() + 1, vector<bool>(s.size() + 1));

    for (int i = 0; i < p.size() + 1; i++)
    {
        for (int j = 0; j < s.size() + 1; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = true;
            else
            {
                if (i == 0)
                    dp[i][j] = false;
                else if (j == 0)
                {
                    if (p[i - 1] == '*')
                    {
                        dp[i][j] = dp[i - 2][j];
                    }
                    else
                    {
                        dp[i][j] = false;
                    }
                }
                else
                {
                    if (p[i - 1] == '*')
                    {
                        if (dp[i - 2][j] == true || ((p[i - 2] == s[j - 1] || p[i - 2] == '.') && dp[i][j - 1] == true))
                        {
                            dp[i][j] = true;
                        }
                        else
                        {
                            dp[i][j] = false;
                        }
                    }
                    else if (p[i - 1] == '.')
                    {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                    else if (p[i - 1] != s[j - 1])
                    {
                        dp[i][j] = false;
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
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

    return dp[p.size()][s.size()];
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    string str = "mississippi";
    string p = "mis*i.*p*i";
    isMatch(str, p);
    return 0;
}