#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include<stack>
#define ll long long
using namespace std;
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)
#define vi vector<int>
#define vii vector<vector<int>>
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> gp(n+1, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        gp[u].push_back(v);
        gp[v].push_back(u);
    }

    queue<int> q;
    vector<int> par(n + 1, 0);
    vector<bool> vis(n + 1, false);
    q.push(1);
    int level = 0;
    int pos = 0;
    while (!q.empty())
    {
        int size = q.size();
        level++;
        if (pos == 1)
            break;
        while (size--)
        {
            int ele = q.front();
            q.pop();
            
            vis[ele] = true;
            if (ele == n)
            {
                pos = 1;
                break;
            }
            for (int v : gp[ele])
            {
                if (!vis[v] && !par[v])
                {
                    par[v] = ele;
                    q.push(v);
                }
            }
        }
    }
    if (!pos)
     {   cout << "IMPOSSIBLE";
        return 0;
     }

    string ans = "";
    stack<string>st;
    while (n != 1)
    {
        // ans += to_string(n);
        st.push(to_string(n));
        n = par[n];
    }
    st.push("1");
    cout << st.size() << "\n";
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();   
    }
    return 0;
}

// 5 5
// 1 2
// 1 3
// 1 4
// 2 3
// 5 4

// 4----5
// |
// 1----2
// |    |
// 3-----