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
    Node *arb;
    Node(int x)
    {
        this->data = x;
    }
};


// based on position
Node *rearrangeEvenOdd(Node *head)
{
    Node *odd = head;
    Node *even = head->next;

    Node *odd_head = odd;
    Node *even_head = even;
    while (odd->next != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = even_head;
    return odd_head;
}

// on the basis of data / value of node
Node *divide(int N, Node *head)
{
    Node *odd = new Node(0);
    Node *even = new Node(0);

    Node *odd_ = odd;
    Node *even_ = even;
    while (head != NULL)
    {
        if (head->data % 2 == 0)
        {
            even->next = new Node(head->data);
            even = even->next;
        }
        else
        {
            odd->next = new Node(head->data);
            odd = odd->next;
        }

        head = head->next;
    }
    even_ = even_->next;
    odd_ = odd_->next;
    if (even_ == NULL)
        return odd_;
    else
        even->next = odd_;

    return even_;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}