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
        vector<int> v(n);
        int a = 0, b = 0;
        for (int &e : v)
        {
            cin >> e;
            if (e % 2 == 0)
            {
                a++;
            }
            else
            {
                b++;
            }
        }

        if((a&1 == 0 && b&1 !=0) || (a&1 != 0 && b&1 !=0) )
        bool flag =0;
        if (a % 2 != b % 2)
        {
            cout << "NO\n";
        }
        else
        {
            if (a % 2 == 0)
            {
                cout << "YES\n";
            }
            else
            {
                for (int i = 0; i < n && !flag; i++)
                {
                    for (int j = i + 1; j < n; j++)
                    {
                        if (v[i] % 2 != v[j] % 2 && abs(v[i] - v[j]) == 1)
                        {
                            cout << "YES\n";
                            flag = true;
                            break;
                        }
                    }
                    // if(flag)
                    // break;
                }
                cout << "NO\n";
            }
        }
    }
    return 0;
}