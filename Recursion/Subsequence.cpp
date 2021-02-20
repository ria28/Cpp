#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)

// SUBSEQUENCE

void subse(string str, int n, int idx, string asf)
{
    if (idx == n)
    {
        cout << asf << "\n";
        return;
    }
    subse(str.substr(1), n, idx + 1, asf + str.substr(0,1));
    subse(str.substr(1), n, idx + 1, asf+"_");
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;
    subse(str, str.size(), 0, "");
    return 0;
}