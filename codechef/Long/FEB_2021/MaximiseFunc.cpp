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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        ll ma = INT16_MIN;
        ll mi = INT16_MAX;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            mi = min(mi, arr[i]);
            ma = max(ma, arr[i]);
        }
        cout << 2 * (ma - mi) << "\n";
    }

    return 0;
}