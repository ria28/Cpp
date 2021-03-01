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

int getMaxGold(vector<vector<int>> &mat, int m, int n)
{
    int one = 0, two = 0, three = 0;
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            if (i - 1 >= 0 && j + 1 < n)
                one = mat[i - 1][j + 1];
            if (j + 1 < n)
                two = mat[i][j + 1];
            if (i + 1 < m && j + 1 < n)
                three = mat[i + 1][j + 1];

            mat[i][j] += max(one, max(two, three));

            // mat[i][j] += max(mat[i - 1][j + 1], max(mat[i][j + 1], mat[i + 1][j + 1]));
        }
    }
    int ma = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        // cout << mat[i][0] << " ";
        ma = max(ma, mat[i][0]);
    }
    return ma;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    vector<vector<int>> mat = {{1, 3, 1, 5},
                               {2, 2, 4, 1},
                               {5, 0, 2, 3},
                               {0, 6, 1, 2}};
    int m = 4, n = 4;
    cout << getMaxGold(mat, m, n);
    return 0;
}