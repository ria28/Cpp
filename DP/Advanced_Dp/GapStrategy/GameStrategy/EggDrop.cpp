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

void eggDrop(int f, int e)
{
    vii dp(e + 1, vi(f + 1, 0));
    for (int i = 0; i <= e; i++)
    {
        for (int j = 0; j <= f; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (i == 1)
            {
                dp[i][j] = j;
            }
            else if (j == 1)
            {
                dp[i][j] = 1;
            }
            else
            {
                int min_ = INT_MAX;
                for (int mj = j - 1, pj = 0; mj > 0; mj--, pj++)
                {
                    int val1 = dp[i][mj];     // egg survives
                    int val2 = dp[i - 1][pj]; // egg breaks
                    int val = max(val1, val2);

                    min_ = min(min_, val);
                }
                dp[i][j] = min_ + 1;
            }
        }
    }
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[0].size(); j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << dp[e][f];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int floor, eggs;
    // floor = 7;
    // eggs = 3;
    // ans for this is 3 abv

    cin >> eggs >> floor;
    eggDrop(floor, eggs);
    return 0;
}