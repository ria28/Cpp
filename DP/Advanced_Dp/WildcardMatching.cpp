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

bool isMatch(string str, string p)
{
    int n1 = str.size();
    int n2 = p.size();
    vector<vector<bool>> dp(n2 + 1, vector<bool>(n1 + 1));

    for (int i = n2; i >= 0; i--)
    {
        for (int j = n1; j >= 0; j--)
        {
            if (i == n2 && j == n1)
                dp[i][j] = true;
            else if (i == n2)
                dp[i][j] = false;
            else if (j == n1)
            {
                if (p[i] == '*')
                {
                    dp[i][j] = dp[i + 1][j];
                }
                else
                {
                    dp[i][j] = false;
                }
            }
            else
            {
                if (p[i] == '?')
                {
                    dp[i][j] = dp[i + 1][j + 1];
                }
                else if (p[i] == '*')
                {
                    dp[i][j] = dp[i][j + 1] || dp[i + 1][j];
                }
                else if (p[i] == str[j])
                {
                    dp[i][j] = dp[i + 1][j + 1];
                }
                else
                {
                    dp[i][j] = false;
                }
            }
        }
    }
    return dp[0][0];
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    string str = "baaabab";
    string p = "ba*a?";
    cout << isMatch(str, p);
    return 0;
}