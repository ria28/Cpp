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
#define vi vector<string>
#define vii vector<vector<int>>
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // return 0;

    int t;
    cin >> t;
    int T = 1;
    while (T <= t)
    {
        string str;
        cin >> str;
        vi ans;
        int open = 0;
        for (int i = 0; i < str.size(); i++)
        {
            while (open < str[i] - '0')
            {
                ans.push_back("(");
                open++;
            }
            while (open > str[i] - '0')
            {
                ans.push_back(")");
                open--;
            }
            string a = "";
            a += str[i];
            ans.push_back(a);
        }

        while(open)
        {
            ans.push_back(")");
            open--;
        }

        cout << "Case #" << T << ": ";
        for (string i : ans)
            cout << i;
        cout << "\n";
        T++;
    }
    return 0;
}