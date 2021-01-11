#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k, x, y;
        cin >> n >> k >> x >> y;
        vector<pair<int, int>> arr(4);
        if (x == y)
        {
            cout << x << " " << y << " ";
        }
        else
        {
            if (x < y)
            {
                arr = {{x + n - y, n}, {n, n - y + x}, {y - x, 0}, {0, y - x}};
            }
            else
            {
                arr = {{n, y + n - x}, {y + n - x, n}, {0, x - y}, {x - y, 0}};
            }
            ll rem = (k - 1) % 4;
            pair<int, int> p = arr[rem];
            cout << p.first << " " << p.second;
        }
    }
    return 0;
}