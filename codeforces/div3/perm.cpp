#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        // int arr[n];
        if (n % 2 == 0)
        {
            for (int i = n; i > 0; i--)
                cout << i << " ";
        }
        else
        {
            int mid = (n+1)/2;
            for (int i = n; i > 1; i--)
            {
                if(i!=mid)
                cout << i << " ";
                else
                {
                    cout<<1<<" ";
                }
                               
            }
            cout<<mid<<" ";

            // for (int i = n / 2; i > 0; i--)
            // {
            //     cout << i << " ";
            // }
            // for (int i = n; i > n / 2; i--)
            // {
            //     cout << i << " ";
            // }
        }
        cout << "\n";
    }
    return 0;
}