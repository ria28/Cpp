#include <iostream>
#include <vector>
using namespace std;

static int max_gold = INT32_MIN;
static int bag = 0;
// static int result = 0;
int dfs_Leet(vector<vector<int>> arr, int i, int j) //, vector<vector<bool>> vis)
{
    int result=0;
    vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    // vis[i][j] = true;
    int temp = arr[i][j];
    arr[i][j]=0;
    bool flag = false;
    for (int d = 0; d < directions.size(); d++)
    {
        int x = i + directions[d][0];
        int y = j + directions[d][1];
        if (x >= 0 && y >= 0 && x < arr.size() && y < arr[0].size() && arr[x][y] != 0)
        {
            flag = true;
            // cout << dfs_Leet(arr, x, y, vis) << " ";
            result = max(result, arr[x][y] + dfs_Leet(arr, x, y));
            cout<<arr[i][j]<<"-->"<<result<<" ";
        }
    }
    // vis[i][j] = false;
    arr[i][j]=temp;
    return result;
}
void dfs_(vector<vector<int>> arr, int i, int j, vector<vector<bool>> vis)
{
    if (i < 0 || j < 0 || i > arr.size() || j > arr[0].size() || arr[i][j] == 0 || vis[i][j])
        return;
    vis[i][j] = true;
    bag += arr[i][j];

    dfs_(arr, i - 1, j, vis);
    dfs_(arr, i, j + 1, vis);
    dfs_(arr, i + 1, j, vis);
    dfs_(arr, i, j - 1, vis);
}

void goldmine(vector<vector<int>> arr)
{
    // vector<vector<bool>> vis(arr.size(), vector<bool>(arr[0].size(), 0));
    int res_ = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            if (arr[i][j] != 0)
            {
                // bag = 0;
                // dfs_(arr, i, j, vis);
                // cout<<bag;
                // max_gold = max(max_gold, bag);
                // cout<<max_gold<<"   ";

                // result =0;
                res_ = max(res_,arr[i][j]+ dfs_Leet(arr, i, j));
                cout<<"\n";
            }
        }
    }

    // cout << max_gold;
    cout << res_;
}

void dfs(int i, int n)
{
    if (i > n)
        return;

    cout << i << " ";
    for (int j = 0; j <= 9; j++)
    {
        dfs(10 * i + j, n);
    }
}
void lexicographical_order(int n)
{
    for (int i = 1; i <= 9; i++)
        dfs(i, n);
}

int josephus_prob(int n, int k)
{
    if (n == 1)
        return 0;
    int x = josephus_prob(n - 1, k);
    int y = (x + k) % n;
    return y;
}

void printBoard(vector<vector<string>> board)
{
    // cout<<"hello";
    // for(int k =0; k<board.size();k++)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
vector<vector<string>> res;
void solve_nQueen(vector<vector<string>> board, vector<bool> cols, vector<bool> diag, vector<bool> adiag, int row)
{
    if (row == board.size())
    {
        vector<string> add;
        string ans = "";
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                ans += board[i][j];
            }
            add.push_back(ans);
            ans = "";
        }
        res.push_back(add);
        // return board;
    }
    for (int col = 0; col < board[0].size(); col++)
    {
        if (!cols[col] && !diag[col + row] && !adiag[row - col + board.size() - 1])
        {
            cols[col] = true;
            diag[col + row] = true;
            adiag[row - col + board.size() - 1] = true;
            board[row][col] = "Q";
            solve_nQueen(board, cols, diag, adiag, row + 1);
            cols[col] = false;
            diag[col + row] = false;
            adiag[row - col + board.size() - 1] = false;
            board[row][col] = ".";
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<bool> col(n, false);
    vector<bool> diag(2 * n - 1, false);  //    " / "
    vector<bool> adiag(2 * n - 1, false); //    " \  "
    vector<vector<string>> board(n, vector<string>(n, "."));
    solve_nQueen(board, col, diag, adiag, 0);

    printBoard(res);
    return res;
}

// https://leetcode.com/problems/sudoku-solver/
void printMat(vector<vector<int>> &board)
{
    char a = '1';
    int i = a - '0';
    cout << i << "\n";
    int no = 9;
    char b = (char)('0' + no);
    cout << b;
    for (int i = 0; i < board.size(); i++) // column check
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            cout << board[i][j] << ", ";
        }
        cout << "\n";
    }
}
bool isSafe(vector<vector<int>> &board, int num, int x, int y)
{
    for (int i = 0; i < board.size(); i++) // column check
    {
        if (board[i][y] == num)
            return false;
    }
    for (int j = 0; j < board[0].size(); j++)
    {
        if (board[x][j] == num)
            return false;
    }
    int sm_x = 3 * (x / 3);
    int sm_y = 3 * (y / 3);
    for (int i = sm_x; i < 3; i++)
    {
        for (int j = sm_y; j < 3; j++)
        {
            if (board[i][j] == num)
                return false;
        }
    }

    return true;
}
bool sudoku(vector<vector<int>> &board, int idx)
{
    if (idx == board.size() * board[0].size())
    {
        printMat(board);
        return true;
    }
    bool res = false;
    // cout<<idx<<;
    int x = idx / board[0].size();
    int y = idx % board[0].size();

    if (board[x][y] == 0)
    {
        for (int i = 1; i <= 9; i++)
        {
            if (isSafe(board, i, x, y))
            {
                board[x][y] = i;
                res = res || sudoku(board, idx + 1); // ensure as soon as we get one solution simply return
                if (res)
                    return true;

                board[x][y] = 0;
            }
        }
    }
    else
    {
        res = res || sudoku(board, idx + 1);
    }
    return res;
}

int main()
{
    vector<vector<int>> board = {{0, 0, 6, 0, 0, 8, 0, 0, 0},
                                 {5, 2, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 8, 7, 0, 0, 0, 0, 3, 1},
                                 {0, 0, 3, 0, 1, 0, 0, 8, 0},
                                 {9, 0, 0, 8, 6, 3, 0, 0, 5},
                                 {0, 5, 0, 0, 9, 0, 6, 0, 0},
                                 {1, 3, 0, 0, 0, 0, 2, 5, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 7, 4},
                                 {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    // sudoku(board, 0);

    // solveNQueens(4);

    // cout << josephus_prob(5, 3);

    // lexicographical_order(1000);

    // vector<vector<int>> mat = {{1, 0, 7},
    //                            {2, 0, 6},
    //                            {3, 4, 5},
    //                            {0, 3, 0},
    //                            {9, 0, 20}};

    vector<vector<int>> mat = {
        {0, 6, 0},
        {5, 8, 7},
        {0, 9, 0},
    };
    goldmine(mat);
    return 0;
}