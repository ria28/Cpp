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
    int i, target;
    string asf;
    tri(int i, int tar, string asf)
    {
        this->i = i;
        this->target = tar;
        this->asf = asf;
    }
};

void subset(vi &arr, int sum, int n)
{
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (j == 0)
                dp[i][j] = true;
            else if (i == 0)
                dp[i][j] = false;
            else
            {
                if (dp[i - 1][j] == true)
                    dp[i][j] = true;
                else
                {
                    int val = arr[i - 1];
                    if (val <= j)
                        if (dp[i - 1][j - val] == true)
                            dp[i][j] = true;
                }
            }
        }
    }

    for (int i = 0; i < dp.size(); i++)
    {
        for (auto j : dp[i])
            cout << j << " ";
        cout << "\n";
    }

    cout << (boolalpha) << dp[n][sum] << "\n";

    // PRINTING ===================================================
    queue<tri> q;
    q.push(tri(n, sum, ""));
    while ((q.size()))
    {
        tri ele = q.front();
        q.pop();

        if (ele.i == 0 && ele.target == 0)
        {
            cout << ele.asf << "\n";
        }
        else
        { // cout << arr[ele.i-1] << ele.target << "->" << dp[ele.i][ele.target] << "\n";
            if (dp[ele.i - 1][ele.target] == true)
            {
                q.push(tri(ele.i - 1, ele.target, ele.asf));
            }

            // cout << ele.target << " " << arr[ele.i - 1] << "\n";
            if (ele.target >= arr[ele.i - 1])
            {
                // cout << ele.i - 1<< ele.target - arr[ele.i - 1]<< ele.asf + to_string(arr[ele.i - 1])<< " ---";
                if (dp[ele.i - 1][ele.target - arr[ele.i - 1]] == true)
                    q.push(tri(ele.i - 1, ele.target - arr[ele.i - 1], ele.asf + to_string(arr[ele.i - 1])));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, sum;
    // for(int i =0;i<n;i++)
    // {

    // }
    n = 5;
    sum = 10;

    vi arr = {4, 2, 7, 1, 3};
    subset(arr, sum, n);

    return 0;
}

/* 
    5
    4 2 7 1 3
    10
    1 0 0 0 0 0 0 0 0 0 0 
    1 0 0 0 1 0 0 0 0 0 0 
    1 0 1 0 1 0 1 0 0 0 0
    1 0 1 0 1 0 1 1 0 1 0
    1 1 1 1 1 1 1 1 1 1 1
    1 1 1 1 1 1 1 1 1 1 1
    true 
*/