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
    int v;
    // int w;
    Edge(int v)
    {
        this->v = v;
        // this->w = w;
    }
};

void addEdge(vector<vector<Edge>> &graph, int u, int v) // u ---> v
{
    graph[u].push_back(Edge(v));
}
void display(vector<vector<Edge>> &graph)
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << "->";
        for (Edge e : graph[i])
        {
            cout << "(" << e.v << ") ";
        }
        cout << "\n";
    }
}
void constructGraph(vector<vector<Edge>> &graph)
{
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 4, 3);
    addEdge(graph, 4, 5);
    addEdge(graph, 4, 6);
    addEdge(graph, 5, 6);

    display(graph);
}

void dfs(vector<vector<Edge>> &graph, int src, vector<bool> &vis, vector<int> &ans)
{
    vis[src] = true;
    for (Edge e : graph[src])
    {
        if (!vis[e.v])
        {
            dfs(graph, e.v, vis, ans);
        }
        // cout << src << " ";
    }

    ans.push_back(src);
    //     for (int i : ans)
    //     cout << i << " ";
}

void topological(vector<vector<Edge>> &graph)
{
    vector<bool> vis(graph.size(), false);
    vector<int> ans(graph.size());
    for (int i = 0; i < graph.size(); i++)
    {
        if (!vis[i])
        {
            dfs(graph, i, vis, ans);
        }
    }

    reverse(ans.begin(), ans.end());
    for (int i : ans)
        cout << i << " ";
}

int main()
{
    int n = 7;
    vector<vector<Edge>> graph(n);
    constructGraph(graph);
    topological(graph);
    return 0;
}