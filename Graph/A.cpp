#include <bits/stdc++.h>

using namespace std;

unordered_map<int, vector<int>> gp;
int temp=0;
void dfs(int src, int dest, unordered_set<int> &set)
{
    if (set.find(src) != set.end())
        return;

    if (src == dest)
    {
        temp = 1;
        return;
    }
    set.insert(src);
    for (int i : gp[src])
    {
        if (set.find(i) == set.end())
            dfs(i, dest, set);
    }
}


unordered_map<int,int>par;
int find(int a )
{
    if(par[a] == a)
    return a;

    int temp = find(par[a]);
    return par[a] = temp;    
}


int main()
{
    int n;
    cin >> n;

    vector<int> nodes(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nodes[i];

        par[nodes[i]] = nodes[i];
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        gp[u].push_back(v);
        // gp[v].push_back(u);

        int p1 = find(u);
        int p2 = find(v);
        if(p1 != p2)
        {
            par[p1] = p2;
        }  
    }

    int a, b;
    cin >> a >> b;

    cout<<(find(a) == find(b));

    unordered_set<int> set;
    // temp = 0;
    // dfs(a, b, set);
    // cout<<temp;
}