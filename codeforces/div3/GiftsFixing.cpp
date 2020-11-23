#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

void solve(vector<ll> a, vector<ll> b, int n)
{
    int mna = *min_element(a.begin(), a.end());
    int mnb = *min_element(b.begin(), b.end());
    long long ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans += max(a[i] - mna, b[i] - mnb);
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        vector<ll> a;
        vector<ll> b;
        for (int i = 0; i < n; i++)
        {
            ll ele;
            cin >> ele;
            a.push_back(ele);
        }
        for (int i = 0; i < n; i++)
        {
            ll ele;
            cin >> ele;
            b.push_back(ele);
        }
        solve(a, b, n);
    }

    return 0;
}