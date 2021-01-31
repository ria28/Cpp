#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;

// https://www.hackerrank.com/challenges/journey-to-the-moon/problem

// ll findPar(ll n1, vector<ll> &par)
// {
//     if (par[n1] == n1)
//         return n1;

// }

long long journeyToMoon(ll n, vector<vector<ll>> &astronaut)
{
    vector<ll> par(n);
    vector<ll> Rank(n, 0);

    for (ll i = 0; i < n; i++)
        par[i] = i;

    for (auto i : astronaut)
    {
        ll n1 = i[0];
        ll n2 = i[1];
        ll data1 = n1;
        ll data2 = n2;

        while (n1 != par[n1])
            n1 = par[n1];
        while (n2 != par[n2])
            n2 = par[n2];

        if (n1 != n2)
        {
            par[n2] = n1;
        }
    }

    for (ll i = 0; i < n; i++)
    {
        ll ele = i;
        while (ele != par[ele])
        {
            // cout << ele << " " << par[ele];
            ele = par[ele];
        }
        par[i]=ele;
    }

    for (ll i = 0; i < n; i++)
    {
        Rank[par[i]]++;
    }

    // for (auto i : Rank)
    // {
    //     cout << i << " ";
    // }
    // cout << "\n";
    // for (auto i : par)
    // {
    //     cout << i << " ";
    // }

    ll prod = 0;
    ll sum = 0, res = 0;
    ll i = 0, j = 1;

    // ll n = astronaut.size();
    for (ll i = 0; i < n; i++)
    {
        if (Rank[i] > 0)
        {
            prod += sum * Rank[i];
            sum += Rank[i];
        }
    }
    // cout << "prod" << prod<<" ";
    return prod;
}

// 10 7
// 0 2
// 1 8
// 1 4
// 2 8
// 2 6
// 3 5
// 6 9
int main()
{
    ll n = 10;
    vector<vector<ll>> astronaut = {{0, 2}, {1, 8}, {1, 4}, {2, 8}, {2, 6}, {3, 5}, {6, 9}};
    cout << (journeyToMoon(n, astronaut));
    return 0;
}
