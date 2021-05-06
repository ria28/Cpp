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


// https://leetcode.com/problems/split-linked-list-in-parts/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<ListNode *> splitListToParts(ListNode *root, int k)
{

    ListNode *temp = root;
    ListNode *curr = root;
    int size = 0;
    while (temp != NULL)
    {
        size++;
        temp = temp->next;
    }

    int width = size / k;
    int rem = size % k;

    vector<ListNode *> ans(k);
    if (root == NULL || k == 0)
    {
        while (root != NULL)
        {
            ans.push_back(root);
            root = root->next;
        }
        return ans;
    }

    ListNode *prev = NULL;

    for (int i = 0; i < k && curr != NULL; i++, rem--)
    {
        ans[i] = curr;
        for (int j = 0; j < width + (rem > 0 ? 1 : 0); j++)
        {
            prev = curr;
            curr = curr->next;
        }
        // if(prev!=NULL)
        prev->next = NULL;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}