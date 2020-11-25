#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-->0)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        int dif = INT32_MAX;
        if (n == 2)
        {
            int ele = arr[1] - arr[0];
            cout << ele << "\n";
            continue;
        }
        for (int i = n - 1; i > 0; i--)
        {
            int ele = arr[i] - arr[i - 1];
            dif = min(ele, dif);
        }
        cout << dif << "\n";
    }
    return 0;
}