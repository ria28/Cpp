#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <math.h>
#define ll long long
using namespace std;
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)
#define vi vector<int>
#define vii vector<vector<int>>
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    ll cnt_odds = 0;
    if (n & 1) // odd
    {
        cnt_odds = ceil(n / 2.0);
    }
    else
    {
        cnt_odds = n / 2;
    }
    ll ans;
    if (k <= cnt_odds)
    {
        cout << 2 * k - 1 << "\n";
    }
    else
        cout << 2 * (k - cnt_odds) << "\n";

    return 0;
}