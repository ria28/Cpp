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

bool checkCows(ll mid, ll c, vector<ll> &arr)
{
    ll cowsPlaced = 1, lastPlaced = arr[0];
    for (ll i = 1; i < arr.size(); i++)
    {
        if (arr[i] - lastPlaced >= mid)
        {
            cowsPlaced++;
            lastPlaced = arr[i];
            if (cowsPlaced == c)
            {
                return true;
            }
        }
    }
    return false;
}

void binarySearch(ll n, ll c)
{
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    ll left = arr[0];
    ll right = arr[n - 1];
    ll ans = -1;
    while (left <= right)
    {
        ll mid = left + (right-left) / 2;
        if (checkCows(mid, c, arr))
        {
            // cout<<mid<<" ";
            if (mid > ans)
                ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid-1;
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, c;
        cin >> n >> c;
        binarySearch(n, c);
    }
    return 0;
}