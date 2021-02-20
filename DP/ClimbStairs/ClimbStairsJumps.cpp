#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)

// when jumps array is specified you can move only in a specific direction.
// here move from 0 to 6. At 6th pos there is only 1 way.

void stairs_tab(ll n, vector<int> &jumps)
{
    vector<ll> tab(n + 1, 0);
    tab[n] = 1;
    for (int i = n-1; i >= 0; i--)
    {
        ll sum = 0;
        for (int j = jumps[i]; j > 0; j--)
        {
            if (j + i == n)
                sum++;
            if (j + i < n)
            {
                sum += tab[j + i];
            }
        }
        tab[i] = sum;
    }
    cout << tab[0];
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    ll n;
    cin >> n;
    vector<int> jumps(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> jumps[i];
    }
    
    stairs_tab(n, jumps);
    return 0;
}

// 6
// 3 3 0 2 2 3
// 3