#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;

void print(vector<vector<int>> &ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}

void comvSum_Perm_without_rep(vector<int> &arr, vector<bool> &vis, int sum, string asf)
{
    if (sum == 0)
    {
        cout << asf << "\n";
        return;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= sum && !vis[i])
        {
            vis[i] = true;
            comvSum_Perm_without_rep(arr, vis, sum - arr[i], asf + to_string(arr[i]));
            vis[i] = false;
        }
    }
}

void combSum_Perm_rep(vector<int> &arr, int sum, string asf)
{
    if (sum == 0)
    {
        cout << asf << "\n";
        return;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= sum)
        {
            combSum_Perm_rep(arr, sum - arr[i], asf + to_string(arr[i]));
        }
    }
}

void combSum_without_rep(vector<int> &arr, int sum, string asf, int idx)
{
    if (sum == 0)
    {
        cout << asf << "\n";
        return;
    }

    for (int i = idx; i < arr.size(); i++)
    {
        if (i > idx && arr[i - 1] == arr[i])
            continue;
        if (arr[i] <= sum)
        {
            combSum_without_rep(arr, sum - arr[i], asf + to_string(arr[i]), i + 1);
        }
    }
}

void combSum_with_rep(vector<int> &arr, int sum, string asf, int idx)
{
    if (sum == 0)
    {
        cout << asf << "\n";
        return;
    }

    for (int i = idx; i < arr.size(); i++)
    {
        if (arr[i] <= sum)
        {
            combSum_with_rep(arr, sum - arr[i], asf + to_string(arr[i]), i);
        }
    }
}

// ------------------------------   LEETCODE -------------------------------------------------------

//https://leetcode.com/problems/combination-sum-iii/
void comb3(int k, int start, int n, vector<vector<int>> &ans, vector<int> &a)
{
    if (a.size() == k && n == 0)
    {
        ans.push_back(a);
        return;
    }
    for (int i = start; i <= 9; i++)
    {
        a.push_back(i);
        comb3(k, i + 1, n-i, ans, a);
        a.pop_back();
    }
}


//https://leetcode.com/problems/combination-sum-ii/
// arr : 10,1,2,7,6,1,5  , target:8 
/* [
    [1,1,6],
    [1,2,5],
    [1,7],
    [2,6]
    ] 
*/ 
// sorting reqd.
void combSum_without_rep_leet(vector<int> &arr, int sum, vector<int> &a, int idx, vector<vector<int>> &ans)
{
    if (sum == 0)
    {
        // cout << asf << "\n";
        ans.push_back(a);
        return;
    }

    for (int i = idx; i < arr.size(); i++)
    {
        if (i > idx && arr[i - 1] == arr[i])
            continue;
        if (arr[i] <= sum)
        {
            a.push_back(arr[i]);
            combSum_without_rep_leet(arr, sum - arr[i], a, i + 1, ans);
            a.pop_back();
        }
    }
}

void combSum_with_rep_leet(vector<int> &arr, int sum, vector<int> &a, int idx, vector<vector<int>> &ans)
{
    if (sum == 0)
    {
        // cout << asf << "\n";
        ans.push_back(a);
        return;
    }

    for (int i = idx; i < arr.size(); i++)
    {
        if (arr[i] <= sum)
        {
            a.push_back(arr[i]);
            combSum_with_rep_leet(arr, sum - arr[i], a, i, ans);
            a.pop_back();
        }
    }
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    // 2 4 6 8
    // 8

    int n, sum;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> sum;
    // sort(arr.begin(), arr.end());
    // combSum_with_rep(arr, sum, "", 0);
    // combSum_without_rep(arr, sum, "", 0);
    combSum_Perm_rep(arr, sum, "");

    vector<bool> vis(n, false);
    comvSum_Perm_without_rep(arr, vis, sum, "");

    // -----------------------------    LEETCODE  ------------------------------------------------

    // https://leetcode.com/problems/combination-sum/submissions/
    // vector<int> a;
    // vector<vector<int>> ans;
    // // combSum_with_rep_leet(arr, sum, a, 0, ans);
    // // print(ans);

    // combSum_without_rep_leet(arr,sum,a,0,ans);
    // print(ans);

    // int n, k;
    // cin >> n >> k;
    //  k : size of the subset that make sum 'n'  , n is the required sum that we want  the subset to have

    // vector<vector<int>> ans;
    // vector<int> a;
    // comb3(k, 1, n, ans, a);
    // print(ans);

    return 0;
}