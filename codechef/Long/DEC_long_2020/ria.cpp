#include <iostream>
#include <vector>
#include <math.h>
#define v vector
#define ll long long
using namespace std;

int main()
{
    ll t, n, x, a[100005], k = 30;
    cin >> t;
    while (t--)
    {
        cin >> n >> x;

        if (n > 2)
        {
            v<v<ll>> idx(k + 1);
            for (ll i = 0; i < n; i++)
            {
                cin >> a[i];
                if (i == n - 1)
                    continue;
                for (ll j = k; j >= 0; j--)
                    if (a[i] & (1LL << j))
                    {
                        idx[j].push_back(i);
                    }
            }
            v<ll> cnt(k + 1, 0);
            for (ll i = 0; i < n - 1; i++)
            {
                for (ll j = k; j >= 0; j--)
                {
                    ll mask = 1LL << j;
                    if ((a[i] & mask) == 0)
                        continue;
                    a[i] ^= mask;
                    ll d;
                    if (++cnt[j] < idx[j].size())
                    {
                        d = idx[j][cnt[j]++];
                    }
                    else
                        d = n - 1;
                    a[d] ^= mask;
                    if (--x == 0)
                        break;
                }
                if (x == 0)
                    break;
            }
        }
        else
        {
            for (int i = 0; i < 2; i++)
                cin >> a[i];

            if (a[0] != 0)
            {
                while (x-- > 0)
                {
                    ll p = int(log(a[0]) / log(2));
                    a[0] ^= (ll)pow(2, p);
                    a[1] ^= (ll)pow(2, p);
                    if (a[0] == 0)
                        break;
                }
                if (x > 0 && x % 2 != 0)
                {
                    a[0] = 1;
                    a[1] ^= 1;
                }
            }

            else
            {
                if (x % 2 != 0)
                {
                    a[0] = 1;
                    a[1] = a[1] ^ 1;
                }
            }
        }

        for (ll i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }
}