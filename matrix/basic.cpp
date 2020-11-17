#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

#define M 4
#define N 5

using namespace std;

// https://leetcode.com/problems/word-search/
bool exist(vector<vector<char>> &board, string word)
{
    int rows = board.size();
    int col = board[0].size();
    vector<vector<bool>> vis(rows, vector<bool>(col, false));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (word[0] == board[i][j] && searchWord(i, j, 0, word, board, vis))
                return true;
        }
    }
    return false;
}
bool searchWord(int i, int j, int idx, string word, vector<vector<char>> board, vector<vector<bool>> vis)
{
    if (idx == board.size())
        return true;

    if (i < 0 || i > board.size() || j < 0 || j > board[0].size() || !vis[i][j] || word[idx] != board[i][j])
        return false;

    vis[i][j] = true;
    if (
        searchWord(i + 1, j, idx + 1, word, board, vis) ||
        searchWord(i - 1, j, idx + 1, word, board, vis) ||
        searchWord(i, j + 1, idx + 1, word, board, vis) ||
        searchWord(i, j - 1, idx + 1, word, board, vis) )
        return true;
    vis[i][j]=false;
    return false;
}

// https://www.geeksforgeeks.org/a-boolean-matrix-question/
// https://leetcode.com/problems/set-matrix-zeroes/
void modifyMat(int mat[][])
{
    bool row = false;
    bool col = false;

    for (int i = 0; i < 3; i++)
    {
        for (int j = -0; j < mat[0].size(); j++)
        {
            if (i == 0 && mat[i][j] == 1)
                row = true;
            if (j == 0 && mat[i][j] == 1)
                col = true;

            if (mat[i][j] == 0)
            {
                mat[0][j] = 1;
                mat[i][0] = 1;
            }
        }
    }

    for (int i = 1; i < 3; i++)
    {
        for (int j = 1; j < mat[0].size(); j++)
        {
            if (mat[0][j] == 0 || mat[i][0] == 0)
            {
                mat[i][j] = 1;
            }
        }
    }

    int R = 3, C = 4;
    if (row)
        for (int i = 0; i < C; i++)
            mat[0][i] = 1;

    if (col)
        for (int i = 0; i < R; i++)
            mat[i][0] = 1;
}

// https://leetcode.com/problems/shortest-path-in-binary-matrix/submissions/
int shortestPathBinaryMatrix(vector<vector<int>> &A)
{
    int row = A.size();
    int col = A[0].size();
    if (row == 0 || col == 0 || A[0][0] == 1)
        return -1;

    int dir[8][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    A[0][0] = 1;

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        if (curr.first == A.size() - 1 && curr.second == A.size() - 1)
            return A[curr.first][curr.second];

        for (int i = 0; i < 8; i++)
        {
            int nx = curr.first + dir[i][0];
            int ny = curr.second + dir[i][1];

            if (nx >= 0 && ny >= 0 && nx < row && ny < col && A[nx][ny] == 0)
            {
                q.push(make_pair(nx, ny));
                A[nx][ny] = A[curr.first][curr.second] + 1;
            }
        }
    }
    return -1;
}

//https://www.geeksforgeeks.org/find-common-element-rows-row-wise-sorted-matrix/
int findEle(int mat[M][N])
{
    unordered_map<int, int> map;
    for (int i = 0; i < M; i++)
    {
        map[mat[i][0]]++;
        for (int j = 1; j < N; j++)
        {
            if (mat[i][j - 1] != mat[i][j])
                map[mat[i][j]]++;
        }
    }

    for (auto itr : map)
    {
        if (itr.second == M)
            return itr.first;
    }
    return -1;
}

// https://leetcode.com/problems/diagonal-traverse/
vector<int> findDiagonalOrder(vector<vector<int>> &matrix) //zig zag
{
    vector<int> res;
    if (matrix.size() == 0)
        return res;

    int r = 0, c = 0, m = matrix.size(), n = matrix[0].size();

    for (int i = 0; i < m * n; i++)
    {
        res.push_back(matrix[r][c]);
        if ((r + c) % 2 == 0)
        {
            if (c == n - 1)
                r++;
            else if (r == 0)
                c++;
            else
            {
                r--;
                c++;
            }
        }
        else
        {

            if (r == m - 1)
                c++;
            else if (c == 0)
                r++;
            else
            {
                c--;
                r++;
            }
        }
    }
    return res;
}

void fill0X(int m, int n)
{
    int i, k = 0, l = 0;
    int r = m, c = n;

    // char a[m]][n];
    char a[5][6];
    char x = 'X';

    while (k < m && l < n)
    {
        //first row
        for (i = l; i < n; ++i)
            a[k][i] = x;
        k++;

        // last col
        for (i = k; i < m; ++i)
            a[i][n - 1] = x;
        n--;

        //last row
        if (k < m)
        {
            for (i = n - 1; i >= l; --i)
                a[m - 1][i] = x;
            m--;
        }

        //first col
        if (l < n)
        {
            for (i = m - 1; i >= k; --i)
                a[i][l] = x;
            l++;
        }

        x = (x == '0') ? 'X' : '0';
    }

    for (i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            printf("%c ", a[i][j]);
        printf("\n");
    }
}

// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
int kthSmallest(vector<vector<int>> matrix, int k) // create ur own min heap***************DISCLAIMER :( ****
{
    // PriorityQueue<Integer> min_heap = new PriorityQueue<Integer>();  java
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            min_heap.push(matrix[i][j]);
        }
    }
    while (k > 1)
    {
        min_heap.pop();
        k--;
    }
    return min_heap.top();
}

int main()
{
    vector<vector<int>> mat{{1, 2, 3},
                            {4, 5, 6},
                            {7, 8, 9}};
    findDiagonalOrder(mat);
    // fill0X(5, 6);

    int mat2[M][N] = {
        {1, 2, 3, 4, 5},
        {2, 4, 5, 8, 10},
        {3, 5, 7, 9, 11},
        {1, 3, 5, 7, 9},
    };
    cout << findEle(mat2);
}