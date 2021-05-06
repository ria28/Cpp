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

int find(int j, vi &arr)
{
    int mi = INT_MAX;
    int idx =0;
    for (int i = j; i < arr.size(); i++)
    {
        if(mi>arr[i])
        {
            mi = arr[i];
            idx =i;
        }
    }
    return idx;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    int T = 1;
    while (T <= t)
    {
        int n;
        cin >> n;
        vi arr(n + 1, 0);
        int cost = 0;
        for (int i = 1; i < arr.size(); i++)
            cin >> arr[i];

        for (int i = 1; i < arr.size()-1; i++)
        {
            int j = find(i, arr);
            cost += j-i + 1;
            // cout<<i<<j<<"\n";
            reverse(arr.begin() + i, arr.begin() + j+1);
            // for (int i : arr)
            //     cout << i << " ";
            // cout<<"\n";

            // cout<<cost<<"\n";
        }
        // cout << "\n";
        cout << "Case #" << T << ": " << cost << "\n";
        T++;
    }

    return 0;
}