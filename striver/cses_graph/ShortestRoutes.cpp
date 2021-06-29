#include <bits/stdc++.h>
#include <queue>
using namespace std;
class Edge
{
public:
    long long v, wt;
    Edge(long long v, long long wt)
    {
        this->v = v;
        this->wt = wt;
    }
};

class pair_
{
public:
    long long v;
    long long wt;
    // string asf;
    pair_(long long v, long long wt)
    {
        this->v = v;
        this->wt = wt;
        // this->asf = asf;
    }

    bool operator>(const pair_ &o) const
    {
        return o.wt < this->wt; // min heap
    }
};

void dijkstra(vector<vector<Edge>> &gp, long long src)
{
    priority_queue<pair_, vector<pair_>, greater<pair_>> minHeap;
    minHeap.push(pair_(src, 0));
    long long n = gp.size();
    vector<bool> vis(n, false);
    vector<long long>dist(n,LLONG_MAX);
    dist[1]=0;

    while (!minHeap.empty())
    {
        long long size = minHeap.size();
        while (size--)
        {
            pair_ ele = minHeap.top();
            minHeap.pop();

            // if(ele.v == dest)
            // {
            //     return ele.wt;
            // }
            if(vis[ele.v]) continue;
            vis[ele.v] = true;

            for (Edge e : gp[ele.v])
            {
                if (!vis[e.v])
                {
                    if(dist[e.v] > dist[ele.v] + e.wt)
                    {
                        dist[e.v] = dist[ele.v] + e.wt;
                        minHeap.push(pair_(e.v, ele.wt + e.wt));
                    }
                    
                }
            }
        }
    }

    for(long long i =1; i<dist.size();i++)
    {
        cout<<dist[i]<<" ";
    }
}

int main()
{
    long long n, m;
    cin >> n >> m;
    vector<vector<Edge>> gp(n + 1);
    for (long long i = 0; i < m; i++)
    {
        long long u, v, wt;
        cin >> u >> v >> wt;
        gp[u].push_back(Edge(v, wt));
    }

    // for (long long i = 1; i <= n; i++)
    // {
        dijkstra(gp, 1);
    // }
}