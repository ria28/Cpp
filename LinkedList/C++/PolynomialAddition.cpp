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
    int coeff;
    int pow;
    struct Node *next;

    Node(int c, int p)
    {
        coeff = c;
        pow = p;
        next = NULL;
    }
};

Node *addPolynomial(Node *p1, Node *p2)
{
    Node *res = new Node(0, 0);
    Node *dummy = res;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->pow == p2->pow)
        {
            int sum = p1->coeff + p2->coeff;
            res->next = new Node(sum, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->pow < p2->pow)
        {
            res->next = p2;
            p2 = p2->next;
        }
        else
        {
            res->next = p1;
            p1 = p1->next;
        }
        res = res->next;
    }

    while (p2)
    {
        res->next = p2;
        res = res->next;
        p2 = p2->next;
    }

    while (p1)
    {
        res->next = p1;
        res = res->next;
        p1 = p1->next;
    }

    dummy = dummy->next;
    return dummy;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}