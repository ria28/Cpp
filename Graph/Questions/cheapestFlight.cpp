#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;

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
    int val, wsf, k;
    pair_(int val, int wsf, int k)
    {
        this->val = val;
        this->k = k;
        this->wsf = wsf;
    }
    bool operator>(const pair_ &o) const
    {
        return this->wsf > o.wsf; // minPQ
    }
};

void addEdge(vector<vector<Edge>> &graph, int u, int v, int w)
{
    graph[u].push_back(Edge(v, w));
}

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<vector<pair<int, int>>> graph(n);
    for (auto i : flights)
    {
        // addEdge(graph, i[0], i[1], i[2]);  // tle
        graph[i[0]].push_back({i[1], i[2]});
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << "->";
    //     for (Edge e : graph[i])
    //     {
    //         cout << "(" << e.v << "," << e.w << ")";
    //     }
    //     cout << "\n";
    // }

    priority_queue<pair_, vector<pair_>, greater<pair_>> q;
    q.push(pair_(src, 0, k + 1));

    while (!q.empty())
    {
        pair_ ele = q.top();
        q.pop();
        // cout << ele.val << " " << ele.k << "\n";
        if (ele.val == dst)
        {
            // cout << ele.val << " " << ele.wsf << " ";
            return ele.wsf;
        }
        if (ele.k == 0)
            continue;
        for (auto i : graph[ele.val])
        {
            // cout << i.first << " " << ele.k - 1;
            q.push(pair_(i.first, ele.wsf + i.second, ele.k - 1));
        }
    }
    // if (min_wt == INT16_MAX)
    //     return -1;
    // else
    return -1;
}
int main()
{
    int n = 3;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    // int src = 0, dst = 2, k = 1;

    cout << findCheapestPrice(n, flights, 0, 2, 1);
    return 0;
}