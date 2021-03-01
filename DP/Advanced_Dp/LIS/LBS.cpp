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

vi lis(vector<int> &arr)
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
    // cout << ma << " ";
    return dp;
}

void bitonic(vi &arr)
{
    // reverse(arr.begin(), arr.end());
    // vi dp_dec(arr.size(), 1);
    // lis from the beginning of the array
    vi dp_inc = lis(arr);
    reverse(arr.begin(), arr.end());
    vi dp_dec = lis(arr);
    reverse(dp_dec.begin(), dp_dec.end());

    // for (int i = 0; i < dp_inc.size(); i++)
    //     cout << dp_dec[i] << " ";
    int ma = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        ma = max(ma, dp_inc[i] + dp_dec[i]);
    }
    cout << ma - 1 << " ";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // vi arr = {12, 4, 78, 90, 45, 23};
    // vi arr = {16, 23, 74, 46, 24, 35, 92, 41, 48, 83, 64, 30, 56};

    vi arr = {15, 55, 39, 83, 28, 13, 14, 100, 32, 98, 13, 87, 12, 94, 39, 90};
    bitonic(arr);
    return 0;
}