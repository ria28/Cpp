// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;



int timer =0;

void dfs(int node ,int par , vector<bool>& vis , vector<int>&tin , vector<int>&low , vector<int ,vector<int>>&g , unordered_set<int>&AP)
{
    // cout<<"jev";
    cout<<node<<" ";
    vis[node] = true;
    tin[node] = low[node] = timer++;
    int children = 0;
    vector<int>nbrs = g[node];
    for(int nbr :nbrs)
    {
        if(nbr == par)
            continue;
        if(!vis[nbr])
        {
            dfs(nbr , node , vis, tin , low ,g, AP);
            low[node] = min(low[node] , low[nbr]);
            if(low[nbr] >= tin[node] && par != -1)
                AP.insert(node);
            children++;
        }
        else
        {
            low[node] = min(low[node] , tin[nbr]);
        }
    }
    
}

int doctorStrange_(int n, int m, vector<vector<int>> & g)
{
    vector<bool>vis(n+1 ,false);
    vector<int>tin(n+1);
    vector<int>low(n+1);
    unordered_set<int>AP;
    
    vector<int ,vector<int>>gp(n+1,vector<int>());
   
    for(int i =0; i<g.size();i++)
    {
        for(int j =0; j<g[0].size();j++)
        {
                     
        }
    }
    

    dfs(1,-1,vis , tin , low , gp, AP);
    return AP.size();
}


// int doctorStrange(int n, int m, vector<vector<int>> & g);

signed main()
{
    int t;cin>>t;
    while(t--){
        int n,m,i;
        cin>>n>>m;
        vector<vector<int>> g(n+1);
        for(i=0;i<m;i++)
        {
            int a,b;cin>>a>>b;
            g[i].push_back(a);
            g[i].push_back(b);
        }
        
        cout<<doctorStrange_(n, m, g)<<"\n";
    }
}// } Driver Code Ends


// 5
// |
// 4
// |
// 3---1---2
// |       |
// |_______|
