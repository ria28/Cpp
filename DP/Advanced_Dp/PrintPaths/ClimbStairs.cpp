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

class quad
{
public:
    int idx, size, jumps;
    string asf;
    quad(int i, int s, int j, string str)
    {
        this->idx = i;
        this->size = s;
        this->jumps = j;
        this->asf = str;
    }
};

void stairs_tab(ll n, vector<int> &jumps)
{
    vector<ll> dp(n, 0);
    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        ll sum = 0;
        for (int j = jumps[i]; j > 0; j--)
        {
            if (j + i == n)
                sum++;
            if (j + i < n)
            {
                sum += dp[j + i];
            }
        }
        dp[i] = sum;
    }
    cout << dp[0];


    // print path
    queue<quad>q;
    q.push({0,dp[0],jumps[0],to_string(0)});
    
    while(q.size()>0)
    {
        quad ele = q.front();
        q.pop();
        for(int i = ele.jumps ; i>0;i--)
        {
            
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    vector<int> jumps(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> jumps[i];
    }

    stairs_tab(n, jumps);
    return 0;
}

// 6
// 3 3 0 2 2 3
// 3