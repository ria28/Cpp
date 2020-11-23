#include <iostream>
using namespace std;

int solve(int arr[], int n, int k)
{
    int carry =0,days=0,i=0;
    for (i = 0; i < n; i++)
    {
        arr[i]+= carry;
        if(arr[i]<k)
            return i+1;
        // else if(arr[i] == k)
        //     return i+2;
        else
        {
            carry = arr[i]-k;
        } 
    }
    if(carry>=0)
    days = n+ (carry/k +1);
    return days;
    
    // return carry+2;
}

int main()
{
    int t, k,n;
    cin >> t;
    while (t-- > 0)
    {
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout<<solve(arr, n, k);
    }
    return 0;
}