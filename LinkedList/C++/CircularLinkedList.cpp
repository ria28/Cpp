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

void deleteNode(struct Node **head, int key)
{
    // reverse(head);

    Node *temp = *head;
    bool b = false;
    do
    {
        if (temp->next->data == key)
        {
            temp->next = temp->next->next;
        }
        temp = temp->next;
    } while (*head != temp);

    // Node * hh = *head;
    // do{
    //     cout<<(hh)->data <<" ";
    //     hh= (hh)->next;
    // }
    // while(*head != hh);
}

/* Function to reverse the linked list */
void reverse(struct Node **head)
{
    Node *curr = *head;
    Node *prev = NULL;
    Node *next;
    Node *temp = *head;

    do
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;

    } while (temp != *head);

    (*head)->next = prev;
    *head = prev;

    // do{
    //     cout<<(*head)->data <<" ";
    //     *head= (*head)->next;
    // }
    // while(*head != prev);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}