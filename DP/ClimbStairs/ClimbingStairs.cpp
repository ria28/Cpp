#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;

// In these you can either go from 0 to nth stair or vice versa. But when jumps array is specified you can move only in a specific direction.

// jumps 1,2
// https://leetcode.com/problems/climbing-stairs/

//jumps are 1 ,2 ,3
void stairs_tab(ll n)
{
    vector<ll> tab(n + 1);
    tab[0] = 1;

    for (ll i = 1; i <= n; i++)
    {
        ll sum = 0;
        for (ll j = 3; j > 0; j--)
        {
            if (i - j >= 0)
            {
                sum += tab[i - j];
            }
        }
        tab[i] = sum;
    }
    cout << tab[n];
}

ll stairs_memo(ll n, vector<ll> &dp)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
        return 0;

    if (dp[n] != 0)
        return dp[n];
    ll step_1 = stairs_memo(n - 1, dp);
    ll step_2 = stairs_memo(n - 2, dp);
    ll step_3 = stairs_memo(n - 3, dp);

    ll step_n = step_1 + step_2 + step_3;
    dp[n] = step_n;
}

void stairs(ll n, string asf) // 1 2 or 3 steps
{
    if (n == 0)
    {
        cout << asf << " ";
        return;
    }

    if (n < 0)
        return;
    stairs(n - 1, asf + to_string(1));
    stairs(n - 2, asf + to_string(2));
    stairs(n - 3, asf + to_string(3));
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    ll n;
    cin >> n;
    // stairs(n, "");

    // vector<ll> dp(n + 1, 0);
    // stairs_memo(n, dp);
    // cout << dp[n] << "\n";

    stairs_tab(n);
    return 0;
}