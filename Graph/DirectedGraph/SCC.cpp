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
#define vii vector<vector<Edge>>

class Edge
{
public:
    int v;
    // int wt;
    Edge(int v)
    {
        this->v = v;
    }
};

void addEdge(vii &gp, int u, int v)
{
    gp[u].push_back(Edge(v)); // u--->v
}

void construct(vii &gp)
{
    addEdge(gp, 1, 0);
    addEdge(gp, 0, 2);
    addEdge(gp, 2, 1);
    addEdge(gp, 0, 3);
    addEdge(gp, 3, 4);
}

void display(vii &gp)
{
    for (int i = 0; i < gp.size(); i++)
    {
        cout << i << "->";
        for (Edge e : gp[i])
            cout << e.v << ", ";
        cout << "\n";
    }
}

void dfs_topologicalSort(vii &gp, int src, vector<bool> &vis, vi &ans) // topological but don't 
expect the order brecause it is cyclic 
{
    vis[src] = true;
    for (Edge e : gp[src])
    {
        if (!vis[e.v])
            dfs_topologicalSort(gp, e.v, vis, ans);
    }
    ans.push_back(src);
    // for (int i : ans)
    //     cout << i << " ";
}

vii transposeGraph(vii &gp)
{
    vii gp_rev(gp.size());
    for (int i = 0; i < gp.size(); i++)
    {
        for (Edge e : gp[i])
        {
            gp_rev[e.v].push_back(Edge(i));
            // cout<<e.v<<" "<<i<<" ,";
        }
    }
    // display(gp_rev);
    return gp_rev;
}

void scc()
{
    vii gp(5);
    construct(gp);
    display(gp);
    
    vector<bool> vis(gp.size(), 0);
    vi ans;

    for (int i = 0; i < gp.size(); i++)
    {
        if (!vis[i])
            dfs_topologicalSort(gp, i, vis, ans);
    }

    vis.clear();
    vis.resize(gp.size(), 0);
    
    vii gp_rev = transposeGraph(gp);

    for (int i = ans.size() - 1; i >= 0; i--)
    {
        vi ans_;
        if (!vis[ans[i]])
        {
            dfs_topologicalSort(gp_rev, ans[i], vis, ans_);
            for (int i : ans_)
                cout << i << " ";
            cout << "\n";
            ans_.clear();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scc();
    return 0;
}