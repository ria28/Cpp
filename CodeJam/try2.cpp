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
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int T = 1;
    while (T <= t)
    {
        int n, cost;
        cin >> n >> cost;

        vector<int> res;
        for (int i = 1; i <= n; ++i)
            res.push_back(i);

        bool flag = false;
        do
        {
            ll arr[n];
            ll ans = 0;
            for (int i = 0; i < n; ++i)
                arr[i] = res[i];

            for (int i = 0; i < n - 1; ++i)
            {
                ll temp = arr[i];
                int idx = i;
                for (int j = i + 1; j < n; ++j) // minimum
                {
                    if (arr[j] < temp)
                    {
                        idx = j;
                        temp = arr[j];
                    }
                }
                if (idx == i)
                    ans++;
                else
                {
                    reverse(arr + i, arr + idx +1);
                    ans += (idx - i +1);  // j-i +1
                }
            }

            if (ans == cost)
            {
                flag = true;
                break;
            }
        } while (next_permutation(res.begin(), res.end()));

        cout << "Case #" << T << ": ";
        if (!flag)
            cout << "IMPOSSIBLE\n";
        else
        {
            for (auto i : res)
                cout << i << " ";
            cout << "\n";
        }
        T++;
    }
}