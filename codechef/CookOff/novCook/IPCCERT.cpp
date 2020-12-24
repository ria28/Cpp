#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> arr(n, vector<ll>(k + 1));
    int cnt = 0;
    for (ll i = 0; i < n; i++)
    {
        ll sum = 0;
        bool lec = false, ques = false;
        for (ll j = 0; j <= k; j++)
        {
            cin >> arr[i][j];
            if (j < k)
            {
                sum += arr[i][j];
            }
        }
        // cout << sum << " " << arr[i][k] << "\n";
        if (sum >= m)
            lec = true;

        if (arr[i][k] <= 10)
            ques = true;
        if (ques && lec)
            cnt++;
    }
    cout << cnt << "\n";

    return 0;
}