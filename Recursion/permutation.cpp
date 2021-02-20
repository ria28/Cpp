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

// https://leetcode.com/problems/permutations/
vector<vector<int>> ans;
void perm(vector<int> &nums, vector<int> &asf, vector<bool> &vis)
{
    if (asf.size() == nums.size())
    {
        ans.push_back(asf);
        // asf.clear();
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (!vis[i])
        {
            // cout<<nums[i]<<" ";
            vis[i] = true;
            asf.push_back(nums[i]);
            perm(nums, asf, vis);
            asf.pop_back();
            vis[i] = false;
        }
    }
}

vector<vector<int>> permute(vector<int> &nums)
{

    vector<int> asf;
    vector<bool> vis(nums.size(), false);
    perm(nums, asf, vis);
    return ans;
}

void recursion(vector<int> num, int i, int j, vector<vector<int>> &res)
{
    if (i == j - 1)
    {
        res.push_back(num);
        return;
    }
    for (int k = i; k < j; k++)
    {
        if (i != k && num[i] == num[k])
            continue;
        swap(num[i], num[k]);
        recursion(num, i + 1, j, res);
    }
}
vector<vector<int>> permuteUnique(vector<int> &num)
{
    sort(num.begin(), num.end());

    vector<vector<int>> res;
    recursion(num, 0, num.size(), res);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums = {1, 1, 2};
    // vector<vector<int>> arr = permute(nums);
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     for (auto j : arr[i])
    //     {
    //         cout << j << " ";
    //     }
    //     cout << "\n";
    // }

    // duplicacy
    // the above code will generate
    /*  1 1 2 
        1 2 1 
        1 1 2 
        1 2 1 
        2 1 1 
        2 1 1  

        but we want 
        [[1,1,2],
        [1,2,1],
        [2,1,1]]

    */
    // THIS WILL HANDLE ALL THE CASES
    vector<int> num = {1, 1, 2};
    vector<vector<int>> arr = permuteUnique(num);
    for (int i = 0; i < arr.size(); i++)
    {
        for (auto j : arr[i])
        {
            cout << j << " ";
        }
        cout << "\n";
    }

    return 0;
}