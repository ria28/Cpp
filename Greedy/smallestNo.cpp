//https://www.geeksforgeeks.org/find-smallest-number-with-given-number-of-digits-and-digit-sum/
// smallest  no with given no of digits and sum of digits

#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)

void solve(int s, int d)
{
    if (d == 0) // digits = 0
        return;
    else if (s > 9 * d) // max digi we can fill is 9. so if by filing max at all places does not give the required sum ----> Not possible to form no.
        return;

    int arr[d];
    // we need to find min no so we start filling the digits in the number from right to left
    // For a no to be of 'd' digits the starting digit can not be zero.
    // we decrement our sum by 1 --> reserving atleast (min) "1" for our starting value--> if sum is left after processing then we'll add it later
    s -= 1;
    for (int i = d - 1; i > 0; i--)
    {
        if (s - 9 > 0)
        {
            arr[i] = 9;
            s -= 9;
        }
        else
        {
            arr[i] = s;
            s = 0;
        }
    }

    arr[0] = s + 1;
    for (int i : arr)
        cout << i;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int s , d ;  // s =9, d=2      s= 20,d=3
    cin>>s>>d;
    solve(s, d);
    return 0;
}