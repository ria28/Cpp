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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int T = 1; T <= t; T++)
    {
        cout << "Case #" << T << ": ";
        int n;
        cin >> n;
        vi arr(n);
        int len = 1;
        unordered_set<int> set;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            len += arr[i];
            set.insert(len - arr[i]);
        }
        string ans = "";
        ans += 'A';
        vector<char> res(len);
        vector<bool>vis(26,false);
        vis[0]=true;
        res[0] = 'A';
        for (int i = 1; i < len; i++)
        {
            if ((set.find(i) != set.end() && i % 2 != 0) || set.find(i) == set.end())
            {
                char a = res[i - 1];
                a++;
                res[i] = a;
            }
            else if (set.find(i) != set.end() && i % 2 == 0)
            {
                
            }
        }
    }
    return 0;
}