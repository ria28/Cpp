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
    while (t--)
    {
        string str;
        cin >> str;
        int n = str.size();
        char A = 'a', B = 'a', C = 'a';
        string ans = "";
        int ope = 0, clo = 0;
        unordered_map<char, int> map;
        if (str[0] == str[n - 1])
            cout << "NO\n";
        else
        {
            for (int i = 0; i < n; i++)
            {
                map[str[i]]++;
            }

            bool flg = false;
            for (auto i : map)
            {
                cls
                
                if ((i.first == str[0] || i.first == str[n - 1]) && i.second == n / 2)
                {
                    // cout << i.first << " " << i.second << "\n";
                    flg = true;
                    break;
                    // cout << "NO\n";
                }
                
            }

            if (flg == true)
            {
                cout << "YES\n";
            }
            else
                cout << "NO\n";
        }
    }

    return 0;
}