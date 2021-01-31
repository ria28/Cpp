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

void bfs(vector<vector<ll>> &graph, ll n, vector<bool> &vis)
{
    queue<ll> q;
    q.push(1);
    ll level = 0;
    while (!q.empty())
    {
        ll size = q.size();
        while (size--)
        {
            ll cur = q.front();
            // cout << cur << " ";
            q.pop();
            if (cur == n)
            {
                cout << level << "\n";
                return;
            }

            for (ll i : graph[cur])
            {
                if (!vis[i])
                {
                    vis[i] = true;
                    q.push(i);
                }
            }
        }
        level++;
    }
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> graph(n + 1, vector<ll>());
        for (ll i = 0; i < m; i++)
        {
            // cout << i << " " << m<<" ";
            ll u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        // for (ll i = 1; i <= n; i++)
        // {
        //     cout << i << "->";
        //     for (auto j : graph[i])
        //     {
        //         cout << j << " ";
        //     }
        //     cout << "\n";
        // }
        vector<bool> vis(n+1, false);
        bfs(graph, n, vis);
    }
    return 0;
}