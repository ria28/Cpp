#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <bitset>
using namespace std;

bool reverse_(string str, unordered_set<string> set)
{
    int s = 0, i = 0, cnt = 0;
    while (s < str.size() && i < str.size())
    {
        if (str[i] == '1')
            cnt++;
        if (cnt % 2 == 0 && cnt != 0)
        {
            reverse(str.begin() + s, str.begin() + i + 1);
            // cout << str << "  ";
            if (set.find(str) != set.end())
                return false;
            int store = i;
            while (str[i + 1] == '0')
            {
                i++;
                // cout<<i<<" ";
            }
            if (store != i)
            {
                // cout << s << " " << i << " ";
                reverse(str.begin() + s, str.begin() + i + 1);
                if (set.find(str) != set.end())
                    return false;
                // cout << str << "  ";
            }
            s++;
            cnt = 0;
            i = s;
        }
        else
        {
            i++;
        }
    }
    // reverse(str.begin(), str.end());
    return true;
}

bool odd_1(string str)
{
    int cnt = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '1')
            cnt++;
    }
    if (cnt & 1)
        return true;
    else
        return false;
}

int main()
{
    int t;
    cin >> t;
    // reverse_("01110");
    // reverse_("1110");
    while (t--)
    {
        string str;
        cin >> str;
        int n = str.size();
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            int cnt = 0;
            unordered_set<string> set;
            for (int j = 0; j + i <= n; j++)
            {
                string sub = str.substr(j, i);
                cout << sub << " ";
                if (j == 0)
                {
                    set.insert(sub);
                    cnt++;
                }
                else
                {
                    if (set.find(sub) == set.end())
                    {
                        // if (i == 3)
                        //     cout << sub << " ";
                        // if (!odd_1(sub))
                        // {
                        // if (i == 3)
                        //     cout << sub << " ";

                        bool rev = reverse_(sub, set);
                        if (rev)
                        {
                            set.insert(sub);
                            cnt++;
                        }
                        // }
                        // else
                        // {
                        //     set.insert(sub);
                        //     cnt++;
                        // }
                    }
                }
            }
            cout << " \n"
                 << cnt << "\n";
            sum += cnt;
            unordered_set<string>::iterator itr;
            // for (itr = set.begin(); itr != set.end(); itr++)
            //     cout << "( " << *itr << ") ";
        }
        cout << sum << "\n";
    }
    return 0;
}