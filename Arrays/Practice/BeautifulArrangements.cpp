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
int cnt = 0;

// BEAUTIFUL ARRANGEMENT I
// https://leetcode.com/problems/beautiful-arrangement-ii/submissions/
vector<int> constructArray(int n, int k)
{
    vi out;
    if (k == 1)
    {
        for (int i = 1; i <= n; i++)
            out.push_back(i);
    }
    else
    {
        int i = 1, j = k + 1; //*************imp  (5,2)
        while (i <= j)
        {
            out.push_back(i);
            if (i != j)
                out.push_back(j);
            i++;
            j--;
        }
        for (int i = k + 2; i <= n; i++)
        {
            out.push_back(i);
        }
    }
    return out;
}

// BEAUTIFUL ARRANGEMENT II
void helper(int n, int idx, vector<bool> &vis)
{
    if (idx > n)
    {
        cnt++;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (((i % idx == 0) || (idx % i == 0)) && !vis[i])
        {
            vis[i] = true;
            helper(n, idx + 1, vis);
            vis[i] = false;
        }
    }
}

int countArrangement(int n)
{
    vector<bool> vis(n + 1, false);
    helper(n, 1, vis);
    cout << cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // countArrangement(6);
    string a = "011";
    cout << (a[0] - '0');
    return 0;
}