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


// https://leetcode.com/problems/word-break/

bool wordBreak(string str, vector<string> &dict)
{
    int n = dict.size();
    unordered_set<string> set;
    for (int i = 0; i < n; i++)
    {
        set.insert(dict[i]);
    }

    vi dp(str.size(), 0);
    for (int i = 0; i < str.size(); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            string sub = str.substr(j, i -j +1);
            // cout<<sub<<" ";
            if (set.find(sub) != set.end())
            {
                if (j > 0)
                {
                    dp[i] += dp[j - 1];
                }
                else
                {
                    dp[i] += 1;
                }
            }
        }
    }

    // for (int i : dp)
    //     cout << i << " ";
    return dp[str.size()-1]>0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<string> dict(n);
    for (int i = 0; i < n; i++)
    {
        cin >> dict[i];
        // set.insert(dict[i]);
    }
    string str;
    cin >> str;
    cout<<(boolalpha)<<wordBreak(str, dict);
    return 0;
}

/* 
    10
    pep
    loves
    coding
    pepcoding
    ice
    cream
    icecream
    man
    go
    mango
    pepcodinglovesmangoicecream 
*/