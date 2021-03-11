#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <math.h>
#define ll long long
using namespace std;
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)
#define vi vector<int>
#define vii vector<vector<int>>
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, k;
//         cin >> n >> k;
//         string str;
//         cin >> str;

//         if (k == 0)
//         {
//             cout << "YES\n";
//         }
//         else if(n<=k)
//         {
//             cout<<"NO\n";
//         }
//         else
//         {
//             bool flag = true;
//             for (int i = 0; i < n; i++)
//             {
//                 if ( i != n-i-1 && str[i] != str[n - i - 1])
//                 {
//                     flag = false;
//                     break;
//                 }
//             }

//             if (flag)
//             {
//                 if (k + 1 <= ceil(n / 2.0))
//                     cout << "YES\n";
//                 else
//                     cout << "NO\n";
//             }
//             else
//                 cout << "NO\n";
//         }
//     }

//     return 0;
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string str;
        cin >> str;

        /* 
            (a1 a2 a3  ...ak) ak+1 (ak  ak-1 ak-2)
        */

        if (2 * k + 1 > n)
            cout << "NO\n";
        else
        {
            bool flg = true;
            for (int i = 0; i < k; i++)
            {
                if (str[i] != str[n - i - 1])
                {
                    flg = false;
                    break;
                }
            }

            if (flg)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}