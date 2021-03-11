#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <climits>
#include <math.h>
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
    while (t--)
    {
        ll n, k;
        cin >> n >> k;

        vector<ll> arr(n);
        ll max_ = INT32_MIN;
        ll mex = n;
        set<int> set;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            set.insert(arr[i]);
            max_ = max(max_, arr[i]);
        }

        if (k == 0)
        {
            cout << n << "\n";
            continue;
        }

        sort(arr.begin(), arr.end());
        for (ll i = 0; i <= max_; i++)
        {
            if (set.find(i) == set.end())
            {
                mex = i;
                break;
            }
        }

        // cout<<mex<<" ";

        if (mex < max_)
        {
            ll a = ceil((mex + max_) / 2.0);
            set.insert(a);
            cout << set.size() << "\n";
        }
        else
        {
            cout << set.size() + k << "\n";
        }
    }
    return 0;
}