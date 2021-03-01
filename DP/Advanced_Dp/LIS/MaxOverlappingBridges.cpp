#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#define ll long long
using namespace std;
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)
#define vi vector<int>
#define vii vector<vector<int>>

class Bridge
{
public:
    int nb; // north bank
    int sb; // south bank
    Bridge()
    {
    }
    Bridge(int nb, int sb)
    {
        this->nb = nb;
        this->sb = sb;
    }
};

bool comp(Bridge a, Bridge b)
{
    if (a.nb != b.nb)
        return a.nb < b.nb;
    else
        return a.sb < b.sb;
}

void nonOverlapping(vector<Bridge> &arr)
{
    sort(arr.begin(), arr.end(), comp);
    // for (auto i : arr)
    //     cout << i.nb << " " << i.sb << "\n";
    vector<int> dp(arr.size(), 0);
    dp[0] = 1;
    int ma = INT_MIN;
    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[i].sb >= arr[j].sb)
            {
                dp[i] = max(dp[j], dp[i]);
            }
        }
        dp[i] += 1;
        ma = max(ma, dp[i]);
    }
    cout << ma << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<Bridge> arr(n);
    for (int i = 0; i < n; i++)
    {
        int nb, sb;
        cin >> nb >> sb;
        arr[i]=(Bridge(nb, sb));
    }

    nonOverlapping(arr);
    return 0;
}