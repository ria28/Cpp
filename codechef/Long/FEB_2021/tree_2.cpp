#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
// #define ll long long
// using namespace std;
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1000000007;
const int N = 3e5, M = N;

vector<int> g[N];
int a[N];
ll n;
vector<ll> arr_2;
vector<set<pair<ll, ll>>> arr_3;
vector<vector<ll>> graph_;
vector<ll> rank_;

struct HASH
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

vector<unordered_map<ll, ll, HASH>> memo;

void parent_(ll vtx)
{
    arr_2[vtx] = vtx;
    for (auto i : graph_[vtx])
    {
        parent_(i);
        if (rank_[vtx] == 1)
            arr_2[vtx] = arr_2[i];
    }
}

void dfs(ll vtx)
{
    for (auto i : graph_[vtx])
    {
        ll c = i;
        if (rank_[c] == 0)
        {
            memo[vtx][rank_[vtx]]++;
            memo[c][1]++;
            continue;
        }
        if (rank_[vtx] == 1)
            c = arr_2[vtx];
        dfs(c);
        for (auto j : memo[c])
            memo[vtx][rank_[vtx] * 1ll * j.first] += j.second;
    }
}

ll power__(ll base, ll power)
{
    base %= mod;
    ll result = 1;
    while (power > 0)
    {
        if (power & 1)
            result = ((ll)result * base) % mod;
        base = ((ll)base * base) % mod;
        power >>= 1;
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    arr_2.resize(n + 1);
    arr_3.resize(n + 1);
    graph_.resize(n + 1);
    rank_.resize(n + 1, 0);
    memo.resize(n + 1);

    for (ll i = 2; i <= n; ++i)
    {
        ll x;
        cin >> x;
        graph_[x].emplace_back(i);
        rank_[x]++;
    }
    parent_(1);
    dfs(1);
    ll q;
    cin >> q;
    while (q--)
    {
        ll vtx, w;
        ll p = 0ll;
        cin >> vtx >> w;
        vtx = arr_2[vtx];
        auto itr = arr_3[vtx].lower_bound(pair<ll, ll>{w, -1});
        if (itr != arr_3[vtx].end() and itr->first == w)
        {
            cout << itr->second << "\n";
            continue;
        }
        for (auto &i : memo[vtx])
        {
            if (i.first and w % i.first == 0)
                p += (w / i.first) * i.second * 1ll;
        }
        cout << (w - p) << "\n";
    }

    return 0;
}
