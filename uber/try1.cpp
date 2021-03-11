#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#define ll long long
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)
#define vi vector<int>
#define vii vector<vector<int>>

using namespace std;

int getPowerCouple2021(int nodes, int edges, vector<int> from, vector<int> to, vector<int> w)
{

    map<int, set<int>> m;
    for (int i = 0; i < to.size(); i++)
    {
        m[w[i]].insert(from[i]);
        m[w[i]].insert(to[i]);
    }

    map<pair<int, int>, int> p;
    int max = INT_MIN;
    int max_product = INT_MIN;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        set<int> s = it->second;
        vector<int> v(s.begin(), s.end());
        int siz = v.size();
        for (int i = 0; i < siz - 1; i++)
        {
            p[make_pair(v[i], v[i + 1])]++;
            if (max < p[make_pair(v[i], v[i + 1])])
                max = p[make_pair(v[i], v[i + 1])];
        }
        if (siz > 2)
        {
            p[make_pair(v[0], v[siz - 1])]++;
            if (max < p[make_pair(v[0], v[siz - 1])])
                max = p[make_pair(v[0], v[siz - 1])];
        }
    }
    for (auto itr = p.begin(); itr != p.end(); itr++)
    {
        pair<int, int> pr = itr->first;
        if (itr->second == max)
            if (max_product < pr.first * pr.second)
                max_product = pr.first * pr.second;
    }
    return max_product;
}

int main()
{
    int nodes = 4, edges = 5;

    vector<int> from = {1, 1, 2, 2, 2};
    vector<int> to = {2, 2, 3, 3, 4};
    vector<int> wt = {1, 2, 1, 3, 3};

    cout << getPowerCouple2021(nodes, edges, from, to, wt);
}