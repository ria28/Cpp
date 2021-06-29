#include <bits/stdc++.h>
#define ll long long
using namespace std;

// unordered_set<long long>set_;
bool primes[1000005];
void seives(ll n)
{
    memset(primes, true, sizeof(primes));
    primes[0] = 0;
    primes[1] = 0;

    for (int i = 2; i * i < 1000005; i++)
    {
        if (primes[i])
        {
            for (int j = i * i; j < 1000005; j += i)
            {
                primes[j] = 0;
            }
        }
    }
}

bool digi(ll n)
{
    ll cnt = 0;
    while (n)
    {
        ll rem = n % 10;
        n = n / 10;
        cnt += rem;
    }
    return primes[cnt];
}

int ans[1000005];

int main()
{
    seives(1000005);
    memset(ans, 0, sizeof(ans));
    int curr = 0;
    for (int i = 0; i < 1000005; i++)
    {
        if (primes[i] && digi(i))
            curr++;
        ans[i] = curr;
    }
    int t;
    scanf("%u", &t);
    while (t--)
    {
        int l, u;
        scanf("%u %u", &l, &u);
        ll cnt = 0;

        cnt = ans[u] - ans[l - 1];

        printf("%d\n", cnt);
    }
}