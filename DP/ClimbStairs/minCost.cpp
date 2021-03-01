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

// https://leetcode.com/problems/min-cost-climbing-stairs/

//  JUMPS : 1 or 2 
int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    vector<int> tab(n + 1);
    tab[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int sum = INT_MAX;
        for (int j = 2; j > 0; j--)
        {
            if (i + j > n)
                continue;
            sum = min(sum, tab[i + j]);
        }
        tab[i] = sum + cost[i];
    }
    return min(tab[0], tab[1]);
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    // Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
    // Output: 6
    // Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].

    return 0;
}

// 10 15 20
//o/p : 15
