#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;

// https://www.hackerrank.com/challenges/torque-and-development/forum

ll findParent(ll a, vector<ll> &p)
{
    if (a == p[a])
        return a;
    return findParent(p[a], p);
}

long roadsAndLibraries(ll n, ll c_lib, ll c_road, vector<vector<ll>> cities)
{

    ll res = 0;
    vector<ll> Rank(n + 1, 0);
    for (ll i = 1; i <= n; i++)
    {
        Rank[i] = 0;
    }
    // cout << c_lib << " " << c_road << "\n";
    if (c_lib < c_road)
    {
        res = c_lib * n;
        // cout << "hello" << res;
        // return res;
    }
    else
    {
        vector<ll> p(n + 1);
        for (ll i = 0; i < p.size(); i++)
            p[i] = i;
        for (auto i : cities)
        {
            ll n1 = i[0];
            ll n2 = i[1];

            while (n1 != p[n1])
                n1 = p[n1];
            while (n2 != p[n2])
                n2 = p[n2];

            if (n1 != n2)
            {
                p[n2] = n1;
            }
        }

        for (ll i = 1; i <= n; i++)
        {
            Rank[findParent(i, p)]++;
        }

        // for (ll i = 1; i <= n; i++)
        // {
        //     cout << Rank[i] << " ";
        // }
        // cout << "\n";

        for (int i = 1; i <= n; i++)
        {
            if (Rank[i] > 0)
            {
                res += c_lib + (Rank[i] - 1) * c_road;
            }
        }
    }
    return res;
}
int main()
{
    ll n, m, c_lib, c_road;
    cin >> n >> m >> c_lib >> c_road;
    vector<vector<ll>> cities(m, vector<ll>(2));
    for (ll i = 0; i < m; i++)
    {
        for (ll j = 0; j < 2; j++)
        {
            cin >> cities[i][j];
        }
    }

        cout << "res : " << (roadsAndLibraries(n, c_lib, c_road, cities));
    return 0;
}