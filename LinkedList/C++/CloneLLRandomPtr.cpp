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

Node *copyList(Node *head)
{

    // create copy of node in between
    if (head == NULL)
        return head;

    Node *curr = head;
    Node *temp = NULL;
    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = new Node(curr->data);
        curr->next->next = temp;
        curr = temp;
    }
    curr = head;

    // creating arb pointers of copy list
    while (curr != NULL)
    {
        curr->next->arb = (curr->arb != NULL) ? curr->arb->next : NULL;
        curr = (curr->next != NULL) ? curr->next->next : NULL;
    }

    Node *ori = head;
    Node *copy = head->next;
    temp = copy;

    while (ori != NULL && copy != NULL)
    {
        ori->next = (ori->next != NULL) ? ori->next->next : NULL;
        copy->next = (copy->next != NULL) ? copy->next->next : NULL;

        ori = ori->next;
        copy = copy->next;
    }
    return temp;
    // Your code here
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}