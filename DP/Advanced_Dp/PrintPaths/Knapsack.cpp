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

class tri
{
public:
    int i, j;
    string asf;
    tri(int i, int j, string asf)
    {
        this->i = i;
        this->j = j;
        this->asf = asf;
    }
};

void knap(int n, vi &profit, vi &wt, int capacity)
{
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[0].size(); j++)
        {
            if (wt[i - 1] <= j)
            {
                // cout<<wt[i]<<" ";
                int new_pro = profit[i - 1] + dp[i - 1][j - wt[i - 1]];
                dp[i][j] = max(dp[i - 1][j], new_pro);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for (int i = 0; i < dp.size(); i++)
    {
        for (auto j : dp[i])
            cout << j << " ";
        cout << "\n";
    }
    cout << dp[n][capacity] << "\n";

    queue<tri> q;
    q.push(tri(n, capacity, ""));
    while (q.size() > 0)
    {
        tri ele = q.front();
        q.pop();
        // cout << ele.i << " " << ele.j << "\n";
        if (ele.i == 0 || ele.j == 0)
        {
            cout << ele.asf << "\n";
        }
        else
        {
            if (dp[ele.i - 1][ele.j] == dp[ele.i][ele.j])
            {
                q.push(tri(ele.i - 1, ele.j, ele.asf));
            }

            if (ele.j >= wt[ele.i - 1])
            {
                // cout << dp[ele.i - 1][ele.j - wt[ele.i - 1]] << "yyy" << wt[ele.i - 1] << "[[[" << dp[ele.i][ele.j] << "\n";
                if (dp[ele.i - 1][ele.j - wt[ele.i - 1]] + profit[ele.i - 1] == dp[ele.i][ele.j])
                    q.push(tri(ele.i - 1, ele.j - wt[ele.i - 1], ele.asf + to_string(profit[ele.i - 1]) + " "));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 5;
    vi value = {15, 14, 10, 45, 30};
    vi weight = {2, 5, 1, 3, 4};
    int max_ = 7;
    knap(n, value, weight, max_);
    return 0;
}