#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;

// https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/connected-horses-10/editorial/
// modulo  with 1e9 +7 (prime and prevents integer overflow)
vector<ll> factorial(1000000+1);
void fact()
{
    factorial[0] = 1;
    for (ll i = 1; i <= 1000000; i++)
    {
        factorial[i] = (factorial[i - 1] * i)%1000000007;
    }
}

vector<vector<int>> dirs = {{-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}};
ll cnt = 0;
void dfs(vector<vector<int>> &mat, ll i, ll j)
{
    // cout << i << " " << j << "\n";
    mat[i][j] = -1;
    cnt++;
    for (int d = 0; d < 8; d++)
    {
        ll new_x = i + dirs[d][0];
        ll new_y = j + dirs[d][1];

        // cout << new_x << " " << new_y << "\n";
        if (new_x >= 1 && new_y >= 1 && new_x < mat.size() && new_y < mat[0].size() && mat[new_x][new_y] == 1)
        {
            // cout<<"hello";
            // cout << new_x << " " << new_y << "\n";
            dfs(mat, new_x, new_y);
        }
    }
    // return cnt;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin >> t;
    fact();
    while (t--)
    {
        ll n, m, horses;
        cin >> n >> m >> horses;
        vector<vector<int>> mat(n + 1, vector<int>(m + 1, 0)); // 0 --> empty  1---> horse is there but not vis -1---> vis
        for (ll i = 0; i < horses; i++)
        {
            ll x, y;
            cin >> x >> y;
            mat[x][y] = 1;
        }
        ll ans = 1;
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= m; j++)
            {
                if (mat[i][j] == 1)
                {
                    cnt = 0;
                    dfs(mat, i, j);
                    // cout << cnt << " ";
                    // cout << factorial[cnt] << " ";      
                    ans = ans * (factorial[cnt])%1000000007;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}