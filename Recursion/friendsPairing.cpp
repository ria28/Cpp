#include <iostream>
#include <vector>
#include <string>
using namespace std;
void pair_(int n, int idx, vector<bool> &used, string asf)
{
    if (idx > n)
    {
        cout << asf<<"\n";
        return;
    }
    if (used[idx] == true)
    {
        pair_(n, idx + 1, used, asf);
    }
    else
    {
        used[idx] = true;
        pair_(n, idx + 1, used, asf + "(" + to_string(idx) + ")");
        for (int i = idx + 1; i <= n; i++)
        {
            if (used[i] == false)
            {
                used[i] = true;
                pair_(n, idx + 1, used, asf + "(" + to_string(idx) + "," + to_string(i) + ")");
                used[i] = false;
            }
        }
        used[idx] = false;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<bool> used(n + 1, false);
    pair_(n, 1, used, " ");
    return 0;
}