#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> tin;
vector<int> low;
vector<bool> vis;
int timer = 1;
vector<string> res;

void dfs(int node, int par, vector<vector<int>> &gp)
{
    tin[node] = low[node] = timer++;
    vis[node] = true;
    for (int i : gp[node])
    {
        if (i == par)
            continue;

        if (!vis[i])
        {
            dfs(i, node, gp);
            low[node] = min(low[node], low[i]);
            if (low[i] > tin[node])
            {
                string ans = to_string(node) + " - " + to_string(i);
                // cout << ans << " ";
                res.push_back(ans);
            }
        }
        else
        {
            low[node] = min(low[node], tin[i]);
        }
    }
}

signed main()
{
    int n;
    cin >> n;
    // if(n==0)
    // {
    //     cout<<n
    // }
    vector<vector<int>> gp(n);
    tin.resize(n, -1);
    low.resize(n, -1);
    vis.resize(n, false);

    int N = n;
    while (n--)
    {
        int u;
        cin >> u;
        char bracket;
        int no_of_v;
        cin >> bracket;
        cin >> no_of_v >> bracket;

        for (int i = 0; i < no_of_v; i++)
        {
            int v;
            cin >> v;
            gp[u].push_back(v);
        }
    }

    // for (int i = 0; i < gp.size(); i++)
    // {
    //     cout << i << "->";
    //     for (int j : gp[i])
    //     {
    //         cout << j << ",";
    //     }
    //     cout << "\n";
    // }
    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1, gp);
        }
    }

    cout << res.size() << " critical links\n";
    sort(res.begin(),res.end());
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << "\n";
    }

    // return 0;
}