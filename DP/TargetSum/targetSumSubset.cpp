#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)

// SUBSET IS NOT CONTIGUOUS WHEREAS SUBARRAY IS CONTIGUOUS / CONTINUOUS
bool IsSubset(int n, vector<int> &arr, int target)
{
    vector<vector<bool>> dp(n+1, vector<bool>(target + 1, false));
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[0].size(); j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = true;
            else if (j == 0)
                dp[i][j] = true;
            else if (i == 0)
                dp[i][j] = false;
            else
            {
                if (dp[i - 1][j] == true)
                    dp[i][j] = true;
                else
                {
                    int val = arr[i - 1]; // coz dp starts with 0 being empty and 1 -->4(arr[0]) , 2--> 2(arr[1]), 3--> 7(arr[2]) , 4 -->1(arr[3])
                    if (val <= j)
                    {
                        if (dp[i - 1][j - val] == true)
                            dp[i][j] = true;
                    }
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

    cout << (boolalpha) << dp[n][target];
}

// n numbers subset = 2^n ...every ele as 2 choice either it'll come or not
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    ll target;
    cin >> target;
    IsSubset(n, arr, target);
    return 0;
}


/* 
    5
    4 2 7 1 3
    10
    1 0 0 0 0 0 0 0 0 0 0 
    1 0 0 0 1 0 0 0 0 0 0 
    1 0 1 0 1 0 1 0 0 0 0
    1 0 1 0 1 0 1 1 0 1 0
    1 1 1 1 1 1 1 1 1 1 1
    1 1 1 1 1 1 1 1 1 1 1
    true 
*/