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

// https://leetcode.com/problems/minimum-path-sum/

int minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> tab(n + 1, vector<int>(m + 1, INT_MAX));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            tab[i][j] = min(tab[i + 1][j], tab[i][j + 1]) + grid[i][j];
        }
    }
    return tab[0][0];
}

// without using an extra space
int minPathSum_(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (i == n - 1 && j == m - 1)
            {
                continue;
            }

            int c1 = j + 1 < m ? arr[i][j + 1] : 1e6;
            int c2 = i + 1 < n ? arr[i + 1][j] : 1e6;

            int minCost = min(c1, c2);
            arr[i][j] += minCost;
        }
    }

    return arr[0][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //     Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
    // Output: 7
    // Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

    //     Input: grid = [[1,2,3],[4,5,6]]
    // Output: 12
    return 0;
}