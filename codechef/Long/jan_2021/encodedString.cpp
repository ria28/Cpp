#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#define ll long long
using namespace std;
int binary2decimal(string str)
{
    int i = 3;
    int ans = 0;
    for (int j = 0; j < str.size(); j++)
    {
        if (str[j] == '1')
        {
            int p = pow(2, i);
            ans += p;
        }
        i--;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        string str;
        cin >> n;
        cin >> str;

        unordered_map<int, char> map;
        string alpha = "abcdefghijklmnop";
        for (int i = 0; i < 16; i++)
        {
            map[i] = alpha[i];
        }

        string ans = "";
        for (int i = 0; i <= str.size() - 4;)
        {
            string sub = str.substr(i, 4);
            i += 4;
            // cout << sub << " ";
            ll c = binary2decimal(sub);
            // cout << c << " ";
            ans += map[c];
        }
        cout<<ans<<" ";
    }
    return 0;
}