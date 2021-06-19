#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int pal(ll n)
{
    ll reversedN = 0, remainder, m;
    m = n;
    while (n > 0)
    {
        remainder = n % 10;
        reversedN = reversedN * 10 + remainder;
        n /= 10;
    }
    if (reversedN == m)
        return 1;
    return 0;
}

int solve(int n)
{
    string s = "";
    string copy;
    while (n > 0)
    {
        if (n & 1 == 1)
            s += "1";
        else
            s += "0";
        n >>= 1;
    }
    copy = s;
    reverse(s.begin(), s.end());
    if (s == copy)
        return 1;
    else
        return 0;
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, t;
    cin >> t;
    int arr[1000001] = {0};
    arr[1] = 1;
    for (int i = 2; i <= 1000000; i++)
    {
        if (pal(i) == 1 && solve(i) == 1)
            arr[i] = arr[i - 1] + 1;
        else
            arr[i] = arr[i - 1];
    }
    while (t--)
    {
        int n;
        cin >> n;
        cout << arr[n] << "\n";
    }
}