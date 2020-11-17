#include <bits/stdc++.h>
#include <math.h>

using namespace std;
void solve()
{
    int n;
    cin >> n;
    set<int> s;
    map<int, vector<int>> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
        a[x].push_back(i);
    }
    if ((int)s.size() == 1)
    {
        cout << "NO"
             << "\n";
        return;
    }
    cout << "YES"
         << "\n";
    vector<vector<int>> other;
    for (auto i : a)
        other.push_back(i.second);
    for (int i = 1; i < (int)other.size(); i++)
    {
        for (auto j : other[i])
            cout << other[0][0] + 1 << " " << j + 1 << "\n";
    }
    for (int i = 1; i < (int)other[0].size(); i++)
        cout << other[0][i] + 1 << " " << other[1][0] + 1 << "\n";
    return;
}
int main()
{
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        //    cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}