#include <iostream>
#include <string>
#include <unordered_set>
#include <set>
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
    int n;
    cin >> n;
    vi arr(n);
    int sum = 0;
    unordered_map<int, set<int>> map;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        map[arr[i] % 3].insert(arr[i]);
        sum += arr[i];
    }

    sort(arr.begin(), arr.end(), greater<int>());
    if (arr[n - 1] != 0)
    {
        cout << -1;
    }
    else if (sum == 0)
    {
        cout << 0;
    }
    else
    {
        if (sum % 3 == 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (i == 0 && arr[i] == 0)
                {
                    cout << 0;
                    break;
                }
                cout << arr[i];
            }
        }
        else
        {
            int rem = sum % 3;
            int ele;
            int cnt = 0;
            if (map.find(rem) != map.end())
            {
                ele = *map[rem].begin();
            }
            else
            {
                if (rem == 1)
                {
                    cnt == 2;
                    ele = *map[2].begin();
                }
                else // 2
                {
                    cnt = 1;
                    ele = *map[1].begin();
                } 
            }

            for (int i = 0; i < n; i++)
            {
                if (arr[i] == ele && cnt >= 0)
                {
                    cnt--;
                    continue;
                }
                if (i == 0 && arr[i] == 0)
                {
                    cout << 0;
                    break;
                }
                cout << arr[i];
            }
        }
    }
    return 0;
}