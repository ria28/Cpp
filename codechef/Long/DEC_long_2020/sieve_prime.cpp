#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<bool> isPrime(n, true);
        vector<ll> pr;
        isPrime[0] = false;
        isPrime[1] = false;
        // isPrime[2]=true;
        pr.push_back(2);
        for (ll i = 4; i < n; i += 2)
        {
            isPrime[i] = false;
        }

        for (ll i = 3; i < n; i += 2)
        {
            if (isPrime[i])
            {
                pr.push_back(i);
                for (ll j = 3; i * j < n; j += 2)
                {
                    isPrime[i * j] = false;
                }
            }
        }

        for (ll i = 0; i < pr.size(); i++)
        {
            cout << pr[i] << "\n";
        }
    }
    return 0;
}