
//  PARTIALLY CORRECT   USE DP / GREEDY APPPROACH=-------------------------------


#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    int a[n], b[n];
    int tips = 0, andy = 0, bob = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[i])
        {
            if (andy < x)
            {
                andy++;
                tips += a[i];
            }
            else
            {
                tips += b[i];
                bob++;
            }
        }
        else
        {
            if (bob < y)
            {
                bob++;
                tips += b[i];
            }
            else
            {
                andy++;
                tips += a[i];
            }
        }
    }
    cout<<tips<<"\n";

    return 0;
}