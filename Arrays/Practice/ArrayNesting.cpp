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

class Solution
{
public:
    int arrayNesting(vector<int> &nums)
    {
        int n = nums.size();
        int len = 0;
        int next_idx = 0;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++)
        {
            if (vis[i])
                continue;
            next_idx = i;
            int curr_len = 0;
            while (1)
            {
                if (vis[next_idx] == false)
                {
                    vis[next_idx] = true;
                    next_idx = nums[next_idx];
                    curr_len++;
                }
                else
                    break;
            }
            len = max(len, curr_len);
        }
        return len;
    }
};