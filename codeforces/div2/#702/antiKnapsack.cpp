#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include<math.h>
#define ll long long
using namespace std;
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)
#define vi vector<int>
#define vii vector<vector<int>>

// ANTI - KNAPSACK
// You are given two integers n and k. You are asked to choose maximum number of distinct integers from 1 to n so that there is no subset of chosen numbers with sum equal to k.

// this will include all the numbers grtr than k .... k+1 to n
//  also it'll include nos from ceil of k/2 till k-1 ...taking ceil because if k =7 ..k/2 = 3
// next of k/2 is  4 and 3 +4 will make 7 so take ceil

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int cei = ceil(k / 2.0);
        // cout<<"ceil"<<cei;
        cout << ((k - 1 - cei + 1) + (n - (k + 1) + 1)) << "\n";
        for (int i = k+1; i <= n; i++)
        {
            cout << i << " ";
        }
        for (int i = cei; i <= k - 1; i++)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}