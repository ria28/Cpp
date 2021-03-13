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

void keypad(int n)
{

    vii store(10);
    store[0] = {0, 8};
    store[1] = {1, 2, 4};
    store[2] = {1, 2, 3, 5};
    store[3] = {2, 3, 6};
    store[4] = {1, 4, 5, 7};
    store[5] = {2, 4, 5, 6, 8};
    store[6] = {3, 5, 6, 9};
    store[7] = {4, 7, 8};
    store[8] = {0, 5, 7, 8, 9};
    store[9] = {6, 8, 9};
    vii dp(n + 1, vi(10, 0));
    for (int i = 0; i < 10; i++)
        dp[1][i] = 1;
    for (int i = 2; i < n + 1; i++)
    {
        int sum = 0;
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < store[j].size(); k++)
            {
                dp[i][j] += dp[i - 1][store[j][k]];
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 10; i++)
    {
        ans += dp[n][i];
    }

    cout << ans << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    keypad(2);
    return 0;
}