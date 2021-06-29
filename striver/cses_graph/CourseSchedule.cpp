#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Edge
{
public:
    long long v;
    Edge(long long v)
    {
        this->v = v;
        // this->wt = wt;
    }
};

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<Edge>>gp(n+1);
    vector<ll>inorder(n+1,0);
    for(ll i =0; i<m;i++)
    {
        ll u,v;
        cin>>u>>v;
        gp[u].push_back(v);
        inorder[v]++;
    }

    queue<ll>q;
    for(ll i =1;i<=n;i++)
    {
        if(inorder[i] ==0)
            q.push(i);
    }

    vector<ll>res;
    while(!q.empty())
    {
        ll ele = q.front(); q.pop();
        res.push_back(ele);
        for(Edge e : gp[ele])
        {
            inorder[e.v]--;
            if(inorder[e.v] ==0)
                q.push(e.v);
        }
    }

    if(res.size() < n)
    {
        cout<<"IMPOSSIBLE";
    }
    else
    {
        for(ll i : res)
        {
            cout<<i<<" ";
        }
    }
    return 0;
}