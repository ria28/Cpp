#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Edge{
    public :
    ll v , wt;
    Edge(ll v , ll wt)
    {
        this->v =v ;
        this-> wt = wt;
    }
};
void floydWarshall(vector<vector<ll>>&dist , ll n)
{

    for(ll k =1; k<=n;k++)
    {
        for(ll i =1; i<=n ;i++)
        {
            for(ll j =1; j<=n;j++)
            {
                if(dist[i][k] == INT64_MIN || dist[k][j] == INT64_MIN)
                {
                    continue;
                }
                else if(dist[i][j] < dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void dfs(int src , vector<vector<Edge>>&gp , vector<bool>&vis)
{
    if(src == gp.size())
    {
        return;
    }
    if(vis[src]) return;

    vis[src] = true;
    for(Edge e : gp[src])
    {
        if(!vis[e])
            dfs(e.v,gp,vis)
    }
}

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>dist(n+1,vector<ll>(n+1,INT64_MIN));
    vector<vector<Edge>>gp(n+1);

    for(ll i =0; i<m;i++)
    {
        ll a,b;
        ll c;
        cin>>a>>b>>c;
        dist[a][b] = max(dist[a][b] , c);
        gp[a].push_back(Edge(b,c));
        // dist[b][a] = max(dist[b][a] , c);
    } 


    for(ll i =0; i<=n;i++)
    {
        dist[i][i] =0;
    }
    
    vector<bool>vis(n+1,false);
    dfs(1,gp,vis);

    if(floydWarshall(dist,n))
    {
        if(dist[1][n] >= INT64_MAX)
        {
            cout<<"-1";
        }
        else
            cout<<dist[1][n];
        return 0;
    }

    cout<<"-1";

    return 0;
}