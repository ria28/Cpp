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
struct Node
{
    ll data;
    // vector<Node *> children;
    Node()
    {
    }
    Node(ll data)
    {
        this->data = data;
    }
};

ll cnt;
void dfs(vector<vector<Node *>> &gp, ll v, ll w)
{
    if (gp[v].size() == 0)
        return;

    if (w % gp[v].size() != 0)
    {
        cnt += w;
        return;
    }
    else
    {
        w = w / gp[v].size();
        for (auto i : gp[v])
        {
            dfs(gp, i->data, w);
        }
    }
}

void solve()
{
    ll n;
    cin >> n;
    vector<Node *> par(n);
    struct Node *root = new Node(1);
    par[0] = root;
    vector<vector<Node *>> gp(n + 1, vector<Node *>());
    for (ll i = 1; i < n; i++)
    {
        struct Node *child = new Node();
        ll parent;
        cin >> parent;
        child->data = i + 1;
        gp[parent].push_back(child);
    }

    ll q;
    cin >> q;
    for (ll i = 0; i < q; i++)
    {
        cnt = 0;
        ll v, w;
        cin >> v >> w;
        dfs(gp, v, w);
        cout << cnt << "\n";
    }

    // for (ll i = 1; i < n + 1; i++)
    // {
    //     cout << i << "->";
    //     for (auto j : gp[i])
    //     {
    //         cout << j->data << ",";
    //     }
    //     cout << "\n";
    // }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}