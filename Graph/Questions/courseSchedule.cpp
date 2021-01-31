#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;

vector<int> kahnAlgo(vector<vector<int>> &graph, vector<int> &inorder, int n)
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

    // for (auto i : res)
    //     cout << i << " ";
    vector<int> empty;
    if (res.size() == n)
        return res;
    else
        return empty;
}

vector<int> findOrder(int numCourses, vector<vector<int>> &pre)
{

    if (pre.size() == 0)
    {
        vector<int> ans;
        for (int i = 0; i < numCourses; i++)
            ans.push_back(i);
        return ans;
    }
    vector<vector<int>> graph(numCourses);
    vector<int> inorder(graph.size(), 0);

    for (int i = 0; i < pre.size(); i++)
    {
        graph[pre[i][1]].push_back(pre[i][0]);
        inorder[pre[i][0]]++;
    }
    return kahnAlgo(graph, inorder, numCourses);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numCourses = 2;
    vector<vector<int>> pre = {{1, 0}, {0, 1}};
    vector<int> ans = findOrder(numCourses, pre);
    for (int i : ans)
        cout << i << " ";

    return 0;
}