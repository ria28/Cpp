#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)
using namespace std;
#define ll long long 
const int mod = 1e9 + 7;
#define v vector<int>
// #define code_fast                     \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(0);                       \
//     cout.tie(0);
//author shubham rai
int main()
{
    //    code_fast
       cout<<"hello";
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        int n, query, m;
        cin >> n >> query >> m;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int ans[m + 1] = {};
        int beararr[1000001] = {};

        map<pair<int, int>, int> maptostorecount;
        while (query--)
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            if (arr[l] > m)
            {
                continue;
            }
            else if (arr[l] <= m && arr[r] > m)
            {
                beararr[arr[l]]++;
                beararr[m + 1]--;
            }
            else if (arr[r] <= m)
            {
                beararr[arr[l]]++;
                beararr[m + 1]--;
                maptostorecount[{arr[l], arr[r]}]++;
            }
        }
        for (auto x : maptostorecount)
        {
            int kindex = x.first.first;
            int p = x.first.second;
            int l = x.second;
            beararr[p + kindex] -= l;
            beararr[p + 2 * kindex] += l;
            int c = p + 2 * kindex;
            while (c + p <= m)
            {
                c += p;
                beararr[c] -= l;
                beararr[c + kindex] += l;
                c += kindex;
            }
        }
        for (int i = 1; i <= m; i++)
        {
            beararr[i] += beararr[i - 1];
        }
        int maxval = 0;
        for (int i = 0; i <= m; i++)
        {
            maxval = max(maxval, beararr[i]);
        }
        cout << maxval << "\n";
    }
    return 0;
}