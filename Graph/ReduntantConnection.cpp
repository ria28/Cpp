#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)

        vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> p(edges.size()+1, 0);
        for(int i = 0; i < p.size(); i++ )
            p[i] = i;
        
        vector<int> res(edges.size(),0);
        for(auto v : edges ){
            int n1 = v[0], n2 = v[1];
            while(n1 != p[n1]) 
                n1 = p[n1];
            while(n2 != p[n2]) 
                n2 = p[n2];
            if( n1 == n2 )
                res = v;
            else
                p[n1] = n2;
        }
        return res;
    }

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}};
    vector<int> ans = findRedundantConnection(edges);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}