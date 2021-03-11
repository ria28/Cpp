#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <climits>
#define ll long long
using namespace std;
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)
#define vi vector<int>
#define vii vector<vector<int>>
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int a, b;
    if(n==1 && m==1)
    {
        cout<<2;
    }
    // a2 +b
    else if (n > m)
    {
        int sq = sqrt(n);
        a = sq;
        b = n - (pow(sq, 2));
        if (pow(b, 2) + a == m)
        {
            // cout << a << " " << b;
            cout << 1;
        }
        else
        {
            cout << 0;
        }
    }
    else 
    {
        int sq = sqrt(m);
        b = sq;
        a = m - (pow(sq, 2));
        if (pow(a, 2) + b == n)
        {
            // cout << a << " " << b;
            cout << 1;
        }
        else
        {
            cout << 0;
        }
    }
    // else
    // {
    //     int x = sqrt(n);
    //     // cout<<pow(x,2)<<" ";
    //     if (pow(x, 2) == n)
    //         cout << 2;
    //     else
    //     {
    //         cout << 0;
    //     }
    // }
    return 0;
}