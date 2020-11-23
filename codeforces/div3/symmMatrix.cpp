#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
int main()
{
    int t;
    ios::sync_with_stdio(false);
    cin >> t;
    int m, n;
    while (t-- > 0)
    {
        cin >> n >> m;
        int a1[n], a2[n], a3[n], a4[n];
        bool flag =0;
        for (int i = 0; i < n; i++)
        {
            cin >>a1[i]>>a2[i]>>a3[i]>>a4[i];
            if(a2[i]==a3[i])
            {
                flag =1;
            }
        }
        if(flag ==0 || m & 1)
        cout<<"NO\n";
        else
        {
            cout<<"YES\n";
        }
        
    }
    return 0;
}