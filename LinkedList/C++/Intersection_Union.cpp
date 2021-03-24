#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include<set>
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
    Node *arb;
    Node(int x)
    {
        this->data = x;
    }
};

Node *findIntersection(Node *head1, Node *head2)
{
    unordered_set<int> set;
    int s1 = 0;
    int s2 = 0;
    Node *h1 = head1;
    Node *h2 = head2;
    Node *ans = new Node(0);
    Node *ptr = ans;
    while (head2 != NULL)
    {
        set.insert(head2->data);
        head2 = head2->next;
    }

    while (head1 != NULL)
    {
        if (set.find(head1->data) != set.end())
        {
            ans->next = new Node(head1->data);
            ans = ans->next;
        }
        head1 = head1->next;
    }

    return ptr->next;
}

struct Node *makeUnion(struct Node *h1, struct Node *h2)
{
    set<int> set;
    while (h1 != NULL)
    {
        // if(set.find(h1->data) == set.end())
        // {
        set.insert(h1->data);
        // }
        h1 = h1->next;
    }

    while (h2 != NULL)
    {
        set.insert(h2->data);
        h2 = h2->next;
    }
    Node *node = new Node(0);
    Node *ptr = node;

    for (auto i : set)
    {
        node->next = new Node(i);
        node = node->next;
    }
    return ptr->next;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}