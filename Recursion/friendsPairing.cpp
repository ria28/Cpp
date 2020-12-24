#include <iostream>
#include <vector>
#include <string>
using namespace std;
void pair_(int n, int idx, vector<bool> &used, string asf)
{
    // n : total friends
    // idx : current person
    // used : bool array to keep track of people who have decided whether to pair or not
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
        pair_(n, idx + 1, used, asf + "(" + to_string(idx) + ")");  // decides to go alone
        for (int i = idx + 1; i <= n; i++) // decides to pair up with mates
        {
            if (used[i] == false)   // the person we r trying to pair with should not have made a decision
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