#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;
int sum(vector<int> &arr)
{
    int s = 0;
    for (int i = 0; i < arr.size(); i++)
        s += arr[i];
    return s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        bool win = true;
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<int> b(m);
        int sum_a = 0, sum_b = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum_a += a[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
            sum_b += b[i];
        }
        int cnt = 0;
        if (sum_a > sum_b)
        {
            cout << 0 << " ";
            continue;
        }
        while (sum_a <= sum_b)
        {
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            if (a[0] < b[m - 1])
            {
                // cout << a[0] << " " << b[m - 1];
                sum_a -= a[0];
                sum_a += b[m - 1];
                sum_b -= b[m - 1];
                sum_b += a[0];
                int temp = b[m - 1];
                b[m - 1] = a[0];
                a[0] = temp;

                cnt++;
            }
            else
            {
                win = false;
                break;
            }
        }
        if (!win)
            cout << -1 << " ";
        else
            cout << cnt << " ";
    }
    return 0;
}