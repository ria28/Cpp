#include <iostream>
#include <cmath>
#include <set>
#define ll long long
using namespace std;

int main()
{
    ll n;
    cin >> n;
    int arr[n];
    set<ll> set;
    set.insert(0);
    ll sum =0,cnt=0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        // cout<<sum;
        if(set.count(sum))
        {
            
            cnt++;
            set.clear();
            set.insert(0);
            set.insert(arr[i]);
            sum = arr[i];            
        }
        else
        {
            set.insert(sum);
        }
    }
    cout<<cnt;

    return 0;
}