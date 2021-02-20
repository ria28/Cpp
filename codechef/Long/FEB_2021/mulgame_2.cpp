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
typedef long long ll;
const int mod = 1e9 + 7;
#define v vector<int>
#define code_fast
//author shubham rai
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, q, m;
        cin >> n >> q >> m;
        int arr[n];
        int ans[m + 1] = {};
        int arr_2[1000001] = {};
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        unordered_map<pair<int, int>, int> map;
        while (q--)
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
                arr_2[arr[l]]++, arr_2[m + 1]--;
            }
            else if (arr[r] <= m)
            {
                arr_2[arr[l]]++, arr_2[m + 1]--;
                map[{arr[l], arr[r]}]++;
            }
        }
        for (auto x : map)
        {
            int kindex = x.first.first;
            int p = x.first.second;
            int l = x.second;
            arr_2[p + kindex] -= l;
            arr_2[p + 2 * kindex] += l;
            int c = p + 2 * kindex;
            while (c + p <= m)
            {
                c += p;
                arr_2[c] -= l;
                arr_2[c + kindex] += l;
                c += kindex;
            }
        }
        for (int i = 1; i <= m; i++)
        {
            arr_2[i] += arr_2[i - 1];
        }
        int maxval = 0;
        for (int i = 0; i <= m; i++)
        {
            maxval = max(maxval, arr_2[i]);
        }
        cout << maxval << "\n";
    }
    return 0;
}