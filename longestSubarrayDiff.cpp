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

vi func(vi no, int k)
{
    vi dp(no.size());
    dp[0] = 1;
    int max_ = INT_MIN;
    int beg = 0;
    int end = 0;
    vi ans;
    for (int i = 1; i < no.size(); i++)
    {
        if (abs(no[i] - no[i - 1]) <= k)
        {
            dp[i] = dp[i - 1] + 1;
            end = i;
        }
        else
        {
            // ans.clear();
            ans.push_back(beg);
            ans.push_back(end);
            beg = i;
            end = i;
            dp[i] = 1;
        }
        if (max_ < dp[i])
        {
            max_ = dp[i];
            end = i;
        }
        // max_ = max(max_, dp[i]);
    }
    ans.push_back(beg);
    ans.push_back(end);
    vi final_ans;
    // for (int i : dp)
    //     cout << i << " ";
    int start = INT_MAX;
    int end_;
    for (int i = 2; i < ans.size(); i + 2)
    {
        if (dp[ans[i] - 1] == dp[ans[i] + 1])
        {
            start = min(start, min(ans[i], ans[i - 1]));
            end_ = ans[i + 1];
        }
        else
        {
            if(dp[i-1]>dp[i+1])
            {
                start = ans[i-2];
                end_ = ans[i+1];
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vi arr = {-1, 4, 6, 2, 8, 4, 7, 12};
    func(arr, 5);
    return 0;
}