#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include<chrono>
#define ll long long
#define vi vector<ll>
using namespace std;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    ll t, n, q;
    cin >> t >> n >> q;
    while (t-- != 0)
    {
        vi res;
        int i = 4;
        ll size = 3;
        ll median;

        cout << "1 2 3\n"<<flush;
        cin >> median;
        if (median == 1)
        {
            res.push_back(2);
            res.push_back(1);
            res.push_back(3);
        }
        else if (median == 2)
        {
            res.push_back(1);
            res.push_back(2);
            res.push_back(3);
        }
        else // p==3
        {
            res.push_back(1);
            res.push_back(3);
            res.push_back(2);
        }
        while (i <= n)
        {
            ll lo = 0;
            ll hi = size - 1;
            while (lo < hi)
            {
                ll mid = lo + ((hi - lo) / 2);
                cout << res[mid] << " " << res[mid + 1] << " " << i << "\n"<<flush;
                cin >> median;
                if (median == res[mid])
                {
                    hi = mid;
                }
                else if (median == res[mid + 1])
                {
                    lo = mid + 1;
                }
                else
                {
                    res.insert(res.begin() + mid + 1, i);
                    size++;
                    break;
                }
            }
            if (size != i)
            {
                if (lo != 0)
                    res.push_back(i);
                else
                    res.insert(res.begin(), i);
                size++;
            }

            i++;
        }
        for (auto i : res)
            cout << i << " "<<flush;

        cout << "\n"<<flush;
        cin >> median;
        if (median == -1)
            break;
        else
            continue;
    }
}