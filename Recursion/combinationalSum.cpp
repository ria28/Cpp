#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;

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
    sort(arr.begin(), arr.end());
    // combSum_with_rep(arr, sum, "", 0);
    // combSum_without_rep(arr, sum, "", 0);
    // combSum_Perm_rep(arr, sum, "");
    vector<bool> vis(n, false);
    comvSum_Perm_without_rep(arr, vis, sum, "");

    return 0;
}