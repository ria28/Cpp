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
        ll a, b;
        cin >> a >> b;
        ll e1 = a / 2;
        ll o1 = a - e1;
        ll e2 = b / 2;
        ll o2 = b - e2;
        cout << e1 * e2 + o1 * o2 << "\n";
    }

    return 0;
}