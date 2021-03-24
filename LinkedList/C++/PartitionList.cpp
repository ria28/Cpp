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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *partition(ListNode *head, int x)
{

    // if(head == NULL || head->next == NULL)
    //     return head;

    ListNode *a = new ListNode(0);
    ListNode *b = new ListNode(0);

    ListNode *a_head = a;
    ListNode *b_head = b;

    while (head != NULL)
    {
        if (head->val < x)
        {
            a->next = head;
            a = a->next;
        }
        else
        {
            b->next = head;
            b = b->next;
        }
        head = head->next;
    }

    b->next = NULL;
    a_head = a_head->next;
    b_head = b_head->next;

    if (a_head == NULL)
    {
        return b_head;
    }
    else if (b_head == NULL)
    {
        return a_head;
    }

    a->next = b_head;
    // while(a_head !=  NULL)
    //       {
    //             cout<<a_head->val<<" ";
    //           a_head= a_head->next;
    //       }
    return a_head;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}