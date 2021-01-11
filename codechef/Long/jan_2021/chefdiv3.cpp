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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll n, k, d;
        cin >> n >> k >> d;
        vector<int> a(n);
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            s += a[i];
        }
        if (s < k)
        {
            cout << 0 << " ";
        }
        else
        {
            int days = s / k;
            // cout << days << " ";
            if (days > d)
            {
                cout << d << " ";
            }
            else
            {
                cout << days << " ";
            }
        }
    }

    return 0;
}