#include <iostream>
#include <unordered_map>
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
        int cnt =0;
        int f=0;
        int arr[n];
        for(int i =0; i<n;i++)
        {
            cin>>arr[i];
            // sum += arr[i];            
        }
        f = arr[0];
        arr[0]=0;

        int i =1;
        while(f!=0)
        {
            f--;
            f+=arr[i];
            arr[i]=0;
            cnt++;
            // cout<<cnt<<" ";
            i = (i+1)%n;
        }

        cout<<cnt<<"\n";
    }
}
