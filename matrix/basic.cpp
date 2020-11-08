#include <iostream>
#include <vector>
#include<queue>
using namespace std;

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
        for (i = l; i < n; ++i)
            a[k][i] = x;
        k++;

        for (i = k; i < m; ++i)
            a[i][n - 1] = x;
        n--;

        if (k < m)
        {
            for (i = n - 1; i >= l; --i)
                a[m - 1][i] = x;
            m--;
        }
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
    priority_queue<int, vector<int>, greater<int>>min_heap;
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
    fill0X(5, 6);
}