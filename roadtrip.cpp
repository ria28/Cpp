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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        vector<ll> arr(n + 1, 0);
        ll steps = 0;
        ll start = INT_MIN;
        ll start_i = 0;
        for (ll i = 1; i <= n; i++)
        {

            cin >> arr[i];
        }
        for (ll i = 1; i <= x; i++)
        {
            if (start < arr[i])
            {
                start = arr[i];
                start_i = i;
            }
        }
        // cout<<start_i<<"<--";
        res.push_back(start_i);
        steps++;
        ll idx = 0;
        bool bk = false;
        for (ll i = start_i; i <= n;)
        {
            cout<<i<<" ";
            ll ma = INT_MIN;
            for (ll j = arr[start_i]; j > 0; j--)
            {
                if (i + j > n)
                {
                    bk = true;
                    break;
                }
                // if (i + j <= n)
                if (ma < arr[i + j])
                {
                    ma = arr[i + j];
                    idx = i + j;
                }
            }
            if (bk)
                break;
            // cout << idx << " --";
            steps++;
            res.push_back(idx);
            i = idx;
        }
        res.pop_back();
        cout << steps-1 << "\n";
        for (ll i = 1; i <= n; i++)
        {
            cout << res[i] << " ";
        }
    }

    return 0;
}