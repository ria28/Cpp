#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin>>n;
        int  root_n = sqrt(n);
        if(root_n*root_n >= n)
        {
            cout<<(2*root_n -2)<<"\n";
        }
        else if((root_n+1)*(root_n)>=n)
            cout<<(2*root_n -1)<<"\n";
        else
        {
            cout<<(2*root_n)<<"\n";
        }
        
    }
    return 0;
}