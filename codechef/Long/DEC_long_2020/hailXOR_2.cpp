#include <iostream>
#include <math.h>
#define ll long long
using namespace std;

// n=8 x=422
//845 7785 2143 8452 1798 3573 5043 3188
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        ll arr[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int i = 0, j = 1;
        if (x & 1)
        {
            int cnt = 0;
            // cout << "hh";
            while (x--)
            {
                int i = 0, j = i++;
                while (j <= n)
                {
                    // if (cnt >= x)
                    //     break;

                    // while (arr[i] == 0)
                    // {
                    //     i++;
                    // }
                    // j = i + 1;
                    // while (arr[j] == 0)
                    // {
                    //     j++;
                    // }
                    // if (j >= n)
                    //     break;
                    ll val_and = arr[i] & arr[j];
                    ll p;
                    if (val_and == 0)
                    {
                        int val = arr[i]==0?arr[j]:arr[i];
                        p = floor(log(val) / log(2));
                    }
                    else
                    {
                        p = floor(log(val_and) / log(2));
                    }
                    // cout << p << "\n";
                    arr[i] = arr[i] ^ (ll)pow(2, p);
                    arr[j] = arr[j] ^ (ll)pow(2, p);
                    cnt++;
                    j++;
                    i++;
                    // cout << arr[i] << " " << arr[j] << "\n";
                }
            }
        }
        else
        {
            int count = 2;
            int cnt = 0;
            while (count--)
            {
                i = 0;
                j = 1;
                while (j <= n)
                {
                    if (cnt >= x)
                        break;
                    while (arr[i] == 0)
                    {
                        i++;
                    }
                    j = i + 1;

                    // while (arr[j] == 0)
                    // {
                    //     j++;
                    // }
                    if (j >= n)
                        break;
                    ll val_and = arr[i] & arr[j];
                    ll p;
                    if (val_and == 0)
                    {
                        p = floor(log(arr[i]) / log(2));
                    }
                    else
                    {
                        p = floor(log(val_and) / log(2));
                    }
                    // cout << p << "\n";
                    arr[i] = arr[i] ^ (ll)pow(2, p);
                    arr[j] = arr[j] ^ (ll)pow(2, p);
                    cnt++;
                    // cout << arr[i] << " " << arr[j] << "\n";
                    j++;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
