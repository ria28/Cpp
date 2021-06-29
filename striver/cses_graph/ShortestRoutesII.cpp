#include<bits/stdc++.h>
#define ll long long
using namespace std;

void floydWarshall(vector<vector<ll>>&dist , ll n)
{

    for(ll k =1; k<=n;k++)
    {
        for(ll i =1; i<=n ;i++)
        {
            for(ll j =1; j<=n;j++)
            {
                if(dist[i][k] == INT64_MAX || dist[k][j] == INT64_MAX)
                {
                    continue;
                }
                else if(dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main()
{
    ll n,m, q;
    cin>>n>>m>>q;
    vector<vector<ll>>dist(n+1,vector<ll>(n+1,INT64_MAX));

    for(ll i =0; i<m;i++)
    {
        ll a,b;
        ll c;
        cin>>a>>b>>c;
        dist[a][b] = min(dist[a][b] , c);
        dist[b][a] = min(dist[b][a] , c);
    } 


    for(ll i =0; i<=n;i++)
    {
        dist[i][i] =0;
    }
    
    floydWarshall(dist,n);

    
    while(q--)
    {
        ll u , v;
        cin>>u>>v;
        if(dist[u][v] == INT64_MAX)
        {
            cout<<"-1\n";
            continue;
        }
        cout<<dist[u][v]<<"\n";
    }
    return 0;
}