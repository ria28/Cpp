#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
#include <unordered_map>
#define ll long long
using namespace std;

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll min = INT64_MAX;
        ll min_ele = INT64_MAX;
        bool flag = false;
        ll n;
        cin >> n;
        unordered_map<ll, ll> mp;
        unordered_map<ll, ll> cnt;
        vector<ll> arr;
        for (int i = 0; i < n; i++)
        {
            ll ele;
            cin >> ele;
            arr.push_back(ele);
            mp[arr[i]]++;
            cnt[arr[i]] = i;
        }

        for (auto x : mp)
        {
            if (x.second == 1)
            {

                // cout << cnt[x.first] << "\n";

                // for (int i = 0; i < n; i++)
                // {
                //     if (arr[i] == x.first)
                //     {
                if (min_ele > x.first)
                {
                    min_ele = x.first;
                    min = cnt[x.first] + 1;
                }
                flag = true;
                //     }
                //     while(arr[i]==arr[i+1])
                //     {
                //         i++;
                //     }
                // }
            }
        }

        if (flag)
            cout << min << "\n";
        else
        {
            cout << -1 << "\n";
        }
    }

    return 0;
}