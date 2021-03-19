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

vector<bool> camelMatch(vector<string> &q, string p)
{
    int n = q.size();
    vector<bool> ans(n, false);

    for (int i = 0; i < n; i++)
    {
        string str = q[i];
        int k = 0; // pattern
        // cout<<str<<" ";
        for (int j = 0; j < str.size();)
        {
            // cout << k << " ";
            if (k < p.size() && str[j] == p[k])
            {
                // cout << str[j] << " ";
                j++;
                k++;
            }
            else if (str[j] >= 'A' && str[j] <= 'Z')
            {
                ans[i] = false;
                break;
            }
            else
                j++;

            if (k >= p.size())
            {
                ans[i] = true;
            }
        }
    }
    for (bool v : ans)
        cout << v << " ";
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> str = {"IXfGawluvnCa"};
    string p = "IXfGawlCa";
    camelMatch(str, p);
    return 0;
}