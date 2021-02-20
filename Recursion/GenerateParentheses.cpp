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

void generate(int n, vector<string> &res, string asf, int op, int cl)
{
    if (op == n && cl == n)
    {
        res.push_back(asf);
        return;
    }
    if (op < cl)
        return;
    if (op < n)
        generate(n, res, asf + "(", op + 1, cl);
    if (cl < n && cl <= op)
        generate(n, res, asf + ")", op, cl + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> res;
    int n = 1;
    generate(n, res, "", 0, 0);
    for (auto str : res)
    {
        cout << str << "\n";
    }
    return 0;
}