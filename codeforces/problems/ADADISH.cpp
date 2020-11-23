#include <iostream>
#include <algorithm>
using namespace std;

void solve(int arr[], int n)
{
    int b1 = 0, b2 = 0;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (b1 < b2)
        {
            b1 += arr[i];
        }
        else
        {
            b2 += arr[i];
        }
        ans = max(b1, b2);
    }
    cout<<ans;
}
int main()
{
    int t, n;
    cin >> t;
    while (t-- > 0)
    {
        cin>>n;
        int arr[4];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        solve(arr, n);
    }
    return 0;
}