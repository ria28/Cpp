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

// https://leetcode.com/problems/minimum-path-sum/

class tri
{
public:
    int row;
    int col;
    string ans;
    tri(int r, int c, string a)
    {
        this->row = r;
        this->col = c;
        this->ans = a;
    }
};

vector<string> res;
void minPathSum(vii &arr)
{
    // BOTTOM UP  --------------------
    // cout<<"geenfwlf";
    vii dp(arr.size(), vi(arr[0].size()));
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        for (int j = arr[0].size() - 1; j >= 0; j--)
        {
            if (i == arr.size() - 1 && j == arr[0].size() - 1)
            {
                dp[i][j] = arr[i][j];
            }
            else if (i == arr.size() - 1)
            {
                dp[i][j] = arr[i][j] + dp[i][j + 1];
            }
            else if (j == arr[0].size() - 1)
            {
                dp[i][j] = arr[i][j] + dp[i + 1][j];
            }
            else
            {
                dp[i][j] = arr[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }

    // for (int i = 0; i < dp.size(); i++)
    // {
    //     for (auto j : dp[i])
    //         cout << j << " ";
    //     cout << "\n";
    // }
    
    // printing paths with min cost  -------- REVERSE  ENGINEERING  -----BFS BREADTH FIRST SEARCH
    string ans = "";
    queue<tri> q;

    q.push(tri(0, 0, ""));
    while (q.size() > 0)
    {
        int size = q.size();
        while (size--)
        {
            tri ele = q.front();
            int row = ele.row;
            int col = ele.col;
            string str = ele.ans;
            // cout << row << " " << col << " " << str << "\n";
            q.pop();
            if (row == arr.size() - 1 && col == arr[0].size() - 1) // dest
            {
                // cout << "dest" << str << "\n";
                res.push_back(str);
                // break;
            }
            else if (row == arr.size() - 1)
            {
                q.push({row, col + 1, str + "H"});
            }
            else if (col == arr[0].size() - 1)
            {
                q.push({row + 1, col, str + "V"});
            }
            else
            {
                if (dp[row + 1][col] == dp[row][col + 1])
                {
                    q.push({row + 1, col, str + "V"});
                    q.push({row, col + 1, str + "H"});
                }
                else if (dp[row + 1][col] < dp[row][col + 1])
                {
                    q.push({row + 1, col, str + "V"});
                }
                else
                {
                    q.push({row, col + 1, str + "H"});
                }
            }
        }
    }
    cout << dp[0][0] << "\n";
    for (string str : res)
    {
        cout << str << "\n";
    }
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // vii mat = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    int n, m;
    cin >> n >> m;
    vii mat(n, vi(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    }
    minPathSum(mat);
    return 0;
}