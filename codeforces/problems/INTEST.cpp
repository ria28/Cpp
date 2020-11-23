#include <iostream>
using namespace std;
int cnt = 0;
void solve(int no, int k)
{
    if (no % k == 0)
        cnt++;
}
int main()
{
    int t, k, nos;
    cin >> t >> k;
    while (t-- > 0)
    {
        cin >> nos;
        solve(nos, k);
    }
    cout << cnt;
    return 0;
}