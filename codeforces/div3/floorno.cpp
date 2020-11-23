#include <iostream>
#include<cmath>
# define ll long long
using namespace std;
void solve(float n, float x)
{
    // (res -1)x +2 = n
    if (n == 1 || n == 2)
    {
        cout << 1 << "\n";
    }
    else
    {
        float res = ceil((n - 2) / x)  + 1;
        cout<<res<<"\n";
    }
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        ll n, x;
        cin >> n >> x;
        solve(n, x);
    }
    return 0;
}