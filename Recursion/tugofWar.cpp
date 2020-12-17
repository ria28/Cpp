#include <iostream>
#include <unordered_set>
#include <stack>
#include <vector>
#include <string>
using namespace std;

static string ans = "";
static int min_diff = INT32_MAX;
void solve(vector<int> &arr, int idx, vector<int> &set1, vector<int> &set2, int sum_1, int sum_2)
{
    cout << idx;
    if (idx == arr.size())
    {
        // cout<<"diekjbqe";

        int diff = abs(sum_1 - sum_2);
        if (diff < min_diff)
        {
            min_diff = diff;
            for (auto i : set1)
            {
                ans += to_string(i);
            }
            ans += "  ";
            for (auto i : set2)
            {
                ans += to_string(i);
            }
            // cout << ans << "\n";

           
        }
        return;
    }

    if (set1.size() < (arr.size() + 1) / 2)
    {
        // cout<<"vwiewlje";
        set1.push_back(arr[idx]);
        solve(arr, idx + 1, set1, set2, sum_1 + arr[idx], sum_2);
        set1.erase(set1.begin() + idx);
    }

    if (set2.size() < (arr.size() + 1) / 2)
    {
        set2.push_back(arr[idx]);
        solve(arr, idx + 1, set1, set2, sum_1, sum_2 + arr[idx]);
        set2.erase(set2.begin() + idx);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // 2 sets such that they have min difference of the sum of elements in both the sets
    vector<int> set1;
    vector<int> set2;
    solve(arr, 0, set1, set2, 0, 0);
    cout << ans;
    return 0;
}