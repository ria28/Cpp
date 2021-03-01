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

bool sortCols(vi &a, vi &b)
{
    return a[0] > b[0];
}

int maxEnvelopes(vector<vector<int>> &envelopes)
{
    sort(envelopes.begin(), envelopes.end(), sortCols);
    // for(auto i : envelopes)
    // cout<<i[0]<<" "<<i[1]<<"\n";
    vi dp(envelopes.size(), 0);
    dp[0] = 1;
    int max_all = INT_MIN;
    for (int i = 1; i < envelopes.size(); i++)
    {
        int max_ = INT_MIN;
        for (int j = i - 1; j >= 0; j--)
        {
            if (envelopes[j][0] > envelopes[i][0] && envelopes[j][1] > envelopes[i][1])
            {
                max_ = max(max_, dp[j]);
            }
        }
        dp[i] = max_ != INT_MIN ? max_+1 : 1;
        max_all = max(max_all, dp[i]);
    }
    return max_all;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vii envelope = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    cout << maxEnvelopes(envelope);
    return 0;
}