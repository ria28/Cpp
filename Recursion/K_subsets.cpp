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
            cout << "[ ";
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
            // break : why??  To prevent such cases
            // [ (12)(3)(4) ]
            // [ (12)(4)(3) ]
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

void subset_sum(int i, int ssf, int n, int k, vector<vector<int>> &l, vector<int> &SubsetSum) // ssf set so far till k
{
    // cout << i << " " << ssf << "\n";
    if (i > n)
    {
        for (int i = 0; i < k - 1; i++)
        {
            if (SubsetSum[i] != SubsetSum[i + 1])
            {
                return;
            }
        }
        if (ssf == k)
        {
            cout << "[ ";
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
            SubsetSum[j] += i;
            subset_sum(i + 1, ssf + 1, n, k, l, SubsetSum);
            l[j].pop_back();
            SubsetSum[j] -= i;
            break;
        }
        else
        {
            // cout<<"he";
            l[j].push_back(i);
            SubsetSum[j] += i;
            subset_sum(i + 1, ssf, n, k, l, SubsetSum);
            l[j].pop_back();
            SubsetSum[j] -= i;
        }
    }
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> l(k, vector<int>()); // list of ans
    vector<int> sum(k, 0);
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
    {
        subsets(1, 0, n, k, l);
        // subset_sum(1, 0, n, k, l, sum);
    }

    return 0;
}

//    EXAMPLES OF K SUBSET==============================================
// 5 2
// [ (1234)(5) ]
// [ (1235)(4) ]
// [ (123)(45) ]
// [ (1245)(3) ]
// [ (124)(35) ]
// [ (125)(34) ]
// [ (12)(345) ]
// [ (1345)(2) ]
// [ (134)(25) ]
// [ (135)(24) ]
// [ (13)(245) ]
// [ (145)(23) ]
// [ (14)(235) ]
// [ (15)(234) ]
// [ (1)(2345) ]
// 5 3
// [ (123)(4)(5) ]
// [ (124)(3)(5) ]
// [ (12)(34)(5) ]
// [ (125)(3)(4) ]
// [ (12)(35)(4) ]
// [ (12)(3)(45) ]
// [ (134)(2)(5) ]
// [ (13)(24)(5) ]
// [ (135)(2)(4) ]
// [ (13)(25)(4) ]
// [ (13)(2)(45) ]
// [ (14)(23)(5) ]
// [ (1)(234)(5) ]
// [ (15)(23)(4) ]
// [ (1)(235)(4) ]
// [ (1)(23)(45) ]
// [ (145)(2)(3) ]
// [ (14)(25)(3) ]
// [ (14)(2)(35) ]
// [ (15)(24)(3) ]
// [ (1)(245)(3) ]
// [ (1)(24)(35) ]
// [ (15)(2)(34) ]
// [ (1)(25)(34) ]
// [ (1)(2)(345) ]

//  K SUBSET SUM EQUAL-----------------------------------------------------------------
// 6 3
// [(16)(25)(34)]

// 5 3
// [(14)(23)(5)]