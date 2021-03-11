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

// https://leetcode.com/problems/palindromic-substrings/submissions/

int countSubstrings(string s)
{
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    int cnt = 0;
    // diagonal traversal diagonals are basically gaps
    for (int gap = 0; gap < s.size(); gap++)
    {
        for (int i = 0, j = gap; j < s.size(); i++, j++)
        {
            if (gap == 0)
            {
                dp[i][j] = true;
                cnt++;
            }
            else if (gap == 1)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = true;
                    cnt++;
                }
                else
                    dp[i][j] = false;
            }
            else
            {
                // string substring = s.substr(i, gap + 1);
                // cout << substring << " ";
                if (s[i] == s[j] && dp[i + 1][j - 1] == true)
                {
                    dp[i][j] = true;
                    cnt++;
                }
                else
                {
                    dp[i][j] = false;
                }
            }
        }
    }
    return cnt;
}

// LONGEST PALINDROMIC SUBSTRING
// https://leetcode.com/problems/longest-palindromic-substring/
string longestPalindrome(string s)
{
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    string res = "";
    for (int gap = 0; gap < s.size(); gap++)
    {
        for (int i = 0, j = gap; j < s.size(); i++, j++)
        {
            if (gap == 0)
            {
                dp[i][j] = true;
            }
            else
            {
                if (gap == 1)
                {
                    if (s[i] == s[j])
                    {
                        dp[i][j] = true;
                    }
                    else
                    {
                        dp[i][j] = false;
                    }
                }
                else
                {
                    if (s[i] == s[j] && dp[i + 1][j - 1])
                        dp[i][j] = true;
                    else
                        dp[i][j] = false;
                }
            }
            if (dp[i][j])
            {
                res = s.substr(i, gap + 1);
            }
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // string str = "abccbc";
    // string str = "aba";
    // cout << countSubstrings(str);

    string str = "cbbd";
    cout << longestPalindrome(str);

    return 0;
}