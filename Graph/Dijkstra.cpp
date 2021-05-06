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
    string asf;
    pair_(int v, string asf, int w, int par)
    {
        this->v = v;
        this->asf = asf;
        this->w = w;
        this->par = par;  // this is only for making dijikstra graph 
    }

    // OPERATOR OVERLOADING : CAN USE ONLY OPERATOR KEYWORD

    // this is a constant member function
    // const at the end of the function means it isn't going to modify the state of the object it is called up on ( i.e., this ).
    bool operator>(const pair_ &o) const
    {
        return this->w > o.w; // minPQ
    }
};

// 2ND METHOD OF OPERATOR OVERLOADING

// struct dijikstraComp
// {
// public:
//     bool operator()(pair_ &p1, pair_ &p2)
//     {
//         return p1.w > p2.w; // default min PQ.
//         //   return p2.wsf > p1.wsf   // max PQ.
//     }
// };

void dijkstra(v<v<Edge>> &graph, int dest)
{
    vector<vector<Edge>> dijikstraGraph(graph.size(), vector<Edge>());
    priority_queue<pair_, vector<pair_>, greater<pair_>> minHeap;
    // priority_queue<pair_, vector<pair_>, dijikstraComp> minHeap; // by default min PQ. -->IF OPERATOR OVERLOADED USING 2D METHOD

    minHeap.push(pair_(0, "0", 0, -1));
    v<bool> vis(graph.size(), false);
    while (!minHeap.empty())
    {
        int size = minHeap.size();
        while (size-- > 0)
        {
            pair_ ele = minHeap.top();
            minHeap.pop();

            if (ele.v == dest)
            {
                cout << ele.asf << " " << ele.w << " \n";
            }

            if (!vis[ele.v])
            {
                vis[ele.v] = true;
                if (ele.par != -1)   // not root 
                    addEdge(dijikstraGraph, ele.v, ele.par, ele.w);
                for (Edge e : graph[ele.v])
                {
                    if (!vis[e.v])
                    {
                        minHeap.push(pair_(e.v, ele.asf + to_string(e.v), ele.w + e.w, ele.v));
                    }
                }
            }
        }
    }
    display(dijikstraGraph);
}


//https://www.baeldung.com/cs/prim-dijkstra-difference#:~:text=In%20the%20computation%20aspect%2C%20Prim's,only%20works%20on%20undirected%20graphs
// Prim’s and Dijkstra’s algorithms have three main differences:
// Dijkstra’s algorithm finds the shortest path, but Prim’s algorithm finds the MST
// Dijkstra’s algorithm can work on both directed and undirected graphs, but Prim’s algorithm only works on undirected graphs
// Prim’s algorithm can handle negative edge weights, but Dijkstra’s algorithm may fail to accurately compute distances if at least one negative edge weight exists
// In practice, Dijkstra’s algorithm is used when we want to save time and fuel traveling from one point to another. Prim’s algorithm, on the other hand, is used when we want to minimize material costs in constructing roads that connect multiple points to each other.

int main()
{
    int n = 7;
    vector<vector<Edge>> graph(n);
    constructGraph(graph);

    // src to dest path
    dijkstra(graph, 6);
    return 0;
}