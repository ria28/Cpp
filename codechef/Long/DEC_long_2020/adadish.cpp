#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t ;
    cin>>t;
    while(t--)
    {
        int n ;
        cin>>n;
        int arr[n];
        int b1=0 , b2 =0;
        for(int i =0; i<n; i++)
            cin>>arr[i];
        sort(arr, arr+n,greater<int>());
        for(int i =0; i<n; i++)
        {
            if(b1<b2)
            {
                b1+= arr[i];
            }
            else
            {
                b2+=arr[i];
            }
            
        }
        int ans = max(b1,b2);
        cout<<ans<<"\n";
    }
    return 0;
}