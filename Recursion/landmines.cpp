#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;

int ma = INT32_MAX;
bool path(vector<vector<int>> &mat, vector<vector<int>> &vis, int i, int j, int cnt)
{
    cout << i << " " << j << "\n";
    if (j == mat[0].size() - 1)
    {
        cout << "he" << cnt << "\n";

        // if (cnt < ma)
        // {
        //     ma = cnt;
        //     cout << cnt << " ";
        // }
        return true;
    }

    if (vis[i][j] == 1)
    {
        bool check = false;
        if (j + 1 < mat[0].size() && vis[i][j + 1] == 1)
        {
            check = true;
            cnt++;
            vis[i][j] = 0;
            bool b = path(mat, vis, i, j + 1, cnt);
            vis[i][j] = 1;
            if (!b)
            {
                cnt--;
                return false;
            }
            else
            {
                return true;
            }
        }
        if (i + 1 < mat.size() && vis[i + 1][j] == 1)
        {
            check = true;
            cnt++;
            vis[i][j] = 0;
            bool b = path(mat, vis, i + 1, j, cnt);
            vis[i][j] = 1;
            if (!b)
            {
                cnt--;
                // return false;
            }
            else
            {
                // return true;
            }
        }
        if (i - 1 >= 0 && vis[i - 1][j] == 1)
        {
            check = true;
            cnt++;
            vis[i][j] = 0;
            bool b = path(mat, vis, i - 1, j, cnt);
            vis[i][j] = 1;
            if (!b)
            {
                cnt--;
                // return false;
            }
            else
            {
                // return true;
            }
        }
        if (j - 1 >= 0 && vis[i][j - 1] == 1)
        {
            check = true;
            cnt++;
            vis[i][j] = 0;
            bool b = path(mat, vis, i, j - 1, cnt);
            vis[i][j] = 1;
            if (!b)
            {
                cnt--;
                // return false;
            }
            else
            {
                // return true;
            }
        }
        if (!check)
        {
            if (i + 1 < mat.size())
                path(mat, vis, i + 1, j, cnt);
            return false;
        }
    }
    else
    {
        if (i + 1 < mat.size())
            path(mat, vis, i + 1, j, cnt);
        return false;
    }
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    vector<vector<int>> mat = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 1, 1, 1, 1, 0, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 1, 1, 1, 1, 1, 1}};
    int r = mat.size();
    int c = mat[0].size();
    vector<vector<int>> vis(r, vector<int>(c, 1));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (mat[i][j] == 0)
            {
                vis[i][j] = 0;
                if (i + 1 < r)
                    vis[i + 1][j] = 0;
                if (i - 1 >= 0)
                    vis[i - 1][j] = 0;
                if (j + 1 < c)
                    vis[i][j + 1] = 0;
                if (j - 1 >= 0)
                    vis[i][j - 1] = 0;
            }
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << vis[i][j] << " ";
        }
        cout << "\n";
    }

    bool b = path(mat, vis, 0, 0, 0);
    // cout<<ma<<" ";

    return 0;
}