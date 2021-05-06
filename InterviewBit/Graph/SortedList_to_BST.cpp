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


//  * Definition for singly-linked list.
   struct ListNode {
       int val;
       ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

//   Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


TreeNode *bst(ListNode *head, ListNode *tail)
{
    if (head == tail)
        return NULL;
    // if(head == NULL) return NULL;
    ListNode *slow, *fast;
    slow = head;
    fast = head;
    while (fast->next != tail && fast->next->next != tail)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    TreeNode *node = new TreeNode(slow->val);
    node->left = bst(head, slow);
    node->right = bst(slow->next, tail);
    return node;
}

TreeNode *sortedListToBST(ListNode *head)
{
    if (head == NULL)
        return NULL;
    return bst(head, NULL);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}