#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <climits>
#define ll long long
using namespace std;

// Approach
// Distribute only N litres of fuel into the car optimally coz to return back u need min N fuels only
// To minimize the cost , fill cars with less cost/litre

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> c(n);
        vector<ll> f(n);
        vector<pair<ll, ll>> map;
        for (int i = 0; i < n; i++)
        {
            cin >> f[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
            map.push_back(make_pair(c[i], f[i]));
        }
        sort(map.begin(), map.end()); // sorted on the basis of cost
        int sum = 0;
        int dist_left = n;
        int tot_cost = 0;
        for (auto i : map)
        {
            if (dist_left == 0)
                break;
            int dist = min((int)i.second, dist_left);
            dist_left -= dist;
            cout << dist << " " << dist_left;
            tot_cost += i.first * dist;
        }
        cout << tot_cost << "\n";
    }
}
