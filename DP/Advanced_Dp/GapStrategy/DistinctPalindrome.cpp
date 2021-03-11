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
#define vi vector<ll>
#define vii vector<vector<long long>>
#define MOD 1000000007

// https://leetcode.com/problems/count-different-palindromic-subsequences/

void fetch(vi &prev, vi &next, string s)
{
    ll n = s.size();
    unordered_map<char, ll> map;
    for (ll i = 0; i < n; i++)
    {
        if (map.find(s[i]) != map.end())
        {
            // cout<<s[i]<<"** ";
            prev[i] = map[s[i]];
            map[s[i]] = i;
            // cout<<prev[i]<<" ";
        }
        else
        {
            // cout<<s[i]<<">> ";
            prev[i] = -1;
            map[s[i]] = i;
            // cout<<prev[i]<<" ";
        }
    }
    // for (auto i : prev)
    //     cout << i << " ";

    map.clear();

    for (ll i = n - 1; i >= 0; i--)
    {
        if (map.find(s[i]) != map.end())
        {
            next[i] = map[s[i]];
            map[s[i]] = i;
        }
        else
        {
            next[i] = n;
            map[s[i]] = i;
        }
    }
    // for (auto i : next)
    //     cout << i << " ";
}

int countPalindromicSubsequences(string s)
{
    ll n = s.size();
    // fetch prev and net value index
    vi prev(n);
    vi next(n);

    fetch(prev, next, s);

    vii dp(n, vi(n));
    for (ll gap = 0; gap < n; gap++)
    {
        for (ll i = 0, j = gap; j < n; j++, i++)
        {
            if (gap == 0)
            {
                dp[i][j] = 1;
            }
            else if (gap == 1)
            {
                dp[i][j] = 2;
            }
            else
            {
                if (s[i] == s[j])
                {
                    if (next[i] > prev[j])
                    {
                        dp[i][j] = (2 * dp[i + 1][j - 1] + 2 + MOD) % MOD;
                    }
                    else if (next[i] == prev[j])
                    {
                        // cout << "hello"<<s.substr(i, gap);
                        dp[i][j] = (2 * dp[i + 1][j - 1] + 1 + MOD) % MOD;
                    }
                    else
                    {
                        dp[i][j] = (2 * dp[i + 1][j - 1] - dp[next[i] + 1][prev[j] - 1] + MOD) % MOD;
                    }
                }
                else
                {
                    dp[i][j] = (dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1] + MOD) % MOD;
                }
            }
        }
    }

    // for (int i = 0; i < dp.size(); i++)
    // {
    //     for (auto j : dp[i])
    //         cout << j << " ";
    //     cout << "\n";
    // }
    return dp[0][n - 1] % 1000000007;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str = "abacdaea";
    // b... ,b..b , .c.. , .cc. , bc.b , bccb  ==> 6
    cout << countPalindromicSubsequences(str);

    return 0;
}