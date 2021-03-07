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

// O(N^3)
int minCut_2(string s)
{
    // make a dp boolean array for palin
    int n = s.size();
    vector<vector<bool>> palin(n, vector<bool>(n, false));
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; j++, i++)
        {
            if (gap == 0)
            {
                palin[i][j] = true;
            }
            else if (gap == 1)
            {
                if (s[i] == s[j])
                    palin[i][j] = true;
                else
                    palin[i][j] = false;
            }
            else
            {
                if (s[i] == s[j] && palin[i + 1][j - 1])
                {
                    palin[i][j] = true;
                }
                else
                {
                    palin[i][j] = false;
                }
            }
        }
    }

    // for (int i = 0; i < palin.size(); i++)
    // {
    //     for (auto j : palin[i])
    //         cout << j << " ";
    //     cout << "\n";
    // }

    vii dp(n, vi(n, 0));
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; j++, i++)
        {
            if (gap == 0)
            {
                dp[i][j] = 0;
            }
            else if (gap == 1)
            {
                if (s[i] == s[j])
                    dp[i][j] = 0;
                else
                    dp[i][j] = 1;
            }
            else
            {
                if (palin[i][j])
                {
                    dp[i][j] = 0;
                }
                else
                {
                    int mi = INT_MAX;
                    for (int k = i; k < j; k++)
                    {
                        int left = dp[i][k];
                        int right = dp[k + 1][j];
                        mi = min(mi, left + right);
                    }
                    dp[i][j] = mi + 1;
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

    return dp[0][n - 1];
}

// O(N^2)---------
int minCut(string s)
{
    // make a dp boolean array for palin
    int n = s.size();
    vector<vector<bool>> palin(n, vector<bool>(n, false));
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; j++, i++)
        {
            if (gap == 0)
            {
                palin[i][j] = true;
            }
            else if (gap == 1)
            {
                if (s[i] == s[j])
                    palin[i][j] = true;
                else
                    palin[i][j] = false;
            }
            else
            {
                if (s[i] == s[j] && palin[i + 1][j - 1])
                {
                    palin[i][j] = true;
                }
                else
                {
                    palin[i][j] = false;
                }
            }
        }
    }

    // for (int i = 0; i < palin.size(); i++)
    // {
    //     for (auto j : palin[i])
    //         cout << j << " ";
    //     cout << "\n";
    // }

    // vii dp(n, vi(n, 0));
    vi dp(n, 0);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        if (palin[0][i])
        {
            dp[i] = 0;
        }
        else
        {
            int min_ = INT_MAX;
            for (int j = i; j >= 1; j--) // not 0 coz that wil cover the whole string not suffix
            {
                string sub = s.substr(j, j - i + 1);
                if (palin[j][i]) // suffix is palindrome
                {
                    if (dp[j - 1] < min_)
                    {
                        min_ = dp[j - 1];
                    }
                }
            }
            dp[i] = min_ + 1;
        }
    }

    for (int i = 0; i < dp.size(); i++)
    {
        // for (auto j : [i])
            cout << dp[i] << " ";

        cout << "\n";
    }

    return dp[n - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str = "abccbc";
    cout<<minCut(str);
    return 0;
}