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

// https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/mrinal-and-three-musketeers-128f4c52/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
    vector<int> nbrs(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        // graph[a].push_back(b);
        // graph[b].push_back(a);

        graph[a][b] = 1;
        graph[b][a] = 1;
        nbrs[a]++;
        nbrs[b]++;
    }
    int res = INT_MAX;
    // cout<<graph[4].size()<<"<-";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << graph[i][j] << " ";
        cout << "\n";
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            for (int k = j + 1; k <= n; k++)
            {
                if (graph[i][j] == 1 && graph[i][k] == 1 && graph[j][k] == 1)
                {
                    int recog = nbrs[i] + nbrs[j] + nbrs[k];
                    // cout << recog << " ";
                    res = min(res, recog);
                }
            }
        }
    }

    res = res - 6;
    // we need to subtract the relationship between the 3 musketeers
    // For each musketeer his recognition is the number of warriors he knows, excluding other two musketeers.
    cout << res << "\n";
    return 0;
}