#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <vector>
#include <chrono>
#include <climits>
#define vll vector<ll>
#define ll long long int
ll dp[4020][4020];
ll pref[4020];
#define f(i, s, e) for (long long int i = s; i < e; i++)
#define f_e(i, s, e) for (long long int i = s; i <= e; i++)
#define vll vector<ll>
using namespace std;
using namespace chrono;

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cout << name << " : " << arg1 << endl;
    //use cerr if u want to display at the bottom
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}


ll fun(ll idx, ll taken, ll n, ll k, vll &arr)
{
    if (taken >= k && (pref[idx] - taken >= k))
        return 0;
    else if (idx >= n)
        return 1e10;
    else if (dp[idx][taken] != -1)
        return dp[idx][taken];

    ll c1 = fun(idx + 1, min(pref[idx] - taken + arr[idx], taken), n, k, arr);
    ll c2 = fun(idx + 1, min(taken + arr[idx], pref[idx] - taken), n, k, arr);

    dp[idx][taken] = 1 + min(c1, c2);
    return dp[idx][taken];
}

ll solve(vll &arr, ll n, ll k)
{
    f(i, 0, n / 2)
        swap(arr[i], arr[n - i - 1]);
    f_e(i, 0, n + 10)
    {
        pref[i] = 0;
        f_e(j, 0, k + 10) dp[i][j] = -1;
    }
    f_e(i, 1, n) pref[i] = pref[i - 1] + arr[i - 1];
    ll ans = fun(0, 0, n, k, arr);
    return ans > 1e9 ? -1 : ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r" ,stdin);
        freopen("output.txt", "w" ,stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    auto start1 = high_resolution_clock::now();

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vll arr(n, 0);
        for (long long int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end());
        if (n == 1)
        {
            cout << "-1" << endl;
            continue;
        }
        cout << solve(arr, n, k) << endl;
    }

    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE

        cerr << "Time: " << duration.count() / 1000.0 << endl;
        cout<<duration.count()/1000.0<<endl;
#endif
}