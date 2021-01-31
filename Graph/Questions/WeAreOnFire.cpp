// not working//////-------------

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
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    ll n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> grid(n + 1, vector<int>(m + 1));
    queue<ll> que;
    ll cnt = 0;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 1)
            {
                // que.push(i * m + j);
                cnt++;
            }
        }
    }
    // cout<<"geoo";
    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    while (q--)
    {
        ll x, y;
        cin >> x >> y;

        if (grid[x][y] == 0)
        {
            cout << cnt << "\n";
            // continue;
        }
        else
        {
            que.push((x - 1) * m + (y - 1));
            while (!que.empty())
            {
                ll cur = que.front();
                ll cur_x = (cur / m) + 1;
                ll cur_y = (cur % m) + 1;
                cnt--;
                // cout << cur_x << "," << cur_y << "\n";
                grid[cur_x][cur_y] = 0;
                que.pop();
                for (int i = 0; i < 4; i++)
                {
                    ll new_x = cur_x + dir[i][0];
                    ll new_y = cur_y + dir[i][1];

                     
                    if (new_x > 0 && new_y > 0 && new_x <= n && new_y <= m && grid[new_x][new_y] == 1)
                    {  
                        // cout << "neww: " << new_x << "," << new_y << "\n";
                        que.push((new_x-1) * m + (new_y-1));
                    }
                }
            }
            cout << cnt << "\n";
        }
    }
    return 0;
}