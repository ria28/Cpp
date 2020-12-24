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
        ll n, d;
        cin >> n >> d;
        int arr[n];
        double vul = 0, n_vul = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] <= 9 || arr[i] >= 80)
                vul++;
        }
        n_vul = n - vul;
        int days = 0;
        double a= n_vul / d;
        double b = vul / d;
        // cout<<a<<" "<<b<<" ";
        days = ceil(n_vul / d) + ceil(vul / d);
        cout << days << "\n";
    }
    return 0;
}