#include <iostream>
#include <math.h>
#include <string>
#define ll long long

using namespace std;
int main()
{
    int t;
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
        bool op = true;
        if (n > 2)
        {
            for (int k = 0; k < n - 1 && x-- > 0; k++)
            {
                if (arr[k] == 0)
                {
                    x++;
                    continue;
                }
                else
                {
                    op = false;
                    ll p = (ll)(log(arr[k]) / log(2));
                    arr[k] = arr[k] ^ (ll)pow(2, p);
                    bool jnf = true;
                    for (int j = k + 1; j < n - 1; j++)
                    {
                        int temp = arr[j] ^ (ll)pow(2, p);
                        if (temp < arr[j])
                        {
                            arr[j] = temp;
                            jnf = false;
                            break;
                        }
                    }
                    if (jnf)
                    {
                        arr[n - 1] ^= (ll)pow(2, p);
                    }
                }
                if (arr[k] != 0)
                    k--;
            } 

            if (op)
            {
                int b = x % 2;
                while (b-- > 0)
                {
                    int p = 0;
                    arr[n - 2] = arr[n - 2] ^ (ll)pow(2, p);
                    arr[n - 1] = arr[n - 1] ^ (ll)pow(2, p);
                }
            }
        }
        else
        { 
            if (arr[0] == 0)
            {
                if (x % 2 != 0)
                {
                    arr[0] = 1;
                    arr[1] = arr[1] ^ 1;
                }
            }
            else
            {
                while (x-- > 0)
                {
                    ll p = (ll)(log(arr[0]) / log(2));
                    arr[0] = arr[0] ^ (ll)pow(2, p);
                    arr[1] = arr[1] ^ (ll)pow(2, p);
                    if (arr[0] == 0)
                        break;
                }
                if (x > 0 && x % 2 != 0)
                {
                    arr[0] = 1;
                    arr[1] = arr[1] ^ 1;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
           cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
}