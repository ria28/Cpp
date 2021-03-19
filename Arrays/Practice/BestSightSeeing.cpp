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


// https://leetcode.com/problems/best-sightseeing-pair/
int maxScoreSightseeingPair(vector<int> &values)   
{
    int n = values.size();
    int max_arr = values[0] - 1;
    int o_max = 0;
    for (int i = 1; i < n; i++)
    {
        o_max = max(o_max, max_arr + values[i]);
        max_arr = max(max_arr, values[i]);
        max_arr--;
    }
    return o_max;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<maxScoreSightseeingPair({8,1,5,2,6});
    return 0;
}