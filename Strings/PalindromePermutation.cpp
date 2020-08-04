#include <iostream>
#include <map>
#include <iterator>
using namespace std;

// https://www.codechef.com/submit/PERMPAL
int main(int args, char **argc)
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int l = s.length();

        multimap<char, int> map;
        int a[26], n[l], f[l];

        for (int i = 0; i < l; i++)
        {
            map.insert(make_pair(s[i], i + 1));
            a[s[i] - 'a']++;
        }

        int o = 0, e = 0;
        for (int i = 0; i < 26; i++)
        {
            if (a[i] != 0)
            {
                if (a[i] % 2 == 0)
                    e++;
                else
                    o++;
            }
        }
        if (o <= 1)
        {
            char ch[l];
            int m = l / 2, st = 0, en = l - 1;
            for (int i = 0; i < 26; i++)
            {
                while (a[i] != 0)
                {
                    if (a[i] % 2 == 0)
                    {
                        ch[st] = i + 'a';
                        ch[en] = i + 'a';
                        st++;
                        en--;
                        a[i] = a[i] - 2;
                    }
                    else
                    {
                        ch[m] = i + 'a';
                        a[i] = a[i] - 1;
                    }
                }
            }

            multimap<char, int>::iterator itr;
            for (int i = 0; i < l; i++)
            {
                itr = map.find(ch[i]);
                cout << itr->second << " ";
                map.erase(itr);
            }
            cout << endl; 
        }
        else
            cout << "-1" << endl;
    }

    return 0;
}
