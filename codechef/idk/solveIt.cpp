#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            int ele;
            cin >> ele;
            arr.push_back(ele);
        }

        sort(arr.begin(), arr.end());
        int ma = arr[n - 1] + k;
        int mi = arr[0] - k;
        cout << (ma - mi) << "\n";
    }
    return 0;
}