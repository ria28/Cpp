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

class quad
{
public:
    int len;
    int idx;
    int val;
    string asf;
    quad(int l, int i, int v, string a)
    {
        this->len = l;
        this->idx = i;
        this->val = v;
        this->asf = a;
    }
};

void lis(vi &arr)
{
    int n = arr.size();
    vi dp(n);
    dp[0] = 1;
    int res_max = INT_MIN;
    int max_idx = 0;
    for (int i = 1; i < n; i++)
    {
        int max_ = INT_MIN;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i])
            {
                max_ = max(max_, dp[j]);
            }
        }
        dp[i] = max_ != INT_MIN ? max_ + 1 : 1;
        // res_max = max(res_max, dp[i]);
        if (res_max < dp[i])
        {
            res_max = dp[i];
            max_idx = i;
        }
    }

    cout << res_max << "\n";

    queue<quad> q;
    q.push(quad(res_max, max_idx, arr[max_idx], to_string(arr[max_idx])));
    while (q.size() > 0)
    {
        quad ele = q.front();
        q.pop();
        if (ele.len == 1)
        {
            cout << ele.asf << "\n";
            continue;
        }
        for (int i = 0; i < ele.idx; i++)
        {
            if (dp[i] == ele.len - 1 && arr[i] < ele.val)
            {
                q.push(quad(ele.len - 1, i, arr[i], to_string(arr[i]) + "->" + ele.asf));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // vector<int> arr = {10, 22, 42, 33, 21, 50, 41, 60, 80, 3};
    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    lis(arr);

    return 0;
}