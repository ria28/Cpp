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

void kadanes(vi &arr, int n, int k)
{
    int ans = INT_MIN;
    int curr_sum = arr[0];
    vi maxSum(n, 0);
    maxSum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (curr_sum < 0)
        {
            curr_sum = arr[i];
        }
        else
        {
            curr_sum += arr[i];
        }
        maxSum[i] = curr_sum;
    }

    int exactK = 0;
    for (int i = 0; i < k; i++)
    {
        exactK += arr[i];
    }

    ans = max(ans, exactK);

    int moreThanK = 0;
    for (int i = k; i < arr.size(); i++)
    {
        exactK += arr[i] - arr[i - k];
        ans = max(ans, exactK);
        moreThanK = exactK + maxSum[i-k];
        ans = max(ans , moreThanK);
    }

    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vi arr = {1,2,3};
    int k=2;
    kadanes(arr, arr.size(), k);
    return 0;
}