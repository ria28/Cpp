#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

void solve(int arr[], int n)
{
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (abs(arr[i] - arr[i + 1]) <= 1)
        {
            cnt++;
        }
    }
    if (cnt == n - 1)
    {
        cout << "YES\n";
    }
    else
        cout << "NO\n";
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        if (n == 1)
        {
            cout << "YES\n";
            continue;
        }
        sort(arr, arr + n);
        solve(arr, n);
    }
    return 0;
}
