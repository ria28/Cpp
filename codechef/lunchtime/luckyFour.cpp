#include <iostream>
#include <unordered_map>
#define ll long long
using namespace std;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        int cnt =0;
        while (n)
        {
            int rem = n %10;
            n =n/10;
            if(rem == 4)
                cnt++;
        }
        cout<<cnt<<"\n";
    }
}
