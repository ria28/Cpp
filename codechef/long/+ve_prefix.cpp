#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        if (n & 1)
        {
            // cout << "hello";
            for (int i = 0; i < n; i++)
            {
                if ((i + 1) & 1)
                {
                    arr[i] = i + 1;
                }
                else
                {
                    // cout<<"hhhh";
                    arr[i] = -(i + 1);
                }
            }
            // for (int i = 0; i < n; i++)
            //     cout << arr[i] << " ";
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if ((i + 1) & 1)
                {
                    arr[i] = -(i + 1);
                }
                else
                {
                    arr[i] = (i + 1);
                }
            }
        }
        int sum = 0, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum > 0)
                cnt++;
        }

        if (cnt > k)
        {
            for (int i = n - 1; i >= 0; i -= 2)
            {
                if (cnt == k)
                    break;
                arr[i] = arr[i] < 0 ? (i + 1) : -(i + 1);
                cnt--;
            }
        }
        else if (cnt < k)
        {
            // cout << "again";
            for (int i = n - 1; i >= 0; i--)
            {
                if (cnt == k)
                    break;
                if (arr[i] < 0)
                {
                    // cout << "ggg";
                    arr[i] = -arr[i];
                    cnt++;
                }
            }
        }

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
    }

    return 0;
}