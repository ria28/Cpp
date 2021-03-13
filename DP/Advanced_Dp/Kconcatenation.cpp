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

int kadanes(vi &arr)
{
    int n = arr.size();
    int c_max = arr[0];
    int o_max_ = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (c_max >= 0)
        {
            c_max += arr[i];
        }
        else
        {
            c_max = arr[i];
        }
        // if (arr[i] < 0)
        // {
        //     c_max += arr[i];
        // }
        // else if (arr[i] > c_max)
        // {
        //     c_max = arr[i];
        // }
        // else
        // {
        //     c_max += arr[i];
        // }

        if (c_max > o_max_)
        {
            o_max_ = c_max;
        }
    }
    // cout << "o_max" << o_max_ << " ";
    return o_max_;
}

int kConcatenationMaxSum(vector<int> &arr, int k)
{
    int sum = 0;
    int n = arr.size();
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }

    int ans = 0;
    if (k == 1)
    {
        ans = kadanes(arr);

    }
    else
    {
        // arr.resize(2 * n);
        vi temp(2 * n);
        int i = 0;
        while (i < (2 * n))
        {
            temp[i] = arr[i % n];
            i++;
        }
        for (int i = 0; i < temp.size(); i++)
        {
            cout << temp[i] << " ";
        }
        cout << "\n";
        if (sum > 0)
        {
            int cnt = kadanes(temp);
            ans = cnt + (k - 2) * sum;
        }
        else
        {
            ans = kadanes(temp);
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi arr = {1, -1};
    int k = 1;
    cout << kConcatenationMaxSum(arr, k);
    return 0;
}