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

void mcm(vi &arr)
{
    int n = arr.size()-1;
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
                dp[i][j] = arr[i] * arr[j + 1] * arr[j]; // or the last one can be arr[i+1]
            }
            else
            {
                int mi = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    // dp --> left : (i,k)  right : (k+1 , j)
                    // array --> left : (i , k +1 ),  right : (k+1 , j+1)
                    int left = dp[i][k];
                    int right = dp[k + 1][j];
                    int mulFactor = arr[i] * arr[k + 1] * arr[j + 1];
                    int totalcost = left + right + mulFactor;
                    mi = min(mi, totalcost);
                }
                dp[i][j] = mi;
            }
        }
    }

    cout << dp[0][dp.size()-1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // vi arr = {10, 20, 30, 40, 50, 60};
    vi arr = {3,1,2,3};
    mcm(arr);
    return 0;
}