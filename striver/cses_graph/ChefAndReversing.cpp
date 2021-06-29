#include <bits/stdc++.h>
using namespace std;
#define int long long

class Edge
{
public:
    int v, wt;
    Edge(int v, int wt)
    {
        this->v = v;
        this->wt = wt;
    }
};


int dijkstra(vector<vector<Edge>>& gp , int src , int dest)
{
    priority_queue< pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> >pq; // minheap
    pq.push({0,src});
    vector<bool>vis(dest+1, false);
    while(!pq.empty())
    {
        int size = pq.size();
        while(size--)
        {
            auto ele = pq.top();
            pq.pop();

            if(vis[ele.second]) continue;

            vis[ele.second] = true;
            if(ele.second == dest)
            {
                return ele.first;
            }

            for(auto i : gp[ele.second])
            {
                if(!vis[i.v])
                {
                    pq.push({ele.first + i.wt, i.v});
                }
            }
        }
    }

    return -1;

}

signed main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> gp(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        gp[u].push_back(Edge(v, 0));
        gp[v].push_back(Edge(u, 1));
    }

    cout<<dijkstra(gp, 1, n);
}