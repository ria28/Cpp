#include <bits/stdc++.h>

using namespace std;

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

unordered_map<int, vector<Edge>> gp;

void bfs(int src, int dest)
{
    priority_queue<pair<int, int>, vector<pair<int,int>> , greater<pair<int,int>> > pq;
    unordered_set<int> set;

    pq.push({0, src});
    while (!pq.empty())
    {
        int size = pq.size();
        while (size--)
        {
            auto ele = pq.top();
            pq.pop();

            if (set.find(ele.second) != set.end())
                continue;

            if (ele.second == dest)
            {
                cout << ele.first;
                return;
            }
            set.insert(ele.second);
          
            for (Edge e : gp[ele.second])
            {
                if (set.find(e.v) == set.end())
                {
                    pq.push({ele.first + e.wt, e.v});
                }
            }
          
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> nodes(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nodes[i];
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        gp[u].push_back(Edge(v, wt));
        // map[v].push_back(Edge(u,wt));
    }
    int a, b;
    cin >> a >> b;

    bfs(a, b);
}