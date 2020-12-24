#include <iostream>
#include <unordered_map>
#include<math.h>
#define ll long long
using namespace std;
pair<ll, ll> co_prime(ll num1, ll num2)
{
    // cout << num1 << " " << num2 << "\n";
    ll hcf;
    for (ll i = 1; i <= sqrt(num1); i++)
    {
        if (num1 % i == 0 && num2 % i == 0)
        {
            hcf = i;
        }
    }
    pair<ll, ll> p;
    p.first = num1 / hcf;
    p.second = num2 / hcf;
    // cout<<p.first<<","<<p.second;
    return p;
}
int main()
{
    ll n;
    cin >> n;
    ll cnt = 0;
    for (ll i = 1; i <= n - 1; i++)
    {
        for (ll j = i + 1; j <= n; j++)
        {
            // cout << i << "," << j << " ";
            // if (co_prime(((i * j) + i), ((i * j) + j)))
            // {
            //     cnt++;
            // cout << i << "," << j << " ";
            // }
            pair<ll, ll> p = co_prime(((i * j) + i), ((i * j) + j));
            if (p.first < i && p.second < j)
                continue;
            if (p.first + 1 == p.second)
            {
                cnt++;
                // cout << i << "," << j << " ";
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}
