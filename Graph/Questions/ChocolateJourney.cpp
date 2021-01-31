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

class Edge
{
public:
    ll v, w;
    Edge(ll v, ll w)
    {
        this->v = v;
        this->w = w;
    }
};

class pair_
{
public:
    ll v;
    ll w;
    ll par;
    string asf;
    pair_(ll v, string asf, ll w, ll par)
    {
        this->v = v;
        this->asf = asf;
        this->w = w;
        this->par = par;
    }

    // OPERATOR OVERLOADING : CAN USE ONLY OPERATOR KEYWORD

    // this is a constant member function
    // const at the end of the function means it isn't going to modify the state of the object it is called up on ( i.e., this ).
    bool operator>(const pair_ &o) const
    {
        return this->w > o.w; // minPQ
    }
};

void dijkstra(vector<vector<Edge>> &graph, vector<int> &vis, ll a, ll b, ll n, int x)
{
    // vector<vector<Edge>> dijikstraGraph(graph.size(), vector<Edge>());
    priority_queue<pair_, vector<pair_>, greater<pair_>> minHeap;
    // priority_queue<pair_, vector<pair_>, dijikstraComp> minHeap; // by default min PQ. -->IF OPERATOR OVERLOADED USING 2D METHOD

    minHeap.push(pair_(b, to_string(b), 0, -1));
    // vector<bool> vis(graph.size(), false);
    bool hasC = false;
    ll dis = 0;
    while (!minHeap.empty())
    {
        ll size = minHeap.size();
        while (size-- > 0)
        {
            pair_ ele = minHeap.top();
            minHeap.pop();

            // cout << ele.v << " ";
            // if (vis[ele.v] == 2)
            // {
            //     // cout<<ele.v<<" ";
            //     hasC = true;
            //     dis = ele.v;
            // }
            if (ele.v == a)
            {
                cout << ele.asf << " " << ele.w << " \n";
                return;
            }

            if (vis[ele.v] !=1)
            {
                vis[ele.v] = 1;
                // if (ele.par != -1)
                //     addEdge(dijikstraGraph, ele.v, ele.par, ele.w);
                for (Edge e : graph[ele.v])
                {
                    if (vis[e.v] !=1)
                    {
                        minHeap.push(pair_(e.v, ele.asf + to_string(e.v), ele.w + e.w, ele.v));
                    }
                }
            }
        }
    }
    // display(dijikstraGraph);
    cout << -1 << "\n";
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    ll n, m, k, x;
    cin >> n >> m >> k >> x;
    vector<int> vis(n + 1, 0); // 0 : not vis ; 1 : vis ; 2 : has chocolate
    for (ll i = 0; i < k; i++)
    {
        ll city;
        cin >> city;
        vis[city] = 2;
    }
    // cout<<"hello";
    vector<vector<Edge>> graph(n + 1);
    for (ll i = 0; i < m; i++)
    {
        ll u, v, d;
        cin >> u >> v >> d;
        graph[u].push_back(Edge(v, d));
        graph[v].push_back(Edge(u, d));
    }
    ll a, b;
    cin >> a >> b;
    dijkstra(graph, vis, a, b, n, x);
    return 0;
}