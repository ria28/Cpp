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

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string str;
        cin>>str;
        // vector<int> arr(n);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == '1')
                cnt++;
        }
        int left = 120 - n;
        cnt += left;
        // cout<<cnt<<" ";
        float att = (float)(cnt / 120.0);
        // cout<<att<<" ";
        if (att >= 0.75)
            cout << "YES\n";
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}