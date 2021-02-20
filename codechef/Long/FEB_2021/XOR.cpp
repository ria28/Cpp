#include <vector>
#include <cstdio>

using namespace std;
#define ll long long

ll mod = 998244353;
const ll max__ = 1 << 19, M = 998244353;
ll inv_fact[500005];
ll arr_1[500005];
ll fact_[500005];
ll arr_2[1 << 19];
ll arr_3[1 << 19];

void initi()
{

    inv_fact[1] = inv_fact[0] = 1;
    arr_1[1] = arr_1[0] = 1;
    fact_[1] = fact_[0] = 1;

    for (ll i = 2; i < 200005; i++)
    {
        arr_1[i] = arr_1[mod % i] * (mod - mod / i) % mod;
    }

    for (ll i = 2; i < 200005; i++)
    {
        fact_[i] = (fact_[i - 1] * i) % mod;
    }

    for (ll i = 2; i < 200005; i++)
    {
        inv_fact[i] = (arr_1[i] * inv_fact[i - 1]) % mod;
    }
}

ll power_(ll a, ll b = mod - 2, ll c = mod)
{

    a %= c;

    ll res = 1;

    while (b > 0)
    {
        if (b & 1)
            res = res * a % c;

        a = a * a % c;
        b >>= 1;
    }

    return res;
}

void fr_(ll *a, ll n, ll f = 0)
{
    ll i, j, k, u, v;
    ll m, x, w;
    for (i = n >> 1, j = 1, k; j < n - 1; j++)
    {
        if (i > j)
            swap(a[i], a[j]);
        for (k = n >> 1; k <= i; k >>= 1)
            i ^= k;
        i ^= k;
    }

    for (m = 2; m <= n; m <<= 1)

        for (i = 0, x = power_(3, f == 1 ? (M - 1) / m : (M - 1) / m * (m - 1), M); i < n; i += m)

            for (j = i, w = 1; j < i + (m >> 1); j++)
            {

                u = a[j], v = 1ll * w * a[j + (m >> 1)] % M;

                if ((a[j] = u + v) >= M)
                    a[j] -= M;

                if ((a[j + (m >> 1)] = u - v) < 0)
                    a[j + (m >> 1)] += M;

                w = 1ll * w * x % M;
            }

    if (f == 1)
        for (w = power_(n, M - 2, M), i = 0; i < n; i++)
            a[i] = 1ll * a[i] * w % M;
}

vector<ll> fun_sol(vector<ll> arr, vector<ll> brr)
{

    ll a = arr.size() - 1;
    ll b = brr.size() - 1;
    ll fina_ = 1;

    while (fina_ <= a + b)
        fina_ *= 2;

    for (ll i = 0; i < fina_; i++)
        arr_2[i] = i <= a ? arr[i] : 0;

    ll i = 0;
    while (i < fina_)
    {
        arr_3[i] = i <= b ? brr[i] : 0;
        i++;
    }
    fr_(arr_3, fina_);
    fr_(arr_2, fina_);
    for (ll i = 0; i < fina_; i++)
        arr_2[i] = arr_2[i] * arr_3[i] % M;

    fr_(arr_2, fina_, 1);
    vector<ll> res;
    for (ll i = 0; i <= (a + b); i++)
        res.push_back(arr_2[i]);

    return res;
}

ll combination(ll n, ll r)
{

    if (r > n)
        return 0;

    return (((inv_fact[r] * inv_fact[n - r]) % mod) * fact_[n]) % mod;
}

int main()
{
    initi();
    ll n;
    scanf("%lld", &n);
    vector<ll> arr(n);
    vector<ll> arr_1(30);
    for (ll i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < 30; j++)
            if (arr[i] & (1 << j))
                arr_1[j]++;

    vector<ll> mayb_(n + 1);
    for (ll ii = 0; ii < 30; ii++)
    {
        vector<ll> zero_ = {0};
        vector<ll> one_ = {1};
        for (ll i = 1; i <= arr_1[ii]; i += 2)
        {
            zero_.push_back(combination(arr_1[ii], i));
            zero_.push_back(0);
        }
        ll i = 1;
        while (i <= (n - arr_1[ii]))
        {
            one_.push_back(combination(n - arr_1[ii], i));
            i++;
        }
        auto result_ = fun_sol(zero_, one_);
        i = 0;
        while (i <= n)
        {
            mayb_[i] = (mayb_[i] + ((1 << ii) * result_[i])) % mod;
            i++;
        }
    }

    for (ll i = 1; i <= n; i++)
    {
        mayb_[i] += mayb_[i - 1];
        mayb_[i] %= mod;
    }

    ll q;
    scanf("%lld", &q);
    while (q--)
    {
        ll g;
        scanf("%lld", &g);
        printf("%lld\n", mayb_[g]);
    }
    return 0;
}