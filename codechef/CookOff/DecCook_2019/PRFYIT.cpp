#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;

int cnt = 0;
void solve(string str, int i)
{
    cout << str << "\n";
    if (str.size() == 1 || i == str.size() - 1)
    {
        return;
    }
    if (str[i] == '1' && str[i - 1] == '0' && str[i + 1] == '0')
    {
        // 1010 , 0101

        string str_1 = str.substr(0, i);
        string str_2 = str.substr(i + 1);
        str = str_1 + str_2;
        // cout << str_1 << str_2 << "\n";
        cnt++;
        solve(str, i);
    }
    else if (str[i] == '0' && str[i + 1] == '1' && str[i - 1] == '1')
    {
        string str_1 = str.substr(0, i);
        string str_2 = str.substr(i + 1);
        str = str_1 + str_2;
        // cout << str << "\n";
        cnt++;
        solve(str, i);
    }
    else
    {
        solve(str, i + 1);
    }
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        cnt = 0;
        string str;
        cin >> str;
        solve(str, 1);
        cout << cnt << "\n";
    }

    return 0;
}