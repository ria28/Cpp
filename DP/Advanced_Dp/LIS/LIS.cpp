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

void lis(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 1);
    dp[0] = 1;
    int ma = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
        // cout << dp[i] << "\n";
        ma = max(ma, dp[i]);
    }
    cout << ma << " ";
}

void max_lis_sum(vi &arr)
{
    vi dp(arr.size());
    dp[0] = arr[0];
    int ma = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        dp[i] = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[i] > arr[j])
            {
                
                dp[i] = max(arr[i] + dp[j], dp[i]);
            }
            // cout<<arr[i]<<"-> "<<dp[i]<<" ";
        }
        // cout << dp[i] << "\n";
        ma = max(ma, dp[i]);
    }
    cout << ma << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    vi arr = {10, 20, 30, 40};
    lis(arr);
    // max_lis_sum(arr);
    return 0;
}