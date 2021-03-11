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

vector<long long> matrixQueries(int n, int m, vector<vector<int>> queries)
{
    vector<vector<int>> mat(n + 1, vector<int>(m + 1));
    vector<int> row(n);
    vector<int> col(n);
    priority_queue
    for (int i = 1; i <= n; i++)
    {
        int mi_c = INT_MAX;
        for (int j = 1; j <= m; j++)
        {
            mat[i][j] = i * j;
            mi_c = min(mi_c, mat[i][j]);
        }
    }




}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}