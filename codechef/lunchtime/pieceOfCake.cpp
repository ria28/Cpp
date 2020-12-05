#include <iostream>
#include<vector>
#include <unordered_map>
#define ll long long
using namespace std;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        vector<int> freq(26, 0);
        bool flag = false;
        string str;
        cin >> str;
        for (int i = 0; i < str.size(); i++)
        {
            freq[str[i] - 'a']++;
        }
        
        for (int i = 0; i < str.size(); i++)
        {
            if (str.size() - freq[str[i] - 'a'] == freq[str[i] - 'a'])
            {
                cout << "YES\n";
                flag = true;
                break;
            }
        }
        if(!flag)
            cout<<"NO\n";
    }
}
