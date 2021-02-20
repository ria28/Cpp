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

// from n to n there is 0 move but 1 path

void steps_tab(ll n, vector<ll> &jumps)
{
    vector<ll> tab(n + 1);
    tab[n] = 0; // we are calc moves 
    for (ll i = n - 1; i >= 0; i--)
    {
        ll mi = INT_MAX;
        for (ll j = jumps[i]; j > 0; j--)
        {
            if (i + j > n)
                continue;
            mi = min(mi, tab[i + j]);
        }
        tab[i] = mi+1;
    }
    cout << tab[0];
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    ll n;
    cin >> n;
    vector<ll> jumps(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> jumps[i];
    }
    steps_tab(n, jumps);
    return 0;
}

// 6
// 3 3 0 2 2 3
// 3