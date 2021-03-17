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

// https://leetcode.com/problems/arithmetic-slices/
int numberOfArithmeticSlices_1(vector<int> &nums)
{
    int n = nums.size();
    vi dp(n, 0);
    int sum = 0;
    for (int i = 2; i < n; i++)
    {
        if (nums[i] + nums[i - 2] == 2 * nums[i - 1])
        {
            dp[i] = dp[i - 1] + 1;
        }
        sum += dp[i];
    }
    return sum;
}

// https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
int numberOfArithmeticSlices(vector<int> &arr)
{
    vector<unordered_map<int, int>> map(arr.size());
    int n = arr.size();
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int cd = arr[i] - arr[j]; //
            map[i][cd] += 1;          //  increment if the diff was already present or not

            if (map[j].find(cd) != map[j].end())
            {
                map[i][cd] += map[j][cd];
                res += map[j][cd];
            }
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vi arr = {2, 5, 9, 12, 15, 18, 22, 26, 30, 34, 36};
    // cout << numberOfArithmeticSlices_1(arr);
    vi arr2 = {4, 2, 3, 5, 2, 6, 7, 9, 8, 11};
    numberOfArithmeticSlices(arr2);
    return 0;
}