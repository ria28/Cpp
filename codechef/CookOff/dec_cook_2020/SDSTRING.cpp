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
        string str;
        cin >> str;
        int cnt_1 = 0;
        int cnt_0 = 0;
        int cnt = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '1')
                cnt_1++;
            else
                cnt_0++;
        }
        if (str.size() % 2 != 0)
        {
            cout << -1 << "\n";
            continue;
        }
        if (cnt_1 == cnt_0)
        {
            cout << 0 << "\n";
            continue;
        }

        // while (cnt_1 != cnt_0)
        // {
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '0' && str[i + 1] == '1')
            {
                if (cnt_1 > cnt_0)
                {
                    cnt_0++;
                    cnt_1--;
                    cnt++;
                }
                else
                {
                    cnt_1++;
                    cnt_0--;
                    cnt++;
                }
                // i++;
            }
            if (cnt_0 == cnt_1)
            {
                cout << cnt << "\n";
                break;
            }
        }
        // }
    }
    return 0;
}