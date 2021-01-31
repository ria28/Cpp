#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;

// Topological Sort (handles all cases even if cyclic)

void kahnAlgo(vector<vector<int>> &graph, vector<int> &inorder, int n)
{
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (inorder[i] == 0)
            q.push(i);

    //BFS
    vector<int> res;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        res.push_back(cur);
        for (auto i : graph[cur])
        {
            inorder[i]--;
            if (inorder[i] == 0)
                q.push(i);
        }
    }

    for (auto i : res)
        cout << i << " ";
}

int main()
{
    // 0 --->1    0--->2    1------->3      2---------->3
    // vector<vector<int>> arr = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    vector<vector<int>> arr = {{0, 1}};
    vector<vector<int>> graph(2);
    vector<int> inorder(graph.size(), 0);

    for (int i = 0; i < arr.size(); i++)
    {
        graph[arr[i][1]].push_back(arr[i][0]);
        inorder[arr[i][0]]++;
    }

    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << "->";
        for (int j = 0; j < graph[i].size(); j++)
            cout << graph[i][j] << " ";
        cout << "\n";
    }
    for (auto i : inorder)
        cout << i << " ";
    kahnAlgo(graph, inorder, arr.size());
    return 0;
}