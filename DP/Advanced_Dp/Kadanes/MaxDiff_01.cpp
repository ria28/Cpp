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

void kadanes(vi &arr, int n)
{
    int c_sum = arr[0] == 0 ? 0 : -1, o_sum = arr[0] == 0 ? 0 : -1;
    for (int i = 0; i < n; i++)
    {
        int val = 0;
        if (arr[i] == 0)
            val += 1;
        else
            val += -1;

        if (c_sum >= 0)
            c_sum += val;
        else
            c_sum = val;
        if (c_sum > o_sum)
        {
            o_sum = c_sum;
        }
    }

    cout << o_sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // vi arr = {1, 1, 1, 1};
    vi arr = { 1,1,0,0,0,0,1,0,0,0,1};
    kadanes(arr, arr.size());
    return 0;
}