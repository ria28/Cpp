#include <iostream>
#include <unordered_set>
#include <stack>
using namespace std;

int minAppends(string str)
{
    stack<char> st;
    for (int i = 0; i < str.size(); i++)
    {
        if (st.size() == 0)
        {
            st.push(str[i]);
        }
        else if (str[i] == ')' && st.top() == '(')
        {
            st.pop();
        }
        else
        {
            st.push(str[i]);
        }
    }
    return st.size();
}

void solve(string str, int min_app, unordered_set<string> &set)
{
    if (min_app == 0)
    {
        if (minAppends(str) == 0 && set.find(str) == set.end())
        {
            cout << str << "\n";
            set.insert(str);
        }
        return;
    }

    for (int i = 0; i < str.size(); i++)
    {
        // removing and trying to see whether that is a right set of bracket --->TLE
        string left = str.substr(0, i);
        string right = str.substr(i + 1);
        solve(left + right, min_app - 1, set);
    }
}

int main()
{
    string str;
    cin >> str;
    int min_app = minAppends(str);
    unordered_set<string> set;
    solve(str, min_app, set);
    return 0;
}