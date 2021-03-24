#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;
#include <vector>
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

int carry = 0;
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL && l2 == NULL)
    {
        return NULL;
    }
    else if (l1 == NULL)
    {
        int temp = carry;
        carry = 0;
        return addTwoNumbers(l2, new ListNode(temp));
    }
    else if (l2 == NULL)
    {
        int temp = carry;
        carry = 0;
        return addTwoNumbers(l1, new ListNode(temp));
    }
    cout << carry << " " << l1->val << " " << l2->val << "\n";
    ListNode *p = new ListNode();
    int sum = l1->val + l2->val + carry;
    p->val = (sum ) % 10;
    if (sum >= 10)
        carry = 1;
    else
        carry = 0;
    p->next = addTwoNumbers(l1->next, l2->next);

    return p;
}

ListNode *construct(vi &arr)
{
    ListNode *head = new ListNode(arr[0]);
    ListNode *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        ListNode *node = new ListNode(arr[i]);
        head->next = node;
        head = head->next;
    }
    return temp;
}

int main()
{
    vi arr1 = {9, 9, 9, 9, 9, 9, 9};
    vi arr2 = {9, 9, 9, 9};

    ListNode *l1 = construct(arr1);
    ListNode *l2 = construct(arr2);

    // ListNode *l1 = new ListNode(2);
    // l1->next = new ListNode(4);
    // l1->next->next = new ListNode(3);

    // ListNode *l2 = new ListNode(5);
    // l2->next = new ListNode(6);
    // l2->next->next = new ListNode(4);

    ListNode *p = new ListNode();
    p = addTwoNumbers(l1, l2);
    while (p != NULL)
    {
        cout << p->val << " ";
        if(p->next== NULL && carry ==1)
        {
            p->next = new ListNode(1); 
            carry =0;           
        }
        p = p->next;
    }
    return 0;
}