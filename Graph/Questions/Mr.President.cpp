#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;
#define f_loop(i, s, e) for (ll i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)

bool cmp(pair<ll, pair<ll, ll>> &a, pair<ll, pair<ll, ll>> &b)
{
    return a.first < b.first;
}

bool isConn(vector<pair<ll, pair<ll, ll>>> &graph, ll n)
{
    queue<ll> q;
    q.push(1);
    vector<bool> vis(n + 1, false);
    ll comp = 0;
    while (!q.empty())
    {
        // cout << comp << " ";
        ll ele = q.front();
        q.pop();
        if (vis[ele])
            continue;
        // cout << ele << " ";
        comp++;
        vis[ele] = true;
        for (auto i : graph)
        {
            if (i.second.first == ele || i.second.second == ele)
            {
                ll nbr = i.second.first == ele ? i.second.second : i.second.first;
                if (!vis[nbr])
                {
                    q.push(nbr);
                }
            }
        }
    }
    // cout << comp;
    return comp == n;
}

vector<ll> par;
vector<ll> rank_;
vector<pair<ll, pair<ll, ll>>> kruskal(vector<pair<ll, pair<ll, ll>>> &graph, ll n)
{
    vector<pair<ll, pair<ll, ll>>> mst;
    par.resize(n + 1);
    rank_.resize(n + 1, 0);
    for (ll i = 1; i <= n; i++)
    {
        par[i] = i;
    }

    for (auto i : graph)
    {
        ll a_ = i.second.first;
        ll b_ = i.second.second;
        ll a = a_;
        ll b = b_;
        while (a != par[a])
            a = par[a];
        while (b != par[b])
            b = par[b];

        if (a == b)
        {
            continue;
        }
        if (rank_[a] == rank_[b])
        {
            par[b] = a;
            rank_[a]++;
        }
        else if (rank_[a] > rank_[b])
        {
            par[b] = a;
        }
        else
        {
            par[a] = b;
        }
        mst.push_back({i.first, {a_, b_}});
    }
    return mst;
}

bool cmp_d(pair<ll, pair<ll, ll>> &a, pair<ll, pair<ll, ll>> &b)
{
    return a.first > b.first;
}

ll solve(vector<pair<ll, pair<ll, ll>>> &mst, ll k)
{
    ll cost = 0, cnt = 0;
    for (auto i : mst)
    {
        cost += i.first;
    }
    sort(mst.begin(), mst.end(), cmp_d);
    for (auto i : mst)
    {
        cout << i.second.first << "->" << i.second.second << "," << i.first << "\n";
    }
    if (cost <= k)
        return mst.size() - 1;

    for (auto i : mst)
    {
        cout << cost << "\n";
        if (cost <= k)
            break;
        cost =cost- i.first + 1;
        cnt++;
    }
    cout << cost << "\n";

    return cost > k ? -1 : cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, k;
    cin >> n >> m >> k;
    vector<pair<ll, pair<ll, ll>>> graph;
    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        pair<ll, ll> p = {u, v};
        graph.push_back({w, p});
    }
    // for (auto i : graph)
    // {
    //     cout << i.second.first << "->" << i.second.second << "," << i.first << "\n";
    // }
    if (!isConn(graph, n))
    {
        return -1;
    }
    sort(graph.begin(), graph.end(), cmp);

    vector<pair<ll, pair<ll, ll>>> mst = kruskal(graph, n);
    // for (auto i : mst)
    // {
    //     cout << i.second.first << "->" << i.second.second << "," << i.first << "\n";
    // }
    cout << solve(mst, k);

    return 0;
}