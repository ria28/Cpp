#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

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
        sort(map.begin(), map.end()); // sorted on te basis of cost
        int sum = 0;
        int ans = 0;
        for (auto i : map)
        {
            if (sum + i.second <= n)
            {
                sum += i.second;
                ans += i.first * i.second;
            }
            else
            {
                ans += (n - sum) * i.first;
                break;
            }
        }
        cout << ans << "\n";
    }
}
