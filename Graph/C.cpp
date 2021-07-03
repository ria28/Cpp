#include <bits/stdc++.h>

using namespace std;

unordered_map<int, vector<int>> gp;
vector<string>ans;
void dfs(int src, int dest, unordered_set<int> &set,string asf)
{
    if (set.find(src) != set.end())
        return;

    if (src == dest)
    {
        ans.push_back(asf);
        return;
    }
    set.insert(src);
    asf+= to_string(src);
    for (int i : gp[src])
    {
        if (set.find(i) == set.end())
            dfs(i, dest, set, asf+ "*" );
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
        int u, v;
        cin >> u >> v;
        gp[u].push_back(v);
        // gp[v].push_back(u);

    }

    int a, b;
    cin >> a >> b;

    unordered_set<int> set;
    dfs(a, b, set,"");
    // vector<char>res;
    for(string s : ans)
    {
        for(int i =s.size()-1;i>=0;i--)
        {
            if(isdigit(s[i]))
            {
                cout<<s[i]<<" ";
                // res.push_back(s[i]);
                break;
            }
        }
    }
}