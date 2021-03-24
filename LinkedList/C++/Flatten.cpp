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

struct Node
{
    int data;
    Node *next;
    Node *bottom;
    Node(int x)
    {
        this->data = x;
        this->next = NULL;
        this->bottom = NULL;
    }
};

Node *merge2sorted_LL(Node *a, Node *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    Node *result = new Node(0);
    // Node * ptr = result;
    if (a->data < b->data)
    {
        result = a;
        result->bottom = merge2sorted_LL(a->bottom, b);
    }
    else
    {
        result = b;
        result->bottom = merge2sorted_LL(a, b->bottom);
    }
    result->next = NULL;
    return result;
}

Node *flatten(Node *root)
{
    if (root == NULL || root->next == NULL)
        return root;

    //   Node * rhs = flatten(root->next);
    return merge2sorted_LL(root, flatten(root->next));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}