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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll pos = 0, neg = 0, single = 0, multiple = 0;
        unordered_map<int, pair<int, int>> map; // ori no , nth line-> which line , freq
        for (ll i = 0; i < n; i++)
        {
            pos = 0;
            neg = 0;
            ll m;
            cin >> m;
            vector<ll> ail(m); // ants in a particular line

            for (ll j = 0; j < m; j++)
            {
                cin >> ail[j];
                if (ail[j] > 0)
                    pos++;
                else
                    neg++;

                if (map.find(abs(ail[j])) == map.end())
                {
                    pair<int, int> p;
                    p.first = i;
                    p.second = 1;
                    map[abs(ail[j])] = p;
                }
                else if (map[abs(ail[j])].first != i && map[abs(ail[j])].second == 1) // not in the same line
                {
                    // map[ail[j]]++;
                    multiple++;
                    map[abs(ail[j])].first = i;
                    map[abs(ail[j])].second += 1;
                }
                else
                {
                    continue;
                }
            }

            single += pos * neg;
        }
        if (n == 1)
        {
            cout << single << "\n";
            break;
        }
        else
        {
            ll res = single;
            cout << res << multiple << "\n";
        }

        // cout << (pos * neg) << "\n";
    }
    return 0;
}