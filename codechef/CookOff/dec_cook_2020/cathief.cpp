#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;

// void solve(ll x, ll y, ll k,ll n)
// {
//     for(int i =1; i<=k;i++)
//     {
//         if(x+i<)
//     }

//     if(x==y)
//     {
//         cout<<"Yes\n";
//         return;
//     }
//     if(abs(x-y)==1)
//     {
//         cout<<"NO\n";
//     }

// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll x, y, k, n;
        cin >> x >> y >> k >> n;
        // solve(x,y,k,n);
        // bool y = false;
        // while (abs(x - y) == 1 || x == y)
        // {
        //     if (y > x)
        //     {
        //         for (int i = 1; i <= k; i++)
        //         {
        //             for (int j = 1; j <= k; j++)
        //             {
        //                 while (y <= n)
        //                     y += j;
        //             }
        //             if(j==n)
        //             {
        //                 for(int l =0;)
        //             }
        //             if (x + i <= n)
        //             {
        //                 x += i;
        //                 if(x==y)
        //                 {
        //                     cout<<"Yes\n";
        //                     break;
        //                 }
        //             }
        //         }
        //     }
        // }

        if (abs(x - y) == 1)
        {
            cout << "No\n";
            continue;
        }
        else if (abs(x - y) % (2 * k) == 0)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}