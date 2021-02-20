#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)
#define i_data int
#define int long long
#define vi vector<int> 
const int value = 500005;
const int val2 = 1 << 19;
int mod = 998244353;
int M = 998244353;
const int MaxN = val2;
int inv_fac[500005];
int track[500005];
int max_1[1 << 19], max2[1 << 19];
int fac[500005];

using namespace std;
ll power_(ll a, ll b = mod - 2, ll c = mod)
{
    a %= c;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % c;
        a = a * a % c;
        b >>= 1;
    }
    return res;
}

void fr(int *a, int n, int f = 0)
{
    int i, j, k, m, u, v, w, x;
    for (i = n >> 1, j = 1, k; j < n - 1; j++)
    {
        if (i > j)
            swap(a[i], a[j]);

        for (k = n >> 1; k <= i; k >>= 1)
            i = i ^ k;
        i = i ^ k;
    }

    for (m = 2; m <= n; m <<= 1)
    {
        ll valll = f == 1 ? (M - 1) / m : (M - 1) / m * (m - 1);
        for (i = 0, x = power_(3, valll, M); i < n; i += m)
            for (j = i, w = 1; j < i + (m >> 1); j++)
            {
                u = a[j], v = 1ll * w * a[j + (m >> 1)] % M;
                if ((a[j] = u + v) >= M)
                    a[j] -= M;
                if ((a[j + (m >> 1)] = u - v) < 0)
                    a[j + (m >> 1)] += M;
                w = 1ll * w * x % M;
            }
    }
    if (f == 1)
        for (w = power_(n, M - 2, M), i = 0; i < n; i++)
            a[i] = 1ll * a[i] * w % M;
}

vi multipl(vi &arr, vi &brr)
{
    int num_a = arr.size() - 1;
    int num_b = brr.size() - 1;
    int num_final = 1;
    while (num_final <= num_a + num_b)
        num_final =num_final* 2;
    int i = 0;
    while (i < num_final)
    {
        max_1[i] = i <= num_a ? arr[i] : 0;
        i++;
    }
    i = 0;
    while (i < num_final)
    {
        max2[i] = i <= num_b ? brr[i] : 0;
        i++;
    }
    fr(max2, num_final);
    fr(max_1, num_final);
    i = 0;
    while (i < num_final)
    {
        max_1[i] = max_1[i] * max2[i] % M;
        i++;
    }
    fr(max_1, num_final, 1);
    vi c;
    i = 0;
    while (i <= (num_a + num_b))
    {
        c.push_back(max_1[i]);
        i++;
    }
    return c;
}

int nCr(int n, int r)
{
    if (r > n)
        return 0;

    return (((inv_fac[r] * inv_fac[n - r]) % mod) * fac[n]) % mod;
}

void init()
{
    inv_fac[1] = inv_fac[0] = track[1] = track[0] = fac[1] = fac[0] = 1;
    int co = 200005;
    for (int i = 2; i < co; i++)
        track[i] = track[mod % i] * (mod - mod / i) % mod;
    for (int i = 2; i < co; i++)
        fac[i] = (fac[i - 1] * i) % mod;
    for (int i = 2; i < co; i++)
        inv_fac[i] = (track[i] * inv_fac[i - 1]) % mod;
}

signed main()
{
    vi track(30);
    init();
    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            if (arr[i] & (1 << j))
            {
                track[j]++;
            }
        }
    }
    vi sss(n + 1);
    for (int k = 0; k < 30; k++)
    {
        vi zero = {0};
        vi ones = {1};

        for (int i = 1; i <= track[k]; i += 2)
        {
            zero.push_back(nCr(track[k], i));
            zero.push_back(0);
        }

        for (int i = 1; i <= (n - track[k]); i++)
        {
            ones.push_back(nCr(n - track[k], i));
        }
        auto idk = multipl(zero, ones);
        for (int i = 0; i <= n; i++)
            sss[i] = (sss[i] + ((1 << k) * idk[i])) % mod;
    }
    for (int i = 1; i <= n; i++)
    {
        sss[i] += sss[i - 1];
        sss[i] %= mod;
    }

    int q;
    cin >> q;
    while (q--)
    {
        int g;
        cin >> g;
        cout << sss[g] << "\n";
    }

    return 0;
}