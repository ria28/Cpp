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

#define MAX 20

struct Node
{
    int data;
    Node *right;
    Node *down;
    Node(int x)
    {
        this->data = x;
        this->right  = NULL;
        this->down = NULL;
    }
};

Node *construct(int mat[MAX][MAX], int i, int j, int n)
{
    if (i >= n || j >= n)
        return NULL;

    Node *res = new Node(mat[i][j]);
    res->right = construct(mat, i, j + 1, n);
    res->down = construct(mat, i + 1, j, n);
    return res;
}

Node *constructLinkedMatrix(int mat[MAX][MAX], int n)
{
    return construct(mat, 0, 0, n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}