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
#define vii vector<vector<int>>
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    unordered_map<int, vector<int>> map;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        map[u].push_back(v);
        map[v].push_back(u);
    }

    queue<pair<int, int>> q;
    vector<bool> vis(n + 1, false);
    q.push({});
    // vis[1] = true;
    int level = 0;
    bool pos = 0;
    while (!q.empty())
    {
        int size = q.size();
        level++;
        while (size--)
        {
            auto ele = q.front();
            q.pop();
            if (ele.first == n)
            {
                pos =1;
                cout << level << "\n";
                cout << ele.second;
                return 0;
            }
            vis[ele.first] = true;
            for (int v : map[ele.first])
            {
                if (!vis[v])
                {
                    q.push({v, ele.second + to_string(v) +" "});
                }
            }
        }
    }
    if(!pos)
    cout<<"IMPOSSIBLE";
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