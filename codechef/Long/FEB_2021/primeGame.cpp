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

vector<int> primes(1000001);
bool isprime(ll n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}
void countPrimes()
{
    primes[0] = 0;
    primes[1] = 0;
    int count = 0;
    for (int i = 2; i < 1000001; i++)
    {
        if (isprime(i))
            count++;
        primes[i] = count;
    }
}
void solve()
{
    ll n, k;
    cin >> n >> k;
    primes[n] > k ? cout << "Divyam\n" : cout << "Chef\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    countPrimes();
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}