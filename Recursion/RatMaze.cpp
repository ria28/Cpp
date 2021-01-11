#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;

// USING BFS  ----------------------------------------------------
// rat can move fwd and downward
void ratMaze_bfs(vector<vector<int>> &maze)
{
    int n = maze.size(), m = maze[0].size();
    queue<pair<int, int>> q;
    q.push({0, 0});
    int cnt = 0;
    while (!q.empty())
    {
        pair<int, int> xy = q.front();
        q.pop();
        cout<<xy.first<<", "<<xy.second<<"\n";

        if (xy.first == n - 1 && xy.second == m - 1)
        {
            cnt++;
        }

        if (xy.first + 1 < n && maze[xy.first + 1][xy.second] == 1)
        {
            q.push({xy.first + 1, xy.second});
        }
        if (xy.second + 1 < m && maze[xy.first][xy.second + 1] == 1)
        {
            q.push({xy.first, xy.second + 1});
        }
    }
    cout << cnt << "";
}

// BACKTRACKING----------------------------------------------------
void print(vector<vector<int>> &ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}

bool ratMaze_3(vector<vector<int>> &maze, int n, int i, int j, vector<vector<int>> &ans)
{
    // cout << i << "." << j << "\n";
    if (i == n - 1 && j == n - 1)
    {
        ans[i][j] = 1;
        print(ans);
        return true;
    }
    if (maze[i][j] != 0)
    {
        for (int c = 1; c <= maze[i][j]; c++)
        {
            bool row;
            bool col;
            if (i + c < n && maze[i + c][j] != 0)
            {
                ans[i][j] = 1;
                row = ratMaze_3(maze, n, i + c, j, ans);
                if (!row)
                {
                    ans[i][j] = 0;
                    return false;
                }
            }
            if (j + c < n && maze[i][j + c] != 0)
            {
                ans[i][j] = 1;
                col = ratMaze_3(maze, n, i, j + c, ans);
                if (!col)
                {
                    ans[i][j] = 0;
                    return false;
                }
            }
        }
    }
    else
    {
        return false;
    }
}

// rat travels in all 4 dir: up,right,down,left
vector<vector<int>> dir{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool ratMaze_2(vector<vector<int>> &maze, int n, int i, int j, string asf)
{
    if (i == n - 1 && j == n - 1)
    {
        cout << asf << "\n";
        return true;
    }
    if (maze[i][j] == 1) // no need for vis
    {
        // vis[i][j] = true;
        maze[i][j] = 0; // SO THAT IT DOES NOT GO BACK TO THE SAME POINT WHILE REACHING DEST.
        for (int d = 0; d < 4; d++)
        {
            int new_i = i + dir[d][0];
            int new_j = j + dir[d][1];
            if (new_i < 0 || new_j < 0)
                continue;
            if (maze[new_i][new_j] == 1)
            {
                // cout << new_i << "." << new_j << "\n";
                // vis[new_i][new_j] = true;
                if (new_i > i)
                {
                    asf += 'D';
                }
                else if (new_i < i)
                {
                    asf += 'U';
                }
                else if (new_j < j)
                {
                    asf += 'L';
                }
                else
                {
                    asf += 'R';
                }
                bool is = ratMaze_2(maze, n, new_i, new_j, asf);
                if (!is)
                {
                    if (!asf.empty())
                    {
                        asf.pop_back();
                    }
                    // return false;
                }
                // vis[new_i][new_j] = false;
            }
        }
        // vis[i][j] = false;
        maze[i][j] = 1;
    }
    else
    {
        return false;
    }
}

// rat travels only in right and down dir
bool ratMaze(vector<vector<int>> &maze, int n, int i, int j, vector<vector<int>> &ans)
{
    if (i == n - 1 && j == n - 1)
    {
        ans[i][j] = 1;
        print(ans);
        return true;
    }
    if (maze[i][j] == 1)
    {
        bool row;
        if (i + 1 < n && maze[i + 1][j] == 1)
        {
            ans[i][j] = 1;
            row = ratMaze(maze, n, i + 1, j, ans);
            if (!row)
            {
                ans[i][j] = 0;
                return false;
            }
        }
        bool col;
        if (j + 1 < n && maze[i][j + 1] == 1)
        {
            ans[i][j] = 1;
            col = ratMaze(maze, n, i, j + 1, ans);
            if (!col)
            {
                ans[i][j] = 0;
                return false;
            }
        }
    }
    else
    {
        return false;
    }
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    // SOURCE AND DESTINATON SHOULD BE BY DEFAULT 1. O/W RETURN -1---> BASE CONDITION ADD IF NOT SPECIFIED

    // vector<vector<int>> maze{{1, 0, 0, 0},
    //                          {1, 1, 1, 0},
    //                          {0, 1, 0, 0},
    //                          {1, 1, 1, 1}};
    // int n = maze.size();
    // vector<vector<int>> ans(n, vector<int>(n, 0));
    // ratMaze(maze, n, 0, 0, ans);

    //https://www.geeksforgeeks.org/rat-in-a-maze-problem-when-movement-in-all-possible-directions-is-allowed/?ref=rp
    // vector<vector<int>> maze{{1, 0, 0, 0, 0},
    //                          {1, 1, 1, 1, 1},
    //                          {1, 1, 1, 0, 1},
    //                          {0, 0, 0, 0, 1},
    //                          {0, 0, 0, 0, 1}};
    // int n = maze.size();
    // vector<vector<bool>> vis(n, vector<bool>(n, 0));
    // // vis[0][0] = true;
    // ratMaze_2(maze, n, 0, 0, "");
    // DDRRURRDDD DDRURRRDDD DRDRURRDDD DRRRRDDD


    // vector<vector<int>> maze{{2, 1, 0, 0},
    //                          {3, 0, 0, 1},
    //                          {0, 1, 0, 1},
    //                          {0, 0, 0, 1}};
    // int n = maze.size();
    // vector<vector<int>> vis(n, vector<int>(n, 0));
    // ratMaze_3(maze, n, 0, 0, vis);


    vector<vector<int>> maze = {{1, 0, 0, 1},
                                  {1, 1, 1, 1},
                                  {1, 0, 1, 1}};
    ratMaze_bfs(maze);
    return 0;
}