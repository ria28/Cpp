#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, u, q;
    cin >> n >> m >> u >> q;
    vector<vector<int>> arr(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];

    vector<vector<int>> presum(n + 1, vector<int>(m + 1, 0));
    while (u--)
    {
        int k, r1, r2, c1, c2;
        cin >> k >> r1 >> c1 >> r2 >> c2;
        r1++, r2++, c1++, c2++;
        presum[r1][c1] += k;
        presum[r2 + 1][c2 + 1] += k;

        presum[r1][c2 + 1] -= k;
        presum[r2 + 1][c1] -= k;
    }

    // sum from top to down
    for (int j = 1; j <= m; j++)
    {
        for (int i = 2; i <= n; i++)
        {
            presum[i][j] += presum[i - 1][j];
        }
    }

    // left to right
    for (int i = 1; i <= n; i++)
    {
        for (int j = 2; j <= m; j++)
        {
            presum[i][j] += presum[i][j - 1];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            presum[i][j] += arr[i][j];
            cout << presum[i][j] << " ";
        }

        cout << "\n";
    }

    // sum from top to down
    for (int j = 1; j <= m; j++)
    {
        for (int i = 2; i <= n; i++)
        {
            presum[i][j] += presum[i - 1][j];
        }
    }

    // //left to right
    for (int i = 1; i <= n; i++)
    {
        for (int j = 2; j <= m; j++)
        {
            presum[i][j] += presum[i][j - 1];
        }
    }

    while (q--)
    {
        int r1, r2, c1, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1++, c1++, r2++, c2++;
        int up = 0, left = 0, intersection = 0;

        if (r1 - 1 >= 0)
            up = presum[r1 - 1][c2];
        if (c1 - 1 >= 0)
            left = presum[r2][c1 - 1];
        if (r1 - 1 >= 0 && c1 - 1 >= 0)
            intersection = presum[r1 - 1][c1 - 1];

        int ans = presum[r2][c2] - (up + left - intersection);
        cout << ans << "\n";
    }
}