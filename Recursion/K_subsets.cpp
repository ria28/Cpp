#include <iostream>
#include <vector>
#include <string>
using namespace std;
void subsets(int i, int ssf, int n, int k, vector<vector<int>> &l) // ssf set so far till k
{
    // cout << i << " " << ssf << "\n";
    if (i > n)
    {
        // cout << "he";
        if (ssf == k)
        {
            cout<<"[ ";
            for (int j = 0; j < l.size(); j++)
            {
                cout << "(";
                for (int k = 0; k < l[j].size(); k++)
                {
                    cout << l[j][k];
                }
                cout << ")";
            }
            cout << " ] \n";
        }
        return;
    }
    for (int j = 0; j < k; j++)
    {
        // cout <<l[j].size();
        // cout<<"he";
        if (l[j].size() == 0)
        {
            // cout<<"he";
            l[j].push_back(i);
            subsets(i + 1, ssf + 1, n, k, l);
            l[j].pop_back();
            break;
        }
        else
        {
            // cout<<"he";
            l[j].push_back(i);
            subsets(i + 1, ssf, n, k, l);
            l[j].pop_back();
        }
    }
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> l(k, vector<int>());
    if (n == k)
    {
        cout << "( ";
        for (int i = 1; i <= n; i++)
        {
            cout << i;
        }
        cout << " )";
    }
    else if (n < k)
        cout << -1;
    else
        subsets(1, 0, n, k, l);
    return 0;
}