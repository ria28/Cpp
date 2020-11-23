#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/sudoku-solver/
void printMat(vector<vector<int>> &board)
{
    char  a='1';
    int i =a-'0';
    cout<<i<<"\n";   
    int no =9;
    char b = (char)('0'+no);
    cout<<b; 
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
                res = res || sudoku(board, idx + 1);  // ensure as soon as we get one solution simply return
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

    sudoku(board, 0);
    return 0;
}