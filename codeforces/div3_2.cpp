#include <bits/stdc++.h>
#include <math.h>

using namespace std;
void solve()
{
    int n;
    cin >> n;
    stack<int> s;
    int total = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            s.push(x);
            total += sum;
            sum = 0;
        }
        else
        {
            if (!s.empty())
                sum++;
        }
    }
    cout << total << "\n";
}

int main()
{
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}
