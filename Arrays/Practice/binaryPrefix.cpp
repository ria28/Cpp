#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include<math.h>
#define ll long long
using namespace std;
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)
#define vi vector<int>
#define vii vector<vector<int>>

int binaryToDecimal(string no, int digits)
{
    cout << no << " ";
    int number = 0;
    int exp = 0;
    while (digits >= 0)
    {
        char ele = no[digits - 1];
        // cout<<((int)ele-48)<<"... ";
        number = number * 10 + (no[digits - 1] -'0') * pow(2, exp);
        // cout<<number<<" ";
        exp++;
        // no = no/10;
        digits--;
    }
    cout<<"\n";
    return number;
}

vector<bool> prefixesDivBy5(vector<int> &A)
{
    string str = "";
    for (int i : A)
        str += to_string(i);
    vector<bool> ans(A.size());
    for (int i = 0; i < str.size(); i++)
    {
        string sub = str.substr(0, i + 1);
        int number = binaryToDecimal(sub, sub.size());
        // cout<<number<<" ";
        if (number % 5 == 0)
            ans[i] = true;
        else
            ans[i] = false;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vi arr = {0, 1, 1, 1, 1, 1};
    vector<bool> a = prefixesDivBy5(arr);
    for (bool b : a)
        cout << (boolalpha)<<b;

    string s = "911";
    cout<<(s[0]-'0')*5;
    return 0;
}