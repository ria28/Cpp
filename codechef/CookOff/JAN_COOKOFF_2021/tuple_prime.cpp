#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#define ll long long
using namespace std;

void manipulated_seive(int N, vector<ll> &ans)
{
    vector<long long> isprime(N+1, true);
    vector<long long> prime;
    vector<long long> SPF(N+1);
    isprime[0] = isprime[1] = false;
    ll store = 0;
    for (long long int i = 2; i < N; i++)
    {
        if (isprime[i])
        {
            if (i != 2)
            {
                if (i - store == 2)
                    ans.push_back(i);
            }
            prime.push_back(i);
            store = i;
            SPF[i] = i;
        }
        for (long long int j = 0;
             j < (int)prime.size() &&
             i * prime[j] < N && prime[j] <= SPF[i];
             j++)
        {
            isprime[i * prime[j]] = false;

            SPF[i * prime[j]] = prime[j];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        // vector<ll> primes = SieveOfEratosthenes(n);
        vector<ll> ans;

        manipulated_seive(n, ans);
        // for (int i = 0; i < prime.size() && prime[i] <= n; i++)
        //     cout << prime[i] << " ";
        // ll cnt = 0;
        // ll i = 0, j = 1;

        // for (ll c = 1; c < prime.size(); c++)
        // {
        //     ll sum = 2 + prime[c];
        //     if (prime[sum] && sum <= n)
        //     {
        //         cnt++;
        //     }
        // }
        cout << ans.size() << "\n";

        // for (auto i : ans)
        //     cout << i << " ";
    }
    return 0;
}