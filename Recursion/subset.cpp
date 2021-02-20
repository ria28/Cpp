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

// https://leetcode.com/problems/subsets/
void sub(vector<int> &arr, vector<int> &asf, vector<vector<int>> &res, int idx)
{
    // if(idx>arr.size())
    //     return;

    res.push_back(asf);

    for (int i = idx; i < arr.size(); i++)
    {
        if (i != idx && arr[i] == arr[idx])
            continue;
        asf.push_back(arr[i]);
        sub(arr, asf, res, i + 1);
        asf.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<int> asf;
    vector<vector<int>> res;
    sub(nums, asf, res, 0);
    return res;
}

// https://leetcode.com/problems/subsets-ii/

void sub_(vector<int> &arr, vector<int> &asf, vector<vector<int>> &res, int idx)
{
    // if(idx>arr.size())
    //     return;

    res.push_back(asf);

    for (int i = idx; i < arr.size(); i++)
    {
        if (i != idx && arr[i] == arr[i - 1])
            continue;
        asf.push_back(arr[i]);
        sub_(arr, asf, res, i + 1);
        asf.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    // whenever duplicacy --> sort
    sort(nums.begin(), nums.end());
    vector<int> asf;
    vector<vector<int>> res;
    sub_(nums, asf, res, 0);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // vector<int> nums = {1, 2, 3};
    // auto res = subsets(nums);

    // for (int i = 0; i < res.size(); i++)
    // {
    //     for (int j : res[i])
    //     {
    //         cout << j << "";
    //     }
    //     cout << "\n";
    // }

    vector<int> nums = {1, 2, 2};
    auto res = subsetsWithDup(nums);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j : res[i])
        {
            cout << j << "";
        }
        cout << "\n";
    }

    return 0;
}