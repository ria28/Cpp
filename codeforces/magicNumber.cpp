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
    ll n;
    cin >> n;
    string str = to_string(n);
    if (str[0] != '1')
    {
        cout << "NO";
    }
    else
    {
        bool flag = false;
        for (int i = 0; i < str.size();)
        {
            // cout<<str[i]<<"\n";
            if (str.substr(i, 3) == "144")
            {
                // cout<<"3 ->"<<str.substr(i, 3)<<" ";
                i = i + 3;
            }
            else if (str.substr(i, 2) == "14")
            {
                // cout<<"2 ->"<<str.substr(i, 2)<<" ";
                i = i + 2;
            }
            else if (str.substr(i, 1) == "1")
            {
                // cout<<"1 ->"<<str.substr(i, 1)<<" ";
                i = i + 1;
            }
            else
            {
                flag = true;
                break;
            }
        }

        if (flag)
            cout << "NO";
        else
            cout << "YES";
    }

    // if (str[0] != '1')
    // {
    //     cout << "NO";
    // }
    // else
    // {
    //     int count_4 = 0;
    //     int count_1 = 1;
    //     bool flag = false;
    //     for (int i = 1; i < str.size(); i++)
    //     {
    //         // cout << count_4 << " " << count_4 << "\n";
    //         if (str[i] != '1' && str[i] != '4')
    //         {
    //             // cout<<i<<" <-";
    //             // cout << "yee"<<str[i]<<" ";
    //             // cout << "NO";
    //             flag = true;
    //             break;
    //         }
    //         else if (str[i] == '4')
    //         {
    //             count_4++;
    //         }
    //         else if (str[i] == '1')
    //         {
    //             count_1++;
    //         }

    //         if (count_4 - count_1 > 0)
    //         {
    //             // cout << "ye";
    //             // cout << "NO";
    //             flag = true;
    //             break;
    //         }
    //     }
    //     if (flag)
    //         cout << "NO";
    //     else
    //         cout << "YES";
    // }
    return 0;
}