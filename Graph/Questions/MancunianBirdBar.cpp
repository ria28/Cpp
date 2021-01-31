#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;

class Edge
{
public:
    int nbr;
    Edge(int nbr)
    {
        this->nbr = nbr;
    }
};

int solve(vector<ll> &barDir, int no, int n, vector<vector<Edge>> &graph)
{
    for (int i = 1; i <= n; i++)
    {
        cout << i << "->";
        for (Edge e : graph[i])
            cout << e.nbr << " ";
        cout << "\n";
    }
    int cnt = 1;
    vector<bool> vis(n + 1, false);
    for (int i = no; i <= n;)
    {
        cout << i << " ";
        if (graph[i].size() == 0)
        {
            break;
        }
        int ele =i;
        for (Edge e : graph[i])
        {
            cnt++;
            i = e.nbr;
        }
    }
    cout << cnt << " ";
}

void update(vector<ll> &barDir, vector<vector<Edge>> &graph)
{
    for (ll i = 1; i < barDir.size(); i++)
    {
        barDir[i] = (barDir[i] + 1) % 2;
        for (Edge e : graph[i])
        {
            if (barDir[i] == 1)
            {
                graph[i].push_back(Edge(i + 1));
                graph[i + 1].erase(graph[i + 1].begin(), graph[i + 1].end());
            }
            else
            {
                graph[i + 1].push_back(Edge(i));
                graph[i].erase(graph[i].begin(), graph[i].end());
            }
        }
    }
}

int main()
{
    ll n;                     // 4
    cin >> n;                 // 0 1 2 3
    vector<ll> barDir(n + 1); // 3(n-1)
    vector<vector<Edge>> graph(n + 1);
    for (ll i = 1; i < n; i++) //  1 1 0 --->  0->1->2<-3
    {
        cin >> barDir[i];
        if (barDir[i] == 1)
        {
            graph[i].push_back(Edge(i + 1));
        }
        else
        {
            graph[i + 1].push_back(Edge(i));
        }
    }
    ll q;
    cin >> q;
    while (q--)
    {
        char query;
        cin >> query;
        if (query == 'U')
        {
            update(barDir, graph);
            for (ll i = 1; i < n; i++)
            {
                cout << barDir[i] << " ";
            }
        }
        else
        {
            pair<char, int> p;
            p.first = query;
            cin >> p.second;
            solve(barDir, p.second, n, graph);
        }
    }

    return 0;
}