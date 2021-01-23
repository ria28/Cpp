#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
#define v vector
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

void addEdge(v<v<Edge>> &graph, int u, int v, int w)
{
    graph[u].push_back(Edge(v, w));
    graph[v].push_back(Edge(u, w));
}

void display(v<v<Edge>> &graph)
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << "-> ";
        for (Edge e : graph[i])
        {
            cout << "(" << e.v << "," << e.w << ")";
        }
        cout << "\n";
    }
}

void constructGraph(v<v<Edge>> &graph)
{
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 3, 40);
    addEdge(graph, 1, 2, 10);
    addEdge(graph, 2, 3, 10);
    addEdge(graph, 3, 4, 2);
    addEdge(graph, 4, 5, 3);
    addEdge(graph, 4, 6, 8);
    addEdge(graph, 5, 6, 3);
}

class pair_
{
public:
    int v;
    int w;
    int par;
    // string asf;
    pair_(int v, int w, int par)
    {
        this->v = v;
        // this->asf = asf;
        this->w = w;
        this->par = par;
    }

    bool operator>(const pair_ &o) const
    {
        return this->w > o.w; // minPQ
    }
};

void prims(v<v<Edge>> &graph, int src)
{
    vector<vector<Edge>> primsGraph(graph.size(), vector<Edge>());
    priority_queue<pair_, vector<pair_>, greater<pair_>> minHeap;
    // priority_queue<pair_, vector<pair_>, dijikstraComp> minHeap; // by default min PQ. -->IF OPERATOR OVERLOADED USING 2D METHOD

    minHeap.push(pair_(src, 0, -1));
    v<bool> vis(graph.size(), false);
    while (!minHeap.empty())
    {
        int size = minHeap.size();
        while (size-- > 0)
        {
            pair_ ele = minHeap.top();
            minHeap.pop();

            // if (ele.v == dest)
            // {
            //     cout << ele.asf << " " << ele.w << " \n";
            // }

            if (!vis[ele.v])
            {
                vis[ele.v] = true;
                if (ele.par != -1)
                    addEdge(primsGraph, ele.v, ele.par, ele.w);
                for (Edge e : graph[ele.v])
                {
                    if (!vis[e.v])
                    {
                        minHeap.push(pair_(e.v, ele.w + e.w, ele.v));
                    }
                }
            }
        }
    }
    display(primsGraph);
}

// --------------------- KRUSKAL ALGORITHM------------------------------------

vector<int> par;
vector<int> rank_;

void makeSet()
{
    for (int i = 0; i <= 8; i++)
    {
        par[i] = i;
        rank_[i] == 0;
    }
}

int findPar(int data)
{
    if (par[data] == data)
        return data;
    return findPar(par[data]);
}

void union_find(vector<vector<Edge>> &graph, vector<vector<int>> &edges, int n)
{
    par.resize(n);
    rank_.resize(n);
    int cycle = 0;

    makeSet();

    for (vector<int> data : edges)
    {
        int par1 = findPar(data[0]);
        int par2 = findPar(data[1]);

        if (par1 == par2)
        {
            cycle++;
            continue;
        }
        else
        {
            if (rank_[par1] > rank_[par2])
            {
                par[par2] = par1;
            }
            else if (rank_[par1] < rank_[par2])
            {
                par[par1] = par2;
            }
            else
            {
                par[par2] = par1;
                rank_[par1]++;
            }

            addEdge(graph, data[0], data[1], data[2]);
        }
    }
    cout << cycle << "\n";
}

bool sortCol(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2]; // sorting on the basis of weight which is index 2
}

void kruskal()
{
    int n = 9;
    //{u,v,w}
    vector<vector<int>> edges = {{0, 1, 4}, {0, 7, 8}, {1, 7, 11}, {1, 2, 8}, {7, 8, 7}, {7, 6, 1}, {2, 8, 2}, {8, 6, 6}, {2, 5, 4}, {2, 3, 7}, {6, 5, 2}, {3, 4, 9}, {3, 5, 14}, {5, 4, 10}};
    sort(edges.begin(), edges.end(), sortCol); // sorting on the basis of weight which is index 2
    vector<vector<Edge>> graph(n, vector<Edge>());

    union_find(graph, edges, n);
    display(graph);
}

int main()
{
    int n = 7;
    vector<vector<Edge>> graph(n);
    constructGraph(graph);

    // covers every vertex wit min cost possible
    // prims(graph, 0);
    kruskal();
    return 0;
}