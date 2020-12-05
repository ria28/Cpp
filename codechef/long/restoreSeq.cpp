#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define ll long long
using namespace std;

vector<ll> prime(ll n)
{
    vector<bool> pr(n + 1, true);
    vector<ll> vect;
    // memset(pr, true, sizeof(pr));

    for (ll p = 2; p * p <= n; p++)
    {

        if (pr[p] == true)
        {

            for (ll i = p * p; i <= n; i += p)
                pr[i] = false;
        }
    }

    for (ll p = 2; p <= n; p++)
        if (pr[p])
            vect.push_back(p);
    return vect;
}
int main()
{
    ll t;
    cin >> t;
    ll N = 10000000;
    vector<ll> pr = prime(N);
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> b(n);
        // vector<ll> a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> b[i];
            cout << pr[b[i]] << " ";
            // a.push_back(pr[b[i]]);
        }
        cout << "\n";
        // for (ll i = 0; i < n; i++)
        // {
        //     cout << a[i] << " ";
        // }
    }
    return 0;
}