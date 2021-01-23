#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#define ll long long
#define v vector
using namespace std;

// bidirectional graph

class Edge
{
public:
    int v;
    int w;
    Edge(int v, int w)
    {
        this->v = v; // neighbor
        this->w = w; // weight
    }
};

void addEdge(vector<vector<Edge>> &graph, int u, int v, int w)
{
    graph[u].push_back(Edge(v, w));
    graph[v].push_back(Edge(u, w));
}

void removeEdge(vector<vector<Edge>> &graph, int u, int v) // remove edge b/w 3 and 4
{
    int cnt = 0;
    for (Edge e : graph[u])
    {
        if (e.v == v)
            break;
        cnt++;
    }
    graph[u].erase(graph[u].begin() + cnt);

    cnt = 0;
    for (Edge e : graph[v])
    {
        if (e.v == u)
            break;
        cnt++;
    }
    graph[v].erase(graph[v].begin() + cnt);
}

void removeVertex(v<v<Edge>> &graph, int vtx)
{
    for (Edge e : graph[vtx])
    {
        cout << e.v << " ";
        removeEdge(graph, vtx, e.v);
    }
}

void constructGraph(vector<vector<Edge>> &graph)
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

void display(vector<vector<Edge>> &graph)
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << "->";
        for (Edge e : graph[i])
        {
            cout << "(" << e.v << "," << e.w << ") ";
        }
        cout << "\n";
    }
}

int sd = INT_MAX; // shortest distance
string sdp = "";  // sd path
int ld = INT_MIN; // longest distance
string ldp = "";  // longest distance path
int fl = INT_MIN; // floor of a factor(given wt)
string flp = "";  // floor path
int cl = INT_MAX; // ceil of a factor(given wt)
string clp = "";  // ceil path
int factor = 45;
int k = 3; // kth largest path
priority_queue<pair<int, string>> maxHeap;
void allPaths(v<v<Edge>> &graph, int src, int dest, v<bool> &vis, string asf, int wt)
{
    if (src == dest)
    {
        asf += to_string(dest);
        cout << asf << "@" << wt << "\n ";

        if (wt < sd)
        {
            sd = wt;
            sdp = asf;
        }
        if (ld < wt)
        {
            ld = wt;
            ldp = asf;
        }
        if (wt < factor && wt > fl)
        {
            fl = wt;
            flp = asf;
        }
        if (wt > factor && wt < cl)
        {
            cl = wt;
            clp = asf;
        }

        maxHeap.push(make_pair(wt, asf)); // kth largest

        return;
    }

    vis[src] = true;
    for (Edge e : graph[src])
    {
        if (!vis[e.v])
            allPaths(graph, e.v, dest, vis, asf + to_string(src), wt + e.w); // ****imp**** src added in asf
    }
    vis[src] = false;
}

void isConnected(v<string> &comps)
{
    if (comps.size() == 1)
    {
        cout << " Graph is connected";
    }
    else
    {
        cout << "Not connected";
    }
}

string comp = "";
string getSingleComp(v<v<Edge>> &graph, int src, v<bool> &vis)
{
    vis[src] = true;
    comp += to_string(src);
    // cout << src << " " << comp << "\n";
    for (Edge e : graph[src])
    {
        if (!vis[e.v])
        {
            getSingleComp(graph, e.v, vis);
        }
    }
    return comp;
}

void getConnectedComps(v<v<Edge>> &graph, v<string> &comps, v<bool> &vis)
{
    for (int i = 0; i < graph.size(); i++)
    {
        if (!vis[i])
        {
            comp = "";
            string comp_ = getSingleComp(graph, i, vis);
            comps.push_back(comp_);
            cout << comp_ << "\n";
        }
    }
    // for (string s : comps)
    //     cout << s << " ";
}
void gcc()
{
    int n = 7;
    vector<vector<Edge>> graph(n, vector<Edge>());
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 3, 40);
    addEdge(graph, 1, 2, 10);
    addEdge(graph, 2, 3, 10);
    // addEdge(graph, 3, 4, 2);
    addEdge(graph, 4, 5, 3);
    addEdge(graph, 4, 6, 8);
    addEdge(graph, 5, 6, 3);
    display(graph);
    v<string> comps;
    v<bool> vis(n, false);
    getConnectedComps(graph, comps, vis);

    isConnected(comps);
}

// https://leetcode.com/problems/number-of-islands/
void dfs_Island(int i, int j, int row, int col, vector<vector<char>> &grid)
{
    if (i < 0 || i > row - 1 || j < 0 || j > col - 1 || grid[i][j] != '1')
        return;

    grid[i][j] = '0';

    dfs_Island(i - 1, j, row, col, grid);
    dfs_Island(i, j - 1, row, col, grid);
    dfs_Island(i + 1, j, row, col, grid);
    dfs_Island(i, j + 1, row, col, grid);
}

int numIslands(vector<vector<char>> &grid)
{
    if (grid.size() == 0)
        return 0;

    int count = 0;

    int n = grid.size();
    int m = grid[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1')
            {
                count++;
                dfs_Island(i, j, n, m, grid);
            }
        }
    }

    return count;
}

void island()
{
    vector<vector<char>> island = {{'1', '1', '0', '0', '0'},
                                   {'1', '1', '0', '0', '0'},
                                   {'0', '0', '1', '0', '0'},
                                   {'0', '0', '0', '1', '1'}};
    cout << numIslands(island);
}

int findEdge(v<v<Edge>> &graph, int u, int v)
{
    int pos = -1, cnt = 0;
    for (Edge e : graph[u])
    {
        if (e.v == v)
        {
            pos = cnt;
            break;
        }
        cnt++;
    }
    return pos;
}

void hamiltonian(v<v<Edge>> &graph, int src, int osrc, v<bool> &vis, int cnt, string asf)
{
    if (cnt == graph.size() - 1)
    {
        if (findEdge(graph, osrc, src) != -1)
        {
            cout << "Hamiltonian cycle : " << asf + to_string(src) << "\n";
        }
        else
        {
            cout << "Hamiltonian path : " << asf + to_string(src) << "\n";
        }
    }

    vis[src] = true;
    for (Edge e : graph[src])
    {
        if (!vis[e.v])
        {
            hamiltonian(graph, e.v, osrc, vis, cnt + 1, asf + to_string(src));
        }
    }
    vis[src] = false;
}

void hamiltonianPath()
{
    int n = 7;
    vector<vector<Edge>> graph(n, vector<Edge>());
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 3, 40);
    addEdge(graph, 1, 2, 10);
    addEdge(graph, 2, 3, 10);
    addEdge(graph, 2, 5, 10);
    addEdge(graph, 3, 4, 2);
    addEdge(graph, 4, 5, 3);
    addEdge(graph, 4, 6, 8);
    addEdge(graph, 5, 6, 3);
    v<bool> vis(n, false);
    hamiltonian(graph, 0, 0, vis, 0, "");
}

// r m* w a* (remove frm queue, mark star (check if vis then continue,o/wloop through its nbrs), write (add in asf), add (check vis and add its nbrs))
void bfs(v<v<Edge>> &graph, int src)
{
    queue<pair<int, string>> q;
    int level = 0;
    q.push(make_pair(src, to_string(src)));
    v<bool> vis(graph.size(), false);
    while (!q.empty())
    {
        pair<int, string> p = q.front(); // REMOVE  (r)
        q.pop();
        if (!vis[p.first]) // MARK(m*)  check if it was visited because it  might happen that while we were adding nbrs earlier 2 different ele might have same nbrs at the same leve of tree; we can't add nbrs of an ele twice so we check
        {
            vis[p.first] = true;
            cout << level << ": " << p.first << "@" << p.second << "\n"; // WORK print
            for (Edge e : graph[p.first])
            {
                if (!vis[e.v])
                {
                    string asf = p.second + to_string(e.v);
                    q.push(make_pair(e.v, asf)); // ADD nbrs if not visited
                }
            }
        }
    }
}

void bfs_level(v<v<Edge>> &graph, int src)
{
    queue<pair<int, string>> q;
    int level = -1;
    q.push(make_pair(src, to_string(src)));
    v<bool> vis(graph.size(), false);
    while (!q.empty())
    {
        int size = q.size();
        level++;
        while (size-- > 0)
        {
            pair<int, string> p = q.front(); // REMOVE  (r)
            q.pop();
            if (!vis[p.first]) // MARK(m*)  check if it was visited because it  might happen that while we were adding nbrs earlier 2 different ele might have same nbrs at the same leve of tree; we can't add nbrs of an ele twice so we check
            {
                vis[p.first] = true;
                cout << level << ": " << p.first << "@" << p.second << "\n"; // WORK print
                for (Edge e : graph[p.first])
                {
                    if (!vis[e.v])
                    {
                        string asf = p.second + to_string(e.v);
                        q.push(make_pair(e.v, asf)); // ADD nbrs if not visited
                    }
                }
            }
        }
    }
}

void isCyclic(v<v<Edge>> &graph, int src, v<bool> &vis) // passing src coz we can have more than one component
{
    queue<pair<int, string>> q;
    q.push(make_pair(src, to_string(src)));
    while (!q.empty())
    {
        pair<int, string> p = q.front(); // REMOVE  (r)
        q.pop();

        if (!vis[p.first]) // MARK(m*)
        {
            vis[p.first] = true;
            // cout << p.first << "@" << p.second << "\n"; // WORK
            for (Edge e : graph[p.first])
            {
                if (!vis[e.v])
                {
                    string asf = p.second + to_string(e.v);
                    q.push(make_pair(e.v, asf)); // ADD
                }
            }
        }
        else
        {
            cout << "cycle : " << p.second << " ";
        }
    }
}

void isCyclic(v<v<Edge>> &graph) // gcc
{
    v<bool> vis(graph.size(), 0);
    for (int i = 0; i < graph.size(); i++)
    {
        if (!vis[i])
        {
            isCyclic(graph, i, vis);
        }
    }
}

bool bipartite(v<v<Edge>> &graph, v<int> &vis, int src)
{
    queue<pair<int, int>> q;
    q.push({src, 0}); // -1 : unvisited , 0 : red  , 1 : green
    // cout << q.front().first << " " << q.front().second << " ";
    while (!q.empty())
    {
        int size = q.size();
        while (size-- > 0)
        {
            // rmwa
            pair<int, int> p = q.front();
            q.pop();

            cout << p.first << " " << p.second << "\n";
            if (vis[p.first] == -1)
            {
                vis[p.first] = p.second;
                for (Edge e : graph[p.first])
                {
                    if (vis[e.v] == -1)
                    {
                        int color = (p.second + 1) % 2;
                        q.push({e.v, color});
                    }
                }
            }
            else // conflict
            {
                // cout << p.first << " " << p.second << "\n";
                if (vis[p.first] != p.second)
                    return false;
            }
        }
    }
    return true;
}

void bipartite(v<v<Edge>> &graph)
{
    v<int> vis(graph.size(), -1);
    bool flag = true;
    for (int i = 0; i < graph.size(); i++)
    {
        if (vis[i] == -1)
        {
            if (!bipartite(graph, vis, i))
            {
                flag = false;
                break;
            }
        }
    }
    if (flag)
        cout << "Bipartite "; // always for graph containing all the polygons with even edges/sides
    else
        cout << "Not Bipartite";
}

void infectionSpread(v<v<Edge>> &graph, int time, int src)
{
    queue<pair<int, string>> q;
    int level = 0;
    q.push(make_pair(src, to_string(src)));
    v<bool> vis(graph.size(), false);
    int cnt = 0;
    while (!q.empty() && level < time)
    {
        int size = q.size();
        level++;
        while (size-- > 0)
        {
            pair<int, string> p = q.front(); 
            q.pop();
            if (!vis[p.first]) 
            {
                vis[p.first] = true;
                cnt++;
                for (Edge e : graph[p.first])
                {
                    if (!vis[e.v])
                    {
                        string asf = p.second + to_string(e.v);
                        q.push(make_pair(e.v, asf)); 
                    }
                }
            }
        }
    }

    cout<<cnt<<" ";
}

int main()
{
    int n = 7;
    vector<vector<Edge>> graph(n, vector<Edge>());
    constructGraph(graph);
    display(graph);

    v<bool> vis(n, false);
    // allPaths(graph, 0, 6, vis, "", 0);
    // cout << "sdp" << sdp << "\n"
    //      << "ldp" << ldp << "\n"
    //      << "clp" << clp << "\n"
    //      << "flp" << flp << "\n";
    // for (int i = 0; i < k; i++)
    // {
    //     if (i == k - 1)
    //         cout << maxHeap.top().first << " ";
    //     maxHeap.pop();
    // }

    // removeEdge(graph, 3, 4);
    // removeVertex(graph, 2);
    // display(graph);

    // gcc();

    // island();

    // hamiltonianPath();

    // bfs(graph, 0);
    // bfs_level(graph, 0);

    // isCyclic(graph);

    // bipartite(graph);

    infectionSpread(graph,3,6);

    return 0;
}