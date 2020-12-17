#include <iostream>
#include <unordered_map>

using namespace std;

string reverse(string str)
{
    string rev = "";
    for (int i = str.size(); i >= 0; i--)
    {
        rev += str[i];
    }
    return rev;
}

void palindrome(unordered_map<char, int> map, string odd_char, int n, string asf)
{
    if (asf.size() == map.size())
    {
        string rev = reverse(asf);
        if (odd_char != "")
        {
            asf += odd_char;
        }
        asf += rev;
        cout << asf << "\n";
        asf = "";
        return;
    }
    for (auto i : map)
    {
        if (i.second > 0)
        {
            map[i.first] = i.second - 1;
            palindrome(map, odd_char, n, asf + i.first);
            map[i.first] = i.second + 1;
        }
    }
}

int main()
{
    string str;
    cin >> str;
    unordered_map<char, int> map;
    // string basic = "";
    for (int i = 0; i < str.size(); i++)
    {
        if (map.find(str[i]) == map.end())
        {
            map[str[i]] = 1;
        }
        else
        {
            map[str[i]]++;
        }
    }
    string odd;
    int odd_ = 0; // cnt how many odds are there shouldn't be more than 1
    for (auto i : map)
    {
        if (odd_ > 1)
        {
            cout << "no palindrome will exists more that one odd no of occurence of a  char";
            break;
        }
        if (i.second & 1) //odd
        {
            odd = i.first;
            odd_++;
        }
        map[i.first] = i.second / 2;
    }

    // for (auto i : map)
    // {
    //     cout << i.first << "->" << i.second << "\n";
    // }
    // cout << odd;

    palindrome(map, odd, str.size(), "");

    return 0;
}

// ababababc ---> a4b4c1  ----> a2b2c0 ----> a a b b ---> 4!/(2! * 2!) = 6