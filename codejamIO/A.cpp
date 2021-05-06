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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int T = 1; T <= t; T++)
    {
        cout << "Case #" << T << ": ";
        int n;
        cin >> n;
        vi arr(n, 0);
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (map.find(arr[i]) != map.end())
                map[arr[i]]++;
            else
                map[arr[i]] = 1;
        }
        // for (auto i : map)
        //     cout << i.first << " " << i.second << "\n";

        sort(arr.begin(), arr.end());
        int food = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (i != 0 && arr[i] == arr[i - 1])
                continue;
            food++;
            int curr = 1;
            curr = food * map[arr[i]];
            // cout << arr[i] << " " << food << " ";
            ans += curr;
            map.erase(arr[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}