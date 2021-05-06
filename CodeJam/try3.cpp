#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#define ll long long
using namespace std;
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)
#define vi vector<int>
#define vii vector<vector<int>>
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    int T = 1;
    while (T <= t)
    {
        int n, cost;
        cin >> n >> cost;
        cout << "Case #" << T << ": ";
        if (cost < n - 1 || cost > (n * (n + 1) / 2) - 1)
        {
            cout << "IMPOSSIBLE\n";
        }
        else
        {
            cost = cost - (n - 1);
            vi mi(n - 1);
            for (int i = 0; i < n - 1; i++)
                mi[i] = 1;

            int i = 0;
            while (cost != 0 && i < n - 1)
            {
                int ml = n - 1 - i;
                if (ml <= cost)
                {
                    mi[i] += ml;
                    cost -= ml;
                }
                else
                {
                    mi[i] += cost;
                    cost -= cost;
                }
                i++;
            }
            vi ans(n);
            for (int i = 1; i <= n; i++)
            {
                ans[i - 1] = i;
            }
            for (int i = n - 2; i >= 0; i--)
            {
                int end = i + mi[i] - 1;
                reverse(ans.begin() + i, ans.begin() + end + 1);
            }
            for (int i : ans)
                cout << i << " ";
            cout << "\n";
        }

        T++;
    }
    return 0;
}
