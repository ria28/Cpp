#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)

bool isThere(int l, int r, vector<int> &arr, bool check,int ind)
{
    for (int i = ind + 1; i <= arr.size() - 1; i++)
    {
        if (check == false && arr[i] < arr[ind] )
        {
            if (arr[ind] - arr[i] >= l && arr[ind] - arr[i] <= r)
                return true;
        }
        else if (check == true && arr[i] > arr[ind])
        {
            if (arr[i] - arr[ind] >= l && arr[i] - arr[ind] <= r)
                return true;
        }
    }
    return false;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        bool flag = false;
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> v(n + 1);
        vector<int> pre(n + 1);
        int x = 0;
        for (ll i = 1; i <= n; i++)
        {
            cin >> v[i];
            x += v[i];
            pre[i] = x;
        }

        for (ll i = 1; i <= n; i++)
        {
            if (pre[i] >= l && pre[i] <= r)
            {
                cout << 0 << " \n";
                flag = true;
                break;
            }
        }
        if (flag)
            continue;
        for (ll i = 1; i <= n; i++)
        {
            if (v[i] >= l && v[i] <= r)
            {
                cout << 1 << "\n";
                flag = true;
                break;
            }
        }
        if (flag)
            continue;

        for (ll i = 2; i <= n; i++)
        {
            if (pre[i] < l)
            {
                if (isThere(l - pre[i], r - pre[i], v, true, i))
                {
                    cout << 1 << "\n";
                    flag = true;
                    break;
                }
            }
            else
            {
                if (isThere(pre[i] - r, pre[i] - l, v, false, i))
                {
                    cout << -1 << "\n";
                    flag = true;
                    break;
                }
            }
        }
        if (flag)
            continue;
        if (pre[n - 1] < l)
            cout << 2 << "\n";
        else
            cout << -1 << "\n";
    }
    return 0;
}