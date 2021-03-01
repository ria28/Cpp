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

// https://leetcode.com/problems/distinct-subsequences-ii/

void distnSubse(string str)
{
    int n = str.size();
    vector<int> dp(n + 1);
    dp[0] = 1; // empty set
    unordered_map<char, int> map;
    int cnt = 0;
    for (int i = 1; i < dp.size(); i++)
    {
        dp[i] = (2 * dp[i - 1]) % 1000000007;
        if (map.find(str[i - 1]) != map.end())
        {
            int prevIdx = map[str[i - 1]];
            dp[i] = (dp[i] - dp[prevIdx - 1] + 1000000007) % 1000000007;
        }
        map[str[i - 1]] = i;
    }
    cout << dp[n] % 1000000007 << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // distnSubse("abcbac");
    distnSubse("zchmliaqdgvwncfatcfivphddpzjkgyygueikthqzyeeiebczqbqhdytkoawkehkbizdmcnilcjjlpoeoqqoqpswtqdpvszfaksn");
    return 0;
}