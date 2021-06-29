#include <bits/stdc++.h>
using namespace std;
int rep;
bool bfs(int src, int osrc, vector<bool> &vis, vector<vector<int>> &gp, vector<int> &par)
{
    queue<pair<int, string>> q;
    q.push({src, to_string(src)});

    bool res = false;
    par[src] = -1;
    while (!q.empty())
    {
        int size = q.size();
        // if (res)
        //     break;
        while (size--)
        {
            int ele = q.front().first;
            string asf = q.front().second;
            q.pop();

            if (!vis[ele])
            {
                // cout << ele << " ";
                vis[ele] = true;
                for (int i : gp[ele])
                {
                    if (!vis[i])
                    {
                        
                        q.push({i, asf + to_string(i) + " "});
                        par[i] = ele;
                    }
                }
            }
            else
            {

                // cout << ele << "<--cycle ";
                rep = ele;
                res = true;
                // asf+=" ";
                asf += to_string(src);
                int space = count(asf.begin(), asf.end(), ' ');
                cout << asf.size() - space << "\n";
                cout << (asf);
                return true;
                // break;
            }
        }
        // cout<<"\n";
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> gp(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        gp[u].push_back(v);
        gp[v].push_back(u);
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << i << "->";
    //     for (int j : gp[i])
    //         cout << j << ",";
    //     cout << "\n";
    // }

    for (int i = 1; i <= n; i++)
    {
        vector<bool> vis(n + 1, false);
        vector<int> par(n + 1, 0);
        // cout << "strt";
        if (bfs(i, i, vis, gp, par))
        {
            // for (int p : par)
            //     cout << p << " ";
            // cout << "\n";
            // cout<<"CYLCLE\n";
            string ans = "";
            int copy = rep;

            while (rep != -1)
            {
                ans += to_string(rep);
                ans += " ";
                // cout<<rep<<" ";
                rep = par[rep];
            }
            ans += to_string(copy);
            int space = count(ans.begin(), ans.end(), ' ');
            // cout << ans.size() - space << "\n";
            // cout << ans;
            return 0;
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}