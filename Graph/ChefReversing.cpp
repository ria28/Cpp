#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#define ll long long
using namespace std;
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)
#define vi vector<int>
#define vii vector<vector<int>>

class Edge
{
public:
    int v, w;
    Edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};

class pair_
{
public:
    int v, wsf;
    // string asf;
    pair_(int v, int wsf)
    {
        this->v = v;
        this->wsf = wsf;
    }

    bool operator>(const pair_ &o) const
    {
        return this->wsf > o.wsf;
    }
};

int bfs(vector<vector<Edge>> &gp, int src, int tar)
{
    priority_queue<pair_, vector<pair_>, greater<pair_>> pq; // min heap
    int n = gp.size();
    vector<bool> vis(n, false);
    // int tar = n - 1;
    pq.push(pair_(0, 0));
    int ans = INT_MAX;
    while (!pq.empty())
    {
        int size = pq.size();
        while (size-- > 0)
        {
            pair_ ele = pq.top();
            pq.pop();
            // cout<<ele.v<<" ,";
            if (ele.v == tar)
            {
                
                ans = min(ans,ele.wsf); 
                // cout<<"ans"<<ans<<" "; 
            }

            if (!vis[ele.v])
            {
                vis[ele.v] = true;
                for (Edge e : gp[ele.v])
                {
                    if (!vis[e.v])
                    {
                        pq.push(pair_(e.v, ele.wsf + e.w));
                    }
                }
            }
        }
    }
    return ans;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> gp(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        if(u==v)
        continue;
        gp[u - 1].push_back(Edge(v - 1, 0));
        gp[v - 1].push_back(Edge(u - 1, 1));
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << "-> ";
    //     for (Edge e : gp[i])
    //         cout << "(" << e.v << "," << e.w << "), ";
    //     cout << "\n";
    // }

    int ans = bfs(gp, 0, n - 1);
    cout << ans;

    return 0;
}