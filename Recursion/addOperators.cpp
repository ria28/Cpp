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

void perm(string str, int target, int idx, int res, vector<string> &ans, string asf, string op)
{
    if (idx == str.size() && res == target)
    {
        ans.push_back(asf);
        cout << asf << "\n";
        return;
    }
    else if (idx >= str.size())
    {
        return;
    }
    int curr = str[idx] - '0';
    // cout << asf << " ";
    // int nxt = str[idx + 1] - '0';

    if (res * curr <= target)
    {
        res = res * curr;
        perm(str, target, idx + 1, res, ans, asf + '*' + str[idx], op);
        res = res / curr;
    }
    if ((res + curr) <= target)
    {
        res += curr;
        perm(str, target, idx + 1, res, ans, asf + '+' + str[idx], op);
        res -= curr;
    }
    if (res - curr > 0)
    {
        res -= curr;
        perm(str, target, idx + 1, res, ans, asf + '-' + str[idx], op);
        res += curr;
    }
}

void addOperators(string num, int target)
{
    vector<string> ans;
    string op = "+-*";
    string asf = "";
    asf += num[0];
    perm(num, target, 1, num[0] - '0', ans, asf, op);
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    // https://leetcode.com/problems/expression-add-operators/
    addOperators("232", 8);

    // string str = "123";
    // cout<<str[0]-'0';

    return 0;
}