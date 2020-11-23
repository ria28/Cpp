#include <iostream>
using namespace std;
void solve(int n, int x)
{
    if(x ==0)
    {
        cout<<0<<" Null\n";
        return;
    }
    int e = 0, o = 0; // even odd
    int i = 1;
    while (i <= n)
    {
        if (i % 2 == 0)
            e++;
        else
            o++;

        i++;
    }
    int tot = ((e - 1) * (e)) + ((o - 1)*(o));
    if(tot < x)
    cout<<(x-tot)<<" Loss\n";
    else
    cout<<(tot-x)<<" Profit\n";
}

int main()
{
    int t, n, x;
    cin >> t;
    while (t-- > 0)
    {
        cin >> n >> x;
        solve(n, x);
    }
    return 0;
}