#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        unordered_map<int, int> map;
        bool equal = true;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (i > 0)
            {
                if (arr[i - 1] != arr[i])
                    equal = false;
            }
            if (map.find(arr[i]) == map.end())
            {
                map[arr[i]] = 1;
            }
            else
            {
                map[arr[i]]++;
            }
        }
        if (equal)
        {
            cout << 0 << "\n";
            continue;
        }
        int freq = 0;
        for (auto i : map)
        {
            if (i.second > 1 && i.second > freq)
            {
                freq = i.second;
            }
        }
        if (freq == 0)
        {
            cout << n-1<< "\n";
            continue;
        }
        int min_app = n - freq;
        cout << min_app << "\n";
    }

    return 0;
}