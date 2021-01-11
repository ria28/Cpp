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
    int t, n, lo, hi;
    cin >> t;
    while (t--)
    {
        cin >> n >> lo >> hi;
        vector<ll> a(n);
        ll sum = 0;
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
            if (sum >= lo && sum <= hi)
                flag = true;
            // if (a[i] >= lo && a[i] <= hi)
            //     flag = true;
        }
        if (flag)
        {
            cout << 0 << "\n";
            continue;
        }
        if (sum < lo)
        {
            cout << -1 << "\n";
            continue;
        }
        ll temp = sum;

        for (ll i = 0; i < n; i++)
        {
            sum -= a[i];
            if (sum >= lo && sum <= hi)
            {
                flag = true;
                break;
            }
            sum += a[i];
        }
        if (flag)
        {
            cout << 1 << "\n";
            continue;
        }

        sum = temp;
        for (ll i = 0; i < n; i++)
        {
            if (flag)
                break;
            sum -= a[i];
            for (ll j = i + 1; j < n; j++)
            {
                sum -= a[j];
                if (sum >= lo && sum <= hi)
                {
                    flag = true;
                    break;
                }
                sum += a[j];
            }
            sum += a[i];
        }

        if (flag)
        {
            cout << 2 << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }

        // for (ll i = 0; i < n; i++)
        // {
        //     if (flag)
        //         break;
        //     sum -= a[i];
        //     for (ll j = i + 1; j < n; j++)
        //     {
        //         // sum += a[j];
        //         if (sum >= lo && sum <= hi)
        //         {
        //             flag = true;
        //             break;
        //         }
        //         // sum -= a[j];
        //     }
        //     sum += a[i];
        // }
        // if (flag)
        // {
        //     cout << 1 << "\n";
        // }
        // else
        // {
        //     cout << 2 << "\n";
        // }
    }
    return 0;
}