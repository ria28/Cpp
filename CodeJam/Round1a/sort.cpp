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

pair<int, int> func(int a, int b)
{
    int cnt = 0;
    pair<int, int> ans; // no, cnt
    if (b > a)
    {
        ans.first= b;
        ans.second=0;
        return ans;
    }
    string str1 = to_string(a);
    string str2 = to_string(b);
    int dif = str1.size() - str2.size();
    double zz =b;
    // zz =  int(str2 + "0"*dif)
    // cout<<pow(10, dif)*b<<" ";
    double ele =pow(10,dif)*b;
    zz = ele;
    // cout<<zz<<" ";
    cnt += dif;
    if (zz > a)
    {
        ans.first = zz;
        ans.second = cnt;
    }

    int extra = a - zz;
    double el = pow(10, dif);
    if (extra >= (el - 1))
    {
        zz *= 10;
        cnt++;
    }
    else
    {
        zz += extra + 1;
    }
    ans.first = zz;
    ans.second = cnt;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        int n;
        cin >> n;
        vi arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int app = 0;
        for (int i = 1; i < n; i++)
        {
            arr[i] = func(arr[i - 1], arr[i]).first;
            app += func(arr[i - 1], arr[i]).second;
        }
        cout << app << "\n";
    }

    return 0;
}